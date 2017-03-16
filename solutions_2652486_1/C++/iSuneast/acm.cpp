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
#include <ctime>
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

#define MAXN 100
#define MOD 

int n, m, k;
int v[MAXN][MAXN];
bool ok;
int ls[MAXN];

void dfs(int dep, int maxv) {
	if(ok) {
		return ;
	}
	if(dep == n) {
		for(int i=0; i<k; ++i) {
			if(v[dep][i] != 1) {
				return ;
			}
		}
		ok = true;
		for(int i=n-1; i>=0; --i) {
			printf("%1d", ls[i]);
		}
		putchar(10);
	} else {
		bool yes = false;
		for(int j=maxv; j>=2; --j) {
			bool done = false;
			for(int i=0; i<k; ++i) {
				if(v[dep][i] % j == 0) {
					v[dep+1][i] = v[dep][i]/j;
					done = true;
				} else {
					v[dep+1][i] = v[dep][i];
				}
			}
			if(done) {
				if(rand()%1000>10) {
					yes = true;
					ls[dep] = j;
					dfs(dep+1, j);
				}
			}
		}
		if(!yes) {
			ls[dep] = 2;
			dfs(dep+1, 2);
		}
	}
}

void solve() {
	ok = false;
	dfs(0, m);
	if(!ok) {
		for(int i=0; i<n; ++i) {
			printf("2");
		}
		putchar(10);
	}
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-small-2-attempt1.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-small-2-attempt1.out", "w", stdout);
#endif

	srand((unsigned)time(NULL));
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		int r;
		scanf("%d %d %d %d", &r, &n, &m, &k);
		printf("Case #%d:\n", cas);
		for(int i=0; i<r; ++i) {
			for(int j=0; j<k; ++j) {
				scanf("%d", &v[0][j]);
			}
			solve();
		}
	}

	return 0;
}
