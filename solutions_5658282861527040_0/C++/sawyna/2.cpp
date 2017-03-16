#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#define PB push_back
#define MP make_pair
#define LL long long int
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
using namespace std;
int main()
{
	int T,i,j,n,a,b,k,ans;
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);	
	sc(T);
	for(int t=1;t<=T;t++)
	{
		sc(a);
		sc(b);
		sc(k);
		ans = 0;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				if((i & j) < k)
				ans++;
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	
	return 0;
}

