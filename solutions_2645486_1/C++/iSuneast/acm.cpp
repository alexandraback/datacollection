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

LL e, r, n;
LL v[MAXN];

LL solve() {
	LL ret = 0;
	LL remain = e;
	for(int i=1, next; i<=n; ++i) {
		for(next = i+1; next<=n; ++next) {
			if(v[next] > v[i]) {
				break;
			}
		}
		if(next > n) {
			ret += remain*v[i];
			remain = r;
		} else {
			LL k = next-i;
			LL used = 0;
			if(remain + k*r > e) {
				used = min(remain + k*r - e, remain);
			}
			ret += used * v[i];
			remain = remain - used + r;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-large.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-large.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%lld %lld %lld", &e, &r, &n);
		for(int i=1; i<=n; ++i) {
			scanf("%lld", &v[i]);
		}
		printf("Case #%d: %lld\n", cas, solve());
	}

	return 0;
}
