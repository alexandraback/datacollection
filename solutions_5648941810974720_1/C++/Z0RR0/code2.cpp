#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x,y) cout << x << " " << y << "\n"
#define Max 100005
#define INF INT_MAX
#define mod 1000000007
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define PI 3.14159265358979323846

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;

using namespace std;

LL bigmod(LL b,int p)
{
    if(p == 0)return 1;
    LL my = bigmod(b,p/2);
    my*=my;
    my%=mod;
    if(p & 1)my*=b,my%=mod;
    return my;
}
int setb(int n,int pos)
{
    return n=n | (1 << pos);
}
int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}
bool checkb(int n,int pos)
{
    return (bool)(n & (1 << pos));
}

int dick[] = {0,2,4,6,5,7,1,8,9,3};
char fuck[] = {'Z','W','U','X','F','V','O','G','I','T'};
int cnt[200];
int lol[100];
char str[200000];
char oh[10][10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

int main()
{
	//FI;
	freopen("A-large.in","r",stdin);
	freopen("outALarge.txt","w",stdout);
	int t,T,i,j;
	si(T);
	rep(t,T)
	{
		ss(str);
		int len = strlen(str);
		mem(cnt,0);
		mem(lol,0);
		Rep(i,len)cnt[ str[i] ]++;
		Rep(i,10)
		{
			int x = dick[i];
			char c = fuck[i];
			int my = cnt[ c ];
			lol[x] = my;
			//printf("%s %d\n",oh[x],my);
			int l = strlen(oh[x]);
			Rep(j,l)
			{
				cnt[ oh[x][j] ] -= my;
			}
		}
		printf("Case #%d: ",t);
		Rep(i,10)
		{
			for(j=1;j<=lol[i];j++)printf("%d",i);
		}
		NL;
	}
	return 0;
}
