#pragma comment(linker, "/STACK:65777216")
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <memory.h>
#include <iterator>
#define y1 trololoy1
#define y0 trololoy0
#define mem(A,X) memset(A,X,sizeof(A))
#define memo(A) memset(A,0,sizeof(A))
#define forn(I,B) for (int I=1;I<=(B);I++)
#define forg(H,V) for (int H=first[V];h;h=next[H])
#define rep(I,B) for (int I=0;I<(B);I++) 
#define labs(X) (((X)>0)?(X):(-(X)))
#define ropen(X) freopen(X,"r",stdin)
#define wopen(X) freopen(X,"w",stdout)
#define rwopen(X) freopen(X".in","r",stdin);freopen(X".out","w",stdout)
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define sqr(X) ((X)*(X))

using namespace std;

typedef pair <int,int> pii;
typedef double ld;
typedef long long ll;
typedef pair <ll,ll> pll;
typedef vector<int> vi;
const int N=111;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

ll a[N],b[N],f[N][N],ans;
int A[N],B[N],n,m;

inline void input(){
	memo(f);memo(A);memo(B);memo(a);memo(b);
	ans=0;
	scanf("%d%d",&n,&m);
	forn(i,n) scanf("%I64d%d",&a[i],&A[i]);
	forn(i,m) scanf("%I64d%d",&b[i],&B[i]);
	forn(i,n-1){
		if (A[i]==A[i+1]){
			a[i+1]+=a[i];
			a[i]=0;
		}
	}
	forn(i,m-1){
		if (B[i]==B[i+1]){
			b[i+1]+=b[i];
			b[i]=0;
		}
	}
}

inline ll get(int type,int l,int r){
	ll sum=0;
	for (int i=l;i<=r;++i) if (B[i]==type) sum+=b[i];
	return sum;
}

inline void solve(int T){
	forn(i,n) ans=max(ans,min(get(A[i],1,m),a[i]));
	if (n==2){
		rep(pos,m+1) ans=max(ans,min(get(A[1],1,pos),a[1])+min(get(A[2],pos+1,m),a[2]));
	}
	if (n==3){
		rep(pos,m+1){
			ans=max(ans,min(get(A[1],1,pos),a[1])+min(get(A[2],pos+1,m),a[2]));
			ans=max(ans,min(get(A[1],1,pos),a[1])+min(get(A[3],pos+1,m),a[3]));
			ans=max(ans,min(get(A[2],1,pos),a[3])+min(get(A[3],pos+1,m),a[3]));
			if (A[1]==A[3]) ans=max(ans,min(a[1]+a[3],get(A[1],1,m)));
			if (A[2]==A[3]) ans=max(ans,min(a[2]+a[3],get(A[2],1,m)));
			if (A[1]==A[2]) ans=max(ans,min(a[1]+a[2],get(A[1],1,m)));    
		}
		for (int pos1=0;pos1<=m;++pos1)
			for (int pos2=pos1+1;pos2<=m;++pos2) ans=max(ans,min(get(A[1],1,pos1),a[1])+min(get(A[2],pos1+1,pos2),a[2])+min(get(A[3],pos2+1,m),a[3]));
	}
	printf("Case #%d: %I64d\n",T,ans);
}

int main(){
	rwopen("c");
	int T;
	scanf("%d",&T);
	forn(i,T){
		cerr<<i<<endl;
		input();
		solve(i);
	}
	return 0;
}
