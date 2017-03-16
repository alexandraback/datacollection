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

#define MAXN 
#define MOD 

LL r, t;

bool ok(LL v) {
	double ret = 2*r*(double)v;
	ret += 2*((double)v)*(v-1);
	ret += v;
	return ret <= t;
}

LL solve() {
	LL bgn=0, end=1e18;
	while(bgn <= end) {
		LL mid = (bgn+end)>>1;
		if(ok(mid)) {
			bgn = mid+1;
		} else {
			end = mid-1;
		}
	}
	return end;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\A-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\A-small-attempt0.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%lld %lld", &r, &t);
		printf("Case #%d: %lld\n", cas, solve());
	}

	return 0;
}
