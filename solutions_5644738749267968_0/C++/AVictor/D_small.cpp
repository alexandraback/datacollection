#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
using namespace std;

double C, F, X;


double A[1000], B[1000];

int main()
{
	int test_cnt;
	cin>>test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		int N;
		cin>>N;
		for(int i=0;i<N;i++) scanf("%lf", &A[i]); sort(A, A+N);
		for(int i=0;i<N;i++) scanf("%lf", &B[i]); sort(B, B+N);
		
		int ans1 = 0;
		{
			int j = 0;
			for(int i=0;i<N;i++)
			{
				if (A[i] > B[j])
				{
					ans1++;
					j++;
				}
			}
		}
/*
		{
			int j = N-1, i1 = N-1, i2 = 0;
			while (i2<=i1)
			{
				if (A[i1] > B[j])
				{
					ans1++;
					i1--;
				}
				else
				{
					i2++;
					j--;
				}
			}
		}		
*/		
		int ans2 = 0;
		{
			int j = N-1;
			for(int i=N-1;i>=0;i--)
			{
				if (B[j] > A[i]) j--;
				else ans2++;
			}
		}
		printf("Case #%d: %d %d\n", test_num, ans1, ans2);
	}
	
	return 0;
}
