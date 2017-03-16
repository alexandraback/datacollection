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

#define MAXN 103
#define MAXT 1500
#define MOD 

int a, n, var[MAXN];
int dp[MAXN][MAXT];

pii fromto(int st, int end) {
	int key = 0;
	while(st <= end) {
		st += st-1;
		++key;
	}
	return make_pair(key, st+end);
}

int solve() {
	sort(var+1, var+1+n);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = a;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<MAXT; ++j) {
			if(dp[i-1][j] == -1) {
				continue;
			}
			if(dp[i-1][j] != 1) {
				pii tar = fromto(dp[i-1][j], var[i]);
				if(j+tar.first >= MAXT) {
					while(1);
				}
				ChkMax(dp[i][j+tar.first], tar.second);
			}
			ChkMax(dp[i][j+1], dp[i-1][j]);
		}
	}

	for(int j=0; j<MAXT; ++j) {
		if(dp[n][j] != -1) {
			return j;
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\A-small-attempt3.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\A.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d", &a, &n);
		for(int i=1; i<=n; ++i) {
			scanf("%d", &var[i]);
		}
		printf("Case #%d: %d\n", cas, solve());
	}

	return 0;
}
