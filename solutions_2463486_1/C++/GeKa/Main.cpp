#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <memory.h>

using namespace std;


#define MAX 110

int res[MAX], r1[MAX];
int mas[MAX];
int N;
int A[MAX], B[MAX];
int cnt;
int AL, BL;
bool ls;

void f(int pos)
{
	if (pos == N / 2  + N % 2)
	{
		bool p = true;
		int rl = 2 * N - 1;
		if (rl < AL)
			return;
		if (rl == AL)
		{
			for (int i = AL; i >= 0; i--)
			{
				if (A[i] < res[i])
					break;
				if (A[i] > res[i])
				{
					p = false;
					break;
				}
			}
		}
		if (!p)return;
		if (rl > BL)
			return;
		if (rl == BL)
		{
			for (int i = MAX - 1; i >= 0; i--)
			{
				if (B[i] > res[i])
					break;
				if (B[i] < res[i])
				{
					p = false;
					break;
				}
				if (i == 0 && ls)
					p = false;
			}
		}
		if (p)
			cnt++;
	}
	else
	{
		int start = (pos == 0) ? 1 : 0;
		int end = (pos == N - pos) ? 10 : 4;
		for (int i = start; i < end; i++)
		{
			mas[pos] = i;
			mas[N - pos - 1] = i;
			bool p = true;

			for (int j= 0; j < N; j++)
				if (j <= pos || j >= N - 1 - pos)
					for (int k = 0; k < N; k++)
						if ( (k <= pos || k >= N - 1 - pos) && (j == pos || j == N - 1 - pos || k == pos || k == N - 1 - pos) )
						{
							res[j+k] += mas[j] * mas[k];
							if (res[j+k] >= 10)
							{
								p = false;
							}
						}
			
			if (p)
				f(pos+1);

			for (int j= 0; j < N; j++)
				if (j <= pos || j >= N - 1 - pos)
					for (int k = 0; k < N; k++)
						if ( (k <= pos || k >= N - 1 - pos) && (j == pos || j == N - 1 - pos || k == pos || k == N - 1 - pos) )
						{
							res[j+k] -= mas[j] * mas[k];
							
						}
		}
	}
}

int pre[MAX];

int calc()
{
	for (int j = 0; j < MAX; j++)
	{
		res[j] = 0;
		A[j] = 0;
		B[j] = 0;
	}
	AL = 1;
	for (int i = 0; i < AL; i++)
		A[AL - 1 - i] = 0;
	char s[200];
	scanf("%s", s);
	BL = strlen(s);
	for (int i = 0; i < BL; i++)
		B[BL - 1 - i] = s[i] - '0';

	if (BL % 2 == 0)
		return pre[BL / 2];

	cnt = 0;
	N = (BL + 1) / 2;
	f(0);
	return pre[BL / 2] + cnt;
}

int main()
{
	AL = 1;
	for (int i = 0; i < AL; i++)
		A[AL - 1 - i] = 0;

	BL = 100;
	for (int i = 0; i < BL; i++)
		B[BL - 1 - i] = 9;

	cnt = 0;
	pre[0] = 0;
	for (int i = 1; i <= 50; i++)
	{
		N = i;
		f(0);
		pre[i] = cnt;
	}


	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		ls = true;
		int a = calc();
		ls = false;
		int b = calc();
		printf("Case #%d: %d\n", t+1, b-a);
	}
	
	return 0;
}