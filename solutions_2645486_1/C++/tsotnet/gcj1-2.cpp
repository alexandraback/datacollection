#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#define INF 1000000007
#define EPS 0.000000001
using namespace std;

int T,t,i,j,p,E,R,n,l,r;
pair<int,int> a[11111];
int b[11111];
long long ans;

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d",&E,&R,&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].first);
			a[i].second = i;
		}
		sort(a,a+n);
		reverse(a,a+n);
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			l = 0; r = 10000000;
			while(l<r)
			{
				b[a[i].second] = (l+r+1)/2;
				bool ll = true;
				p = E;
				for(j=0;j<n;j++)
				{
					p -= b[j];
					if(p<0)
					{
						ll = false;
						break;
					}
					p = min(p+R,E);
				}
				if(ll)
					l = (l+r+1)/2; else
					r = (l+r+1)/2-1;
			}
			b[a[i].second] = l;
		}
		ans = 0;
		for(i=0;i<n;i++)
			ans += (long long)b[a[i].second]*a[i].first;
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}