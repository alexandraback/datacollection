#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (1000000+10)
#define MAXn (1000000)
typedef long long ll;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
ll f[MAXN]={0};
int b[MAXN];
ll change(int *b,ll p)
{
	MEM(b) b[0]=1;
	int i=1;
	while(p)
	{
		b[i]=p%10;
		b[0]=i;
		p/=10;
		i++;
	}
}
ll change2(int *b)
{
	ll ans=0;
	For(i,b[0])
	{
		ans=ans*10+b[i];
	}
	return ans;
}
ll rev(ll a)
{
	change(b,a);
	return change2(b);
}

ll q[10000000];
bool vis[MAXN]={0};
void bfs()
{
	int head=1,tail=1;q[1]=1;f[1]=1; vis[1]=1;
	while(head<=tail)
	{
		ll now=q[head];
		
		int p=now+1; 
		if (1<=p&&p<=MAXn&&(!vis[p]||(vis[p]&&f[p]>f[now]+1))) q[++tail]=p,f[p]=f[now]+1,vis[p]=1;
		p=rev(now);
		if (1<=p&&p<=MAXn&&(!vis[p]||(vis[p]&&f[p]>f[now]+1))) q[++tail]=p,f[p]=f[now]+1,vis[p]=1;
		
		head++;
	}
} 

int main()
{
//	freopen("A-small-attempt0.in","r",stdin);
//	freopen("A-small-attempt0.out","w",stdout);
	bfs();
	int T;
	cin>>T;
	For(kcase,T)
	{
		ll n;
		cin>>n;
		ll ans=f[n];
		printf("Case #%d: %lld\n",kcase,ans);
	}
	
	return 0;
}

