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
const int N=555555;
const int INF=111111111;
const double eps=1e-9;
const double pi=3.14159265358979;

int ef[N],es[N],next[N],first[N],c,n,step[N];
bool b[N];

void dfs(int v){
	b[v]=1;
	forg(h,v) if (!b[es[h]] && (h&1)) dfs(es[h]);
}

inline void add(int x,int y){
	next[++c]=first[x];first[x]=c;
	ef[c]=x;es[c]=y;
}

inline void input(){
	memo(ef);memo(es);memo(first);memo(next);memo(step);
	c=n=0;
	scanf("%d",&n);
	forn(i,n){
		int kol;
		scanf("%d",&kol);
		forn(j,kol){
			int x;
			scanf("%d",&x);
			add(i,x);
			add(x,i);
			++step[x];
		}
	}
}

inline void solve(int T){
	printf("Case #%d: ",T);
	forn(i,n){
		if (step[i]) continue;
		memo(b);
		dfs(i);
		forn(j,n) if (b[j]){
			int k=0;
			forg(h,j) if (!(h&1) && b[es[h]]) ++k;
			if (k>1){
				puts("Yes");
				return;
			}
		}
	}
	puts("No");
}

int main(){
	rwopen("a");
	int T;
	scanf("%d",&T);
	forn(i,T){
		cerr<<i<<endl;
		input();
		solve(i);
	}
	return 0;
}
