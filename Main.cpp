#include <iostream>
#include <math.h>
using namespace std;

void print(int *a,int len);//打印
void bubble(int *a,int len);//冒泡排序
void QuickSort(int *a, int left, int right);//快速排序

int main()
{
	int arr[10] = {};
	for (int a = 0; a < 10; a++)
		arr[a] = rand()%100;
	print(arr,10);

	bubble(arr, 10);
	
	QuickSort(arr, 0, 9);
	
	system("pause");
	return 0;
}

void print(int *a,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] <<endl;
	}
	cout <<"=================" << endl;
}

void bubble(int *a, int len)
{
	int flag = 0;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = len - 1; j>i; j--)
		{
			if (a[j-1] > a[j])
			{
				flag = 1;
				a[j - 1] = a[j - 1] ^ a[j];
				a[j ] = a[j - 1] ^ a[j];
				a[j - 1] = a[j - 1] ^ a[j];
			}
		}
		if (flag == 0)
			break;
	}
	print(a, len);
}

void QuickSort(int *a, int left, int right)
{
	int i, j, base;	
	if (left > right)
		return;

	base = a[left];//基数
	i = left;
	j = right;

	while (i != j)
	{
		while (a[j] >= base&&i < j)
		{
			j--;
		}
		while (a[i] <= base&&i < j)
		{
			i++;
		}

		while (i < j)
		{
			a[i] = a[i] ^ a[j];
			a[j] = a[i] ^ a[j];
			a[i] = a[i] ^ a[j];
		}
	}

	a[left] = a[i];
	a[i] = base;//实现当i=j时，将基数和当前数据进行交换
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
	print(a, 10);
}