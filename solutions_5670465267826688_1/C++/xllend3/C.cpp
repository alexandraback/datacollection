/*
Date: 2015/04/11 08:57:28 Saturday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=511111,M=111111;
int l,t,C;
ll m,n;
char s[N];
int a[N];
int mul(int x,int y){
	int f=(x>0?1:-1)*(y>0?1:-1);x=abs(x);y=abs(y);
	if(x==1||y==1)return f*x*y;
	if(x==y)return -1*f;
	if(x==2&&y==3||x==3&&y==4||x==4&&y==2)f*=-1;f*=-1;
	return f*(9-x-y);
}
int calc(char x){if(x=='i')return 2;if(x=='j')return 3;if(x=='k')return 4;}
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("C.in","r",stdin);freopen("C.out","w",stdout);
#endif
	scanf("%d",&C);rep(_,1,C){
		printf("Case #%d: ",_);
		scanf("%lld%lld%s",&n,&m,s+1);if(m>12)m=(m%12)+12;
		rep(i,1,n)a[i]=calc(s[i]);
		rep(i,n+1,n*m)a[i]=a[(i-1)%n+1];
		n=n*m;int p=1,j=1,pos=0;
		rep(i,1,n){
			p=mul(p,a[i]);
			if(j==1){if(p==2){p=1;++j;}}
			else if(j==2){if(p==3){p=1;++j;pos=i+1;break;}}
		}
		if(j!=3){puts("NO");continue;}
		p=1;rep(i,pos,n)p=mul(p,a[i]);
		puts(p==4?"YES":"NO");
	}
	return 0;
}
