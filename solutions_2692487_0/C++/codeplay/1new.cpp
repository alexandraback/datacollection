
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>
 
using namespace std;
#define VI vector < int >
#define LL long long
#define LLU unsigned long long int
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SLLU ({LLU x;scanf("%llu",&x);x;})
#define INF 1000000007

int main()
{
	int t = SI;
	int i, ct;
	long long int start, n;
	long long int a[1000010];
	long long int sum[1000], sum2[1000];
	int moves[1000], moves2[1000];
	long long int temp, temp2;
	for(ct=1; ct<=t; ct++)
	{
		start = SLL;
		n = SLL;
		for(i=0; i<n; i++)
		{
			a[i] = SLL;
		}
		sort(a, a+n);
		temp = start;
		
		for(i=0; i<n; i++)
		{
			if(i==0)
			{
				if(a[i] < temp)
				{
					moves[i] = 0;
					sum[i] = a[i] + temp;
				}
				else
				{
					if(temp == 1)
					{
						moves[i] = 1;
						sum[i] = start;
					}
					else
					{
						moves[i] = 0;
						while(temp <= a[i])
						{
							temp += (temp-1);
							moves[i]++;
						}
						sum[i] = temp + a[i];
					}
				}
				moves2[i] = 1;
				sum2[i] = start; 
			}
			else
			{
				//printf("%d\n", i);
				if(a[i] < sum[i-1])
				{
					moves[i] = moves[i-1];
					sum[i] = sum[i-1] + a[i];
				}
				else
				{
					temp2 = moves[i-1];
					temp = sum[i-1];
					if(temp == 1)
					{
						moves[i] = moves2[i-1] + 1;
						sum[i] = sum[i-1];
					}
					else
					{
						while(temp <= a[i])
						{
							temp += (temp-1);
							temp2++;
						}
						moves[i] = temp2;
						sum[i] = temp + a[i];
					}
				}
				temp = moves[i-1];
				temp2 = moves2[i-1];
				if(temp == temp2)
				{
					moves2[i] = temp +1;
					sum2[i] = max(sum2[i-1], sum[i-1]);
				}
				if(temp < temp2)
				{
					moves2[i] = temp + 1;
					sum2[i] = sum[i-1];
				}
				else
				{
					moves2[i] = temp2 + 1;
					sum2[i] = sum2[i-1];
				}
			}
		}

		printf("Case #%d: %d\n",ct, min(moves[n-1], moves2[n-1]) );	
	}
	return 0;
}
