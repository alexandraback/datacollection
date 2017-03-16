#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 55
int n,a[N],b[N];bool u[N];double pt[N*N];int le[N*N],ri[N*N],p[N*N],L,S;bool F;
bool cmp(int x,int y){return pt[x]<pt[y];}
const double eps=1e-10;
double w[N];
double intS(double x0,double y0,double x1,double y1)
{
	return max(min(y0,y1)-max(x0,x1),0.0);
}
bool chk(int t,int x,int y=-1)
{
	double nt=pt[t];
	for(int i=0;i<n;i++)w[i]=a[i]+b[i]*nt;
	for(int i=0;i<n;i++)
		if(u[i]!=u[x]&&i!=y)
			if(fabs(w[i]+5-w[x])<eps&&b[i]>b[x]||fabs(w[x]+5-w[i])<eps&&b[x]>b[i]||intS(w[i],w[i]+5,w[x],w[x]+5)>eps)return 0;
	return 1;
}
void ff(int x)
{
	if(x==L)F=1;if(F)return;
	S=max(S,x);int y=p[x];
	if(u[le[y]]==u[ri[y]])
	{
		if(chk(y,le[y]))
			u[le[y]]^=1,ff(x+1),u[le[y]]^=1;
		if(chk(y,ri[y]))
			u[ri[y]]^=1,ff(x+1),u[ri[y]]^=1;
	}else
	{
		ff(x+1);
		//if(chk(y,le[y])&&chk(y,ri[y]))
		if(chk(y,le[y],ri[y])&&chk(y,ri[y],le[y]))
			swap(u[le[y]],u[ri[y]]),
			ff(x+1),
			swap(u[le[y]],u[ri[y]]);
	}
}
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			char s[10];scanf("%s",s);
			u[i]=s[0]=='R',scanf("%d%d",b+i,a+i);
		}
		L=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(b[i]>b[j])
				{
					if(a[i]<a[j]-5.0+eps)
						le[L]=i,ri[L]=j,pt[L]=(a[j]-a[i]-5.0)/(b[i]-b[j]),L++;
					if(a[i]<a[j]+5.0+eps)
						le[L]=i,ri[L]=j,pt[L]=(a[j]+5.0-a[i])/(b[i]-b[j]),L++;
				}
		for(int i=0;i<L;i++)p[i]=i;
		sort(p,p+L,cmp),F=0,S=0,ff(0);
		if(F)printf("Case #%d: Possible\n",__);
		else printf("Case #%d: %.9lf\n",__,pt[p[S]]);
	}
	return 0;
}
