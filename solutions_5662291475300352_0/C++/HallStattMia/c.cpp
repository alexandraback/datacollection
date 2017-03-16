#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int n,m;
const int maxn=1000010;
const int eps=1e-12;
double d[maxn],v[maxn];
int nd,nh,nv;
long long ans,pans;
void task()
{
	scanf("%d",&n);
	m=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&nd,&nh,&nv);
		for(int j=1;j<=nh;j++)
		d[++m]=nd,v[m]=1.0/(nv+j-1);
	}
		pans=1000000000000000LL;
	for(int i=1;i<=m;i++)
	{
		double nowv=360.0/(360-d[i])*v[i]+eps;
		double t=360.0/nowv;
		ans=0;
		for(int j=1;j<=m;j++)
		{
			if(v[j]<nowv)
			{
				if(((360-d[j])/v[j])>(360/nowv))ans++;
			}
			else
			{
				double tj=(360-d[j])/(v[j]-nowv);
				if(tj<t){t-=tj;ans++;}	
				tj=360/(v[j]-nowv);
				ans+=(int)(t/tj);
			}
		}
	    pans=min(ans,pans);
	}
	printf("%lld\n",pans);
}
			
		
int main()
{

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		task();
	}
	//for(int i=1;i<=20;i++)cout<<f[i]<<endl;
}
