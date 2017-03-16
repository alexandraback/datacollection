
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
typedef struct info
{
	int d, w, e, s;

}info;
typedef struct start
{
	int d, ni, wi, ei, si, dd, dp, ds;
}start;
bool myfunction (info i,info j) 
{ 
	return i.d < j.d;

}
int main()
{
	int t = SI, n, i, j, k;
	info attack[1000];
	start initial[1000];
	int height[1000];
	int base = 500;
	int left,right, l, count, abc;
	for(abc = 1; abc <=t; abc++)
	{
		n = SI;
		k = 0;
		for(i=0; i<n;i++)
		{
			initial[i].d = SI;
			initial[i].ni = SI;
			initial[i].wi = SI;
			initial[i].ei = SI;
			initial[i].si = SI;
			initial[i].dd = SI;
			initial[i].dp = SI;
			initial[i].ds = SI;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<initial[i].ni; j++)
			{	
				attack[k].d = initial[i].d + initial[i].dd * j; 
				attack[k].w = base + initial[i].wi + initial[i].dp * j; 
				attack[k].e = base + initial[i].ei + initial[i].dp * j; 
				attack[k++].s = initial[i].si + initial[i].ds * j; 
			}	
		}
		sort(attack, attack + k, myfunction);
		for(i=0; i<1000; i++)
			height[i] = 0;
		count = 0;
		for(i=0; i<k; i++)
		{
			//printf("%d %d %d %d\n", attack[i].d,attack[i].w,attack[i].e,attack[i].s );
			
			j = i;

			while(attack[i].d == attack[j].d)
			{
				left = attack[j].w;
				right = attack[j].e;
				for(l=left; l<right; l++)
				{
					if(height[l] < attack[j].s)
					{
						break;
					}
				}
				if(l!=right)
					count++;
				j++;
			}
			j = i;
			while(attack[i].d == attack[j].d)
			{
				left = attack[j].w;
				right = attack[j].e;
				for(l=left; l<right; l++)
				{
					
					height[l] = max(height[l], attack[j].s );
				}
				j++;
			}
			i = j-1;
		}
		printf("Case #%d: %d\n",abc,  count);


	}
	return 0;
}
