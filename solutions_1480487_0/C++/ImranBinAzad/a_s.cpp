#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define ii long long int
#define pi 2*acos(0.0)
#define eps 1e-7
#define mem(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,t;
	scanf("%d",&t);
	
	for (x=1; x<=t; ++x)
	{
		int n,a[250],i,sum= 0;
		cin >> n;
		
		for (i=1; i<=n; ++i) cin >> a[i],sum+= a[i];
		printf("Case #%d:",x);
		for (i=1; i<=n; ++i)
		{
			double m= (double)(sum-n*a[i]+100*sum)/(double)(n*sum);
			/*
			int p= m;
			m= m-p;
			m*= (double)100;
			*/
			printf(" %.6lf",m);
		}
		puts("");
	}
	
	return 0;	
}
