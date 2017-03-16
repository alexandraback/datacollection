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

LL n;
char a[30],b[30];

void fun()
{
	LL f = 0,i;
	Rep(i,n)
	{
		if(a[i] == '?' && b[i] == '?')
		{
			if(f == 1)a[i] = '9';
			else a[i] = '0';

			if(f == -1)b[i] = '9';
			else b[i] = '0';
		}
		else
		{
			if(a[i] == '?' && b[i] != '?')
			{
				if(f == 0)
				{
					a[i] = b[i];
				}
				else
				{
					if(f == -1)a[i] = '0';
					else a[i] = '9';
				}
			}
			if(b[i] == '?' && a[i] != '?')
			{
				if(f == 0)
				{
					b[i] = a[i];
				}
				else
				{
					if(f == 1)b[i] = '0';
					else b[i] = '9';
				}
			}
		}

		if(f == 0)
		{
			if(a[i] != b[i])
			{
				if(a[i] > b[i])f = -1;
				else f = 1;
			}
		}
		//printf("f %lld\n",f);
	}
}

bool match(int val,int f)
{
	int i,j,x;
	x = val;
	if(f == 0)
	{
		for(i=n-1;i>=0;i--)
		{
			int c = a[i];
			int my = x % 10;
			x /= 10;
			if(c != '?')
			{
				if(c - '0' != my)return 0;
			}
		}
		if(x)return 0;
	}
	if(f == 1)
	{
		for(i=n-1;i>=0;i--)
		{
			int c = b[i];
			int my = x % 10;
			x /= 10;
			//printf("%c\n",c);
			if(c != '?')
			{
				if(c - '0' != my)return 0;
			}
		}
		if(x)return 0;
	}
	return 1;
}

int cd,jm;
void go()
{
	//if( match(9,0) && match(10,1) )puts("YO");
	int i,j,mn = 100000;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			if( match(i,0) && match(j,1) )
			{
				int d = abs(i-j);
				if(d < mn)
				{
					mn = d;
					cd = i;
					jm = j;
				}
			}
		}
	}
}
char lol1[30],lol2[30];
void gofuck(int x,int f)
{
	LL i;
	if(f == 0)
	{
		for(i=n-1;i>=0;i--)
		{
			lol1[i] = (x % 10) + '0';
			x /= 10;
		}
	}
	if(f == 1)
	{
		for(i=n-1;i>=0;i--)
		{
			lol2[i] = (x % 10) + '0';
			x /= 10;
		}
	}
	lol1[n] = lol2[n] = 0;
}

int main()
{
	//FI;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("outBsmall.txt","w",stdout);
	LL t,T,i;
	sl(T);
	rep(t,T)
	{
		ss(a);
		ss(b);
		n = strlen(a);
		go();
		//fun();
		//printf("Case #%lld: %s %s\n",t,a,b);
		gofuck(cd,0);
		gofuck(jm,1);
		//printf("Dick #%lld: %d %d\n",t,cd,jm);
		printf("Case #%lld: %s %s\n",t,lol1,lol2);
		/*LL x = 0,y = 0;
		Rep(i,n)
		{
			x *= 10;
			x += (a[i] - '0');
			y *= 10;
			y += (b[i] - '0');
		}
		if(x != cd || y != jm)printf("vul !!!!!!!!!!!!!!!!!!!!!!!!\n");*/
		//printf("x %lld y %lld\n",x,y);
	}
	return 0;
}
