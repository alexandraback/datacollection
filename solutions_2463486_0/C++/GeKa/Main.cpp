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

int res[MAX];
int mas[MAX];
int N;
int A[MAX], B[MAX];
int cnt;

void f(int pos)
{
	if (pos == N / 2  + N % 2)
	{
		bool p = true;


		for (int i = MAX - 1; i >= 0; i--)
		{
			if (A[i] < res[i])
				break;
			if (A[i] > res[i])
			{
				p = false;
				break;
			}
		}

		for (int i = MAX - 1; i >= 0; i--)
		{
			if (B[i] > res[i])
				break;
			if (B[i] < res[i])
			{
				p = false;
				break;
			}
		}
		if (p)
			cnt++;
	}
	else
	{
		int start = (pos == 0) ? 1 : 0;
		for (int i = start; i < 10; i++)
		{
			mas[pos] = i;
			mas[N - pos - 1] = i;
			bool p = true;
			for (int j= 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if ( (j <= pos || j >= N - 1 - pos) && (k <= pos || k >= N - 1 - pos) && (j == pos || j == N - 1 - pos || k == pos || k == N - 1 - pos) )
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
				for (int k = 0; k < N; k++)
					if ( (j <= pos || j >= N - 1 - pos) && (k <= pos || k >= N - 1 - pos) && (j == pos || j == N - 1 - pos || k == pos || k == N - 1 - pos) )
					{
						res[j+k] -= mas[j] * mas[k];
					}
			
		}
	}
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		
		for (int j = 0; j < MAX; j++)
		{
			res[j] = 0;
			A[j] = 0;
			B[j] = 0;
		}

		char s[200];
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < l; i++)
			A[l - 1 - i] = s[i] - '0';

		scanf("%s", s);
		l = strlen(s);
		for (int i = 0; i < l; i++)
			B[l - 1 - i] = s[i] - '0';

		cnt = 0;
		for (int i = 1; i <= 25; i++)
		{
			N = i;
			f(0);
		}
		printf("Case #%d: %d\n", t+1, cnt);
	}
	
	return 0;
}