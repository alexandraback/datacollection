#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 105;
int d[20],c[20],cnt[21];
bool u[N],v[2000001];
typedef long long ll;
ll h[20];
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("out.out","w",stdout);
	int T,ca=1,a,b,i,j,k,r,l;
	scanf("%d",&T);
	while(T--)
	{
		r=0;
		scanf("%d%d",&a,&b);
		for(i=a;i<=b;i++)
		{
			int x=i;
			j=0;
			while(x)
			{
				c[j++]=x%10;
				x/=10;
			}
			for(k=0;k<j;k++)d[k]=c[j-1-k];
			ll e=1;
			for(k=0;k<j;k++){d[k+j]=d[k];e*=10;}
			h[0]=d[0];
			//if(i==241)printf("%lld ",h[0]);
			for(k=1;k<j+j;k++)
			{
				h[k]=h[k-1]*10+d[k];
				//if(i==241)printf("%lld ",h[k]);
			}
			//if(i==241)puts("");
			l=0;
			for(k=0;k<j;k++)
			{
				ll t;
				if(!k)t=h[j-1];
				else t=h[j-1+k]-h[k-1]*e;
				if(t<i&&t>=a)
				{

					//printf("t:%lld i:%d \n",t,i);
					if(!u[t]){r++;u[t]=true;cnt[l++]=t;}
				}
			}
			for(k=0;k<l;k++){u[cnt[k]]=false;}
		}
		printf("Case #%d: %d\n",ca++,r);
	}
	return 0;
}
