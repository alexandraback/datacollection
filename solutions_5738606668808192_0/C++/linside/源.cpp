#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("output.out");
#define N 16
#define J 50
long z = 0;
int t[11];
int s[11][N];
void Plus(int a[N],int d=N-2)
{
	if (d == N - 2) a[d]++;
	if (a[d] == 2)
	{
		a[d] = 0;
		a[d - 1]++;
		Plus(a, d - 1);
	}
	else
	{
		return;
	}
}
void multiply(int a[N], int c)
{
	int s = 0;
	int b[N];
	for (int i = 0;i < N;i++)
	{
		b[i] = 0;
	}
	for (int i = 0;i < N;i++)
	{
		if (a[i] != 0)
		{
			s = i;
			break;
		}
	}
	for (int i = N - 1;i >= s;i--)
	{
		int tmp = a[i] * c,x=0;
		do
		{
			b[i-x] += tmp % 10;
			tmp /= 10;
			x++;
		} while (tmp != 0);
	}
	for (int i = 0;i < N;i++)
	{
		a[i] = b[i];
	}
	return;
}
void add(int a[N], int b[N])
{
	for (int i = N - 1;i >= 0;i--)
	{
		a[i] += b[i];
		if (a[i] >= 10)
		{
			if (i == 0) fout << "Խ�磡";
			a[i - 1] += a[i] / 10;
		}
		a[i] %= 10;
	}
	return;
}
void hex(int a[N], int x)
{
	int b[N];
	for (int j = 0;j < N;j++) b[j] = 0;
	for (int i = 0;i < N;i++)
	{
		int m[N];
		for (int j = 0;j < N;j++) m[j] = 0;
		m[N - 1] = a[i];
		for (int j = N - i - 1;j > 0;j--)
		{
			multiply(m, x);
		}
		add(b, m);
	}
	for (int i = 0;i < N;i++)
	{
		a[i] = b[i];
	}
	return;
}
int div(int a[N], int b1)
{
	int s = 0;
	for (int i = 0;i < N;i++)
	{
		if (a[i] != 0)
		{
			s = i;
			break;
		}
	}      
	int i, j, k, flag = 0;
	char b[2000];     
	memset(b, 0, sizeof(b));
	z = 0; for (i = 0;i<N;i++) { z = a[i] + z * 10;  b[i] = z / b1 + '0';  z = z%b1; }

	i = j = 0;
	return z;
}
int prime(int a[N],int x)
{
	hex(a, x);for (int i = 0;i < N;i++) s[x][i] = a[i];
	int flag = 0;
	int top = 0,i=N-1;
	do
	{
		top += s[x][i] * pow(10, (N - i-1));
		i--;
	} while (i != 0 && top<100000);
	for (int i = 2;i < top;i++)
	{
		if (div(a, i) == 0)
		{
			t[x] = i;
			flag = 1;
			break;
		}
	}
	return flag;
}
int main()
{
	fout << "Case #1:" << endl;
	int num = 0;
	int a[N];
	for (int i = 0;i < N;i++)
	{
		a[i] = 0;
	}
	a[0] = 1;
	a[N - 1] = 1;
	do
	{
		int flag = 1;
		int b[N];
		for (int i = 2;i <= 10;i++)
		{
			for (int j = 0;j < N;j++) b[j] = a[j];
			if (!prime(b,i))
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			for (int i = 0;i < N;i++)
			{
				fout << a[i];
			}
			for (int i = 2;i <= 10;i++)
			{
				fout << " "<<t[i];
			}
			fout << endl;
			num++;
		}
		Plus(a);
	} while (num < J);
	system("pause");
	return 0;
}