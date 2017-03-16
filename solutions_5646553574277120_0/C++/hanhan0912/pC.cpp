//bcw0x1bd2 {{{
#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef ONLINE_JUDGE
#define FILEIO(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FILEIO(name)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
	    scanf("%d",&head);
			    RI(tail...);
}

mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(rng);
}
// Let's Fight! }}}

int C,D,V;
int ip[105];
bitset<10000> dp;

void input(){
	scanf("%d%d%d", &C, &D, &V);
	for (int i=0; i<D; i++)
		scanf("%d", &ip[i]);
}

void solve(int t){
	dp = 0;
	dp[0] = 1;
	for (int i=0; i<D; i++){
		for (int j=0; j<C; j++){
			for (int k=V; k>=ip[i]; k--)
				if (dp[k-ip[i]]) dp[k] = 1;
		}
	}
	int lst = -1;
	for (int i=0; lst==-1 && i<=V; i++)
		if (!dp[i]) lst=i;
	int ret = 0;
	while ((int)dp.count()-1 < V){
		for (int i=0; i<C; i++){
			for (int k=V; k>=lst; k--)
				if (dp[k-lst]) dp[k]=1;
		}
		ret++;
		for (int i=lst+1; i<=V; i++){
			if (!dp[i]){
				lst = i;
				break;
			}
		}
	}
	printf("Case #%d: %d\n", t, ret);
}

int main(){
	int nT;
	scanf("%d", &nT);
	for (int t=1; t<=nT; t++){
		input();
		solve(t);
	}
	return 0;
}

