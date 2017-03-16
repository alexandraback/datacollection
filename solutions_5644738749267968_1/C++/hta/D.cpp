#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
const int maxn=1003;
double a[maxn],b[maxn];
int n;
set<double> S;
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int T=get();
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		n=get();
		for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lf",&b[i]);
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		int p1=1,p2=n,ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]>b[p1])ans++,p1++;else p2--;
		printf("%d ",ans);
		p1=1;ans=0;
		for(int i=1;i<=n;i++)
		{
			while(b[p1]<a[i]&&p1<=n)p1++;
			if(p1<=n)p1++;else ans++;
		}
		printf("%d\n",ans);
		//S.clear();
	}
	return 0;
}
