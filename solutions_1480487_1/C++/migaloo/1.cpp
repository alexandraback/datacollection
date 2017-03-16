#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	double k, X, J[1000], ans;
	int i, T, N, j;
	double total_temp, temp_sum;
	double a[1000];
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		X = 0;
		for(j = 0; j < N; j++)
		{
			scanf("%lf", &J[j]);
			X += J[j];
		}
		k = 2*X/N;
		printf("Case #%d:", i);
		total_temp = 0, temp_sum = 0;	
		for(j = 0; j < N; j++)
		{
			ans = 100*(k-J[j])/X;
			if(ans < 0) 
			{
				total_temp++;
				temp_sum += ans;
			}
			a[j] = ans;
		}
		temp_sum = temp_sum/(N - total_temp);
		for(j = 0; j < N; j++)
		{
			if(a[j] < 0) 
			{
				a[j] = 0;
				printf(" %lf", a[j]);
			}
			else printf(" %lf", a[j] + temp_sum);
		}
		printf("\n");
	}
	return 0;
}
