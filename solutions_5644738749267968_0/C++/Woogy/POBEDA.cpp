#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)

double x[1000];
double y[1000];
double x11[1000];
double y11[1000];

int war(int N)
{
	int t = 0, j = 0,G=N-1;

	bool flag=true;
	/*
	while (flag)
	{
		if (G == -1)
		{
			flag = false;
		}
		else
		{
			if (x11[G] > y11[G])
			{
				t = t + 1;
				G--;
			}
			else
				flag = false;
		}
		
	}
	*/
	for (int i = 0; i <= G; i++)
	{
		j = i;
		flag = true;
		while ((x11[i] > y11[j]) && (flag))
		{
			j = j + 1;
			if (j >= N)
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			y11[j] = -1;
			sort(y11, y11 + N);
		}
		else
		{
			t = t + 1;
		}
	}
	return t;
	
}

int Dwar(int N)
{
	int t = 0,i=0, j=N-1, k = 0;
	bool flag = true;
	/*
	
	for (int i = 0; i <N; i++)
	{
		flag = true;
		for (j = i; j<N; j++)
		{
			if (x[i] < y[j])
			{
				flag = false;
				
			}
		}
		if (!flag)
		{
			y[k] = -1;
			sort(y, y + N);
		}
		else
			t = t + 1;
	}
	*/
	
	for (int i = N-1; i >= 0; i--)
	{
		if (x[i] > y[i])
		{
			t = t + 1;
		}
		else
		{
			x[k] = 2;
			sort(x, x + N);
		}
	}
	
	return t;
	
}


int main()
{
	int T;
	int N;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf_s("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf_s("%lf", &x[j]);
		}
		for (int j = 0; j < N; j++)
		{
			scanf_s("%lf", &y[j]);

		}
		sort(x, x + N);
		sort(y, y + N);
		for (int j = 0; j < N; j++)
		{
			x11[j] = x[j];
		}
		for (int j = 0; j < N; j++)
		{
			y11[j] = y[j];

		}
		// Yo
	
	
		printf("Case #%d: %d %d\n", i, Dwar(N), war(N));
		

	}
}
