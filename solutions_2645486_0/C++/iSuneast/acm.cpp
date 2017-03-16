#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class T>inline void ChkMax(T &a,const T &b){if(a < b) a = b;}
template<class T>inline void ChkMin(T &a,const T &b){if(b < a) a = b;}
const int dx[]={ 0, 0,-1, 1,-1, 1,-1, 1};
const int dy[]={-1, 1, 0, 0,-1,-1, 1, 1};
string dir[]={"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

typedef long long LL;
typedef pair<int, int> pii;

#define LOWBIT(v) ((v)&(-(v)))
#define POW2(p) (1<<(p))
#define KTH_BIT(v, k) ((v) & POW2(k))
#define MERGE_BIT(v, k) ((v) | POW2(k))
#define INF 0x3f3f3f3f
#define eps 1e-5

// -------------------------------------------

#define MAXN 10003
#define MOD 
#define SMALL 13

int e, r, n;
int v[MAXN];
int dp[SMALL][SMALL];

LL solve() {
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; ++i) {
		for(int k=0; k<=e; ++k) {
			for(int j=0; j<=k; ++j) {
				ChkMax(dp[i][min(e, k-j+r)], dp[i-1][k]+j*v[i]);
			}
		}
	}
	int ret = 0;
	for(int i=0; i<=e; ++i) {
		ChkMax(ret, dp[n][i]);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-small-attempt1.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-small-attempt1.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d %d", &e, &r, &n);
		for(int i=1; i<=n; ++i) {
			scanf("%d", &v[i]);
		}
		printf("Case #%d: %lld\n", cas, solve());
	}

	return 0;
}
