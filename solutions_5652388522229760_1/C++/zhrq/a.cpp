#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int a[maxn];
typedef long long ll;
void Count(ll n,int &cnt)
{
	while(n)
	{
		int l=n%10;
		if(!a[l]) a[l]=1, cnt++;
		n/=10;
	}
}
int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		ll n;
		scanf("%lld",&n);
		printf("Case #%d: ",cas);
		if(!n)
		{
			puts("INSOMNIA");
			continue;
		}
		memset(a,0,sizeof a);
		int cnt=0, i=0;
		while(cnt<10) Count(n*(++i),cnt);
		printf("%lld\n",n*i);
		if(n*i>1LL<<32 || n*i<0) cout<<n<<endl;
	}
	return 0;
}

