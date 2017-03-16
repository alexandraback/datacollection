#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.begin())y=x.begin();y!=x.end();y++)
#define trvr(y,x) for(typeof(x.rbegin())y=x.rbegin();y!=x.rend();y++)
#define pb(f) push_back(f)
#define pi_ printf("\n")
#define pi(a) printf("%d\n",a)
#define pil(a) printf("%lld\n",a)
#define sc(a) scanf("%d",&a)
#define ll long long
#define scl(a) scanf("%lld",&a)
#define scs(a) scanf("%s",a)
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define inf 1000000009
#define maxn 100009
using namespace std;
//#include<windows.h>
FILE *fin = freopen("2.in","r",stdin);
FILE *fout = freopen("out.txt","w",stdout);
using namespace std;
typedef pair<int,int> pii;
typedef vector<int > vi;
typedef vector< pii > vpii;
char a[29],b[30];
ll n,aa,bb,ans;
void rec(int i,ll A,ll B,int flag)
{
	if(i==n)
	{
		if(abs(A-B)<ans)
		{
			ans=abs(A-B);
			aa=A,bb=B;
		}
		else if(abs(A-B)==ans)
		{
			if(A<aa)
			{
				aa=A,bb=B;
			}
			else if(A=aa&&B<bb)
			bb=B;
		}
		return;
	}
	if(flag==0)
	{
		if(a[i]=='?'&&b[i]=='?')
		{
			rec(i+1,A*10+0,B*10+0,0);
			rec(i+1,A*10+1,B*10+0,-1);
			rec(i+1,A*10+0,B*10+1,1);
		}	
		else if(a[i]=='?')
		{
			rec(i+1,A*10+b[i]-'0',B*10+b[i]-'0',0);
			if(b[i]!='9')
			rec(i+1,A*10+b[i]+1-'0',B*10+b[i]-'0',-1);
			if(b[i]!='0')
			rec(i+1,A*10+b[i]-1-'0',B*10+b[i]-'0',1);
		}
		else if(b[i]=='?')
		{
			rec(i+1,A*10+a[i]-'0',B*10+a[i]-'0',0);
			if(a[i]!='9')
			rec(i+1,A*10+a[i]-'0',B*10+a[i]-'0'+1,1);
			if(a[i]!='0')
			rec(i+1,A*10+a[i]-'0',B*10+a[i]-'0'-1,-1);
		}
		else if(a[i]<b[i])
		{
			rec(i+1,A*10+a[i]-'0',B*10+b[i]-'0'+0,1);
		}
		else if(a[i]>b[i])
		{
			rec(i+1,A*10+a[i]-'0',B*10+b[i]-'0'+0,-1);
		}
		else
		{
			rec(i+1,A*10+a[i]-'0',B*10+b[i]-'0'+0,0);
		}
	}
	else if(flag==-1)
	{
		if(a[i]=='?'&&b[i]=='?')
		{
			rec(i+1,A*10+0,B*10+9,-1);
		}
		else if(a[i]=='?')
		{
			rec(i+1,A*10+0,B*10+b[i]-'0',-1);
		}	
		else if(b[i]=='?')
		{
			rec(i+1,A*10+a[i]-'0',B*10+9,-1);
		}
		else
		{
			rec(i+1,A*10+a[i]-'0',B*10+b[i]-'0',-1);
		}
	}
	else if(flag==1)
	{
		if(a[i]=='?'&&b[i]=='?')
		{
			rec(i+1,A*10+9,B*10+0,1);
		}
		else if(a[i]=='?')
		{
			rec(i+1,A*10+9,B*10+b[i]-'0',1);
		}	
		else if(b[i]=='?')
		{
			rec(i+1,A*10+a[i]-'0',B*10,1);
		}	
		else
		{
			rec(i+1,A*10+a[i]-'0',B*10+b[i]-'0',1);
		}
	}
}
int main()
{
	int t,i,j,k,cas=0;
	sc(t);while(t--)
	{
		cas++;	printf("Case #%d: ",cas);
		scs(a);scs(b);
		n=strlen(a);
		aa=100000000000000000LL,bb=100000000000000000LL,ans=4000000000000000000LL;
		rec(0,0,0,0);
		ll p=aa,q=bb;int cnt=0;
		vector<int > K,L;
		while(aa!=0)
		{
			int x=aa%10;aa/=10;
			K.pb(x);
		}
		while(K.size()<n)
		K.push_back(0);
		while(bb!=0)
		{
			int x=bb%10;bb/=10;
			L.pb(x);
		}while(L.size()<n)
		L.push_back(0);
		reverse(K.begin(),K.end());
		reverse(L.begin(),L.end());
		trv(it,K)
		printf("%d",*it);
		printf(" ");
		trv(it,L)
		printf("%d",*it);
		printf("\n");
		
//		printf("%lld %lld\n",aa,bb);
	}
}
