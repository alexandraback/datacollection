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

#define MAXN 23
#define MOD 

int n, x, y;
map<pii, int> rem[MAXN];
pii v[MAXN];
typedef map<pii, int>::iterator mit;
double all[MAXN];

bool chk(int x, int p) {
	int ly = -1, mid = -1, ry = -1;
	for(int i=0; i<p; ++i) {
		if(v[i].first + 1== x) {
			ChkMax(ly, v[i].second);
		} else if(v[i].first == x) {
			ChkMax(mid, v[i].second);
		} else if(v[i].first -1 == x) {
			ChkMax(ry, v[i].second);
		}
	}
	if(ly == ry) {
		v[p] = make_pair(x, ly + 1);
		return true;
	}
	return false;
}

void goleft(int p) {
	for(int x=-1; ; --x) {
		if(chk(x, p)) {
			return ;
		}
	}
}

void goright(int p) {
	for(int x=1; ; ++x) {
		if(chk(x, p)) {
			return ;
		}
	}
}

void dfs(int dep) {
	if(dep == n) {
		for(int i=0; i<n; ++i) {
			rem[n][ v[i] ]++;
//			cout<<"("<<v[i].first<<","<<v[i].second<<") ";
		}
//		cout<<endl;
		all[n]+=1.0;
	} else if(dep == 0) {
		v[0] = make_pair(0, 0);
		dfs(dep+1);
	} else {
		int ly = -1, ry = -1, mid = -1;
		for(int i=dep-1; i>=0; --i) {
			if(v[i].first == -1) {
				ly = max(ly, v[i].second);
			} else if(v[i].first == 1) {
				ry = max(ry, v[i].second);
			} else if(v[i].first == 0) {
				mid = max(mid, v[i].second);
			}
		}
		if(ly == ry && ly == mid+1) {
			v[dep] = make_pair(0, ly+1);
			dfs(dep+1);
		} else {
			if(ly <= ry) {
				goleft(dep);
				dfs(dep+1);
			}
			if(ly >= ry) {
				goright(dep);
				dfs(dep+1);
			}
		}
	}
}

double solve() {
	if(all[n] == 0) {
		rem[n].clear();
		dfs(0);
	}
	return rem[n][make_pair(x, y)]/all[n];
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-small-attempt1.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d %d", &n, &x, &y);
		printf("Case #%d: %.10lf\n", cas, solve());
	}

	return 0;
}
