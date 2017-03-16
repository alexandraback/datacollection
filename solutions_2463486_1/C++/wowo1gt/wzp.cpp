//#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
using namespace std;
#define ll __int64
#define inf 1000000007
#define esp 0.000001
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}
double max(double x,double y){return x>y?x:y;}
double min(double x,double y){return x<y?x:y;}
int abs(int x) {return x<0?-x:x;}
const int N=100005;
const int M=400005;
ll num[N],w=100000000000000;
int E=0,p[20];
bool judge(ll t)
{
	int i,k=0;
	while(t)
	{
		p[k++]=t%10;
		t/=10;
	}
	for(i=0;i<k/2;i++)
		if(p[i]!=p[k-i-1]) return 0;
	return 1;
}
void pre()
{
	ll i;
	for(i=1;i*i<w;i++)
		if(judge(i)&&judge(i*i)) num[E++]=i*i;
	//printf("%d\n",E);
}
int main()
{
    freopen("C-large-1.in","r",stdin);
    freopen("output.out","w",stdout);
    int i,j,k=1,tt;
	ll n,m;
	pre();
	scanf("%d",&tt);
	while(tt--)
	{
		int ans=0;
		scanf("%I64d%I64d",&n,&m);
		for(i=0;i<E;i++)
			if(n<=num[i]&&num[i]<=m) ans++;
		printf("Case #%d: %d\n",k++,ans);
	}
    return 0;
}