#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int a[40],tot;
void work(long long now){
	while (now) {
		if (!a[now%10]) tot++;
		a[now%10]=1;
		now/=10;
	}
}
int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	int T,num=0;
	scanf("%d",&T);
	while (T--)
	{
		num++;
		memset(a,0,sizeof a);
		tot=0;
		long long x;
		scanf("%lld",&x);
		if (x==0)
		{
			printf("Case #%d: INSOMNIA\n",num);
			continue;
		}
		int ans=1;
		while (tot<10)
		{
			work(ans*x);
			if (tot==10) 
			{
				printf("Case #%d: %lld\n",num,ans*x);
				break;
			}
			ans++;
		}
	}
}
