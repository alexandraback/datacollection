#include<cstdio>
#include<cstring>
#include<cmath>
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

const int N=10010;
int v[N];
long long e,r,n;
//long long dp[N][];

long long cal(int i,long long ne)
{
	if(i==n-1) return ne*v[i];
	long long j,ans,tmp;
	ans=0;
	for(j=MAX(0,r-e+ne);j<=ne;j++)
	{
		tmp = j*v[i];
		tmp += cal(i+1,ne-j+r);
		ans = MAX(ans,tmp);
	}
	return ans;
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int cnt=1;cnt<=T;cnt++)
	{
		scanf("%lld%lld%lld",&e,&r,&n);
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		long long ans = cal(0,e);
		
		printf("Case #%d: %lld\n",cnt,ans);
	}
} 
