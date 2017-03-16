#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long flip(long long a)
{
	long long ret=0;
	while(a)
	{
		int t=a%10;
		ret+=(ret*10 + t);
		a/=10;
	}
	return ret;
}

int nod(long long a)
{
	int ret=0;
	while(a)
	{
		a/=10; ret++;
	}
	return ret;
}
long long ar[17];
long long te[17];
int min(int a,int b)
{
	if(a<b) return a; return b;
}
long long get(long long a)
{
	int d=nod(a);
long long ret=0;
int p=0;
while(a)
{
	int t=a%10;
	//printf("here t =%d\n",t);
	int pp=min(p,d-p-1);
	ret+=(te[pp]*t);
	p++;
	a=a/10;
}
//printf("here return  =%d\n",ret);
	return ret+1;
}
void pre()
{
	te[0]=1;
	for(int i=1;i<17;i++)
	te[i]=10*te[i-1];
	
	long long l=99;
	ar[2]=10;
	ar[1]=1;
	for(int i=3;i<17;i++)
	{
		ar[i]=ar[i-1]+get(l);
		l=l*10+9;
	}
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
	printf("Case #%d: ",tc);
	long long n; scanf("%lld",&n);
	long long ans=0;
	if(n<20)
	{
		printf("%lld\n",n); continue;
	}
	
	pre();
	if(n%10==0) ans=1,n--;
	int d=nod(n);
	ans+=ar[d];
	//printf("here ans = %lld\n",ans);
	long long rr=get(n);
	//printf("here ret = %lld\n",rr);
	ans+=rr;
	int tmp=d - d/2;
	d=d/2;
	long long y=te[tmp];
	long long g=n/y;
	if(g==te[d-1]) ans--;
	printf("%lld\n",ans-1);
	
	
	//for(int i=0;i<17;i++)
	//printf("%lld\n",ar[i]);
}

	}
