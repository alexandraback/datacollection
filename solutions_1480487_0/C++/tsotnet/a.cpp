#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#define INF 1000000007
#define EPS 0.000000001
using namespace std;

int N,T,i,n,sum,s,a[1000];
bool l;

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d",&n);
		for(i=sum=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		N = n;
		l=true;
		s=2*sum;
		while(l)
		{
			l=false;
			for(i=0;i<n;i++)
				if(s < a[i]*N)
				{
					l=true;
					s -= a[i];
					N--;
					a[i] = -1;
				}
		}
		for(i=0;i<n;i++)
			if(a[i] == -1)
				printf("0.000000 "); else
			if(sum == 0)
				printf("%.6lf ",100.0/N); else
				printf("%.6lf ",100*(1.0*s/N-a[i])/sum);
		printf("\n");
	}
	return 0;
}