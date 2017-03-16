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

#define MAXN 13
#define MOD 

int r, n, m, k;
int v[MAXN];
vector<string> all;
int size;

void solve() {
	map<int, int> mii;
	for(int i=0; i<k; ++i) {
		if(v[i] != 1) {
			mii[v[i]] = -1;
		}
	}
	for(int i=0; i<size; ++i) {
		int res = mii.size();
		for(int j=1; j<(1<<n); ++j) {
			int mul = 1;
			for(int k=0; k<n; ++k) {
				if(KTH_BIT(j, k)) {
					mul *= all[i][k]-'0';
				}
			}
			if(mii.find(mul) != mii.end() && mii[mul] != i) {
				mii[mul] = i;
				--res;
			}
		}
		if(!res) {
			cout<<all[i]<<endl;
			return ;
		}
	}
	cout<<all[0]<<endl;
}

void dfs(int dep, string cur) {
	if(dep == n) {
		all.push_back(cur);
	} else for(int i=cur.length()? cur[cur.length()-1]-'0': 2; i<=m; ++i) {
		dfs(dep+1, cur+(char)('0'+i));
	}
}

void init() {
	all.clear();
	dfs(0, "");
	size = all.size();
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-small-1-attempt0.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-small-1-attempt0.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d %d %d", &r, &n, &m, &k);
		printf("Case #%d:\n", cas);
		init();
		for(int i=0; i<r; ++i) {
			for(int j=0; j<k; ++j) {
				scanf("%d", &v[j]);
			}
			solve();
		}
	}

	return 0;
}
