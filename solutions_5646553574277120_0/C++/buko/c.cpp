#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;

int z,q,c,d,v,r, can[40],i;
set<int> zb;

int go(int level) {
	int i;
	for (i=1;i<=v;i++) can[i] = false;
	can[0] = true;
	for (set<int>::iterator it = zb.begin(); it!= zb.end();it++) {
		for (i=v-*it;i>=0;i--) if (can[i]) can[i+*it] = true;
	}
	bool ok = true;
	for (i=1;i<=v;i++) if (!can[i]) ok = false;
	if (ok) return 0;
	if (level >= 3) {
		return INF / 2;
	}
	int res = INF;
	for (i=1;i<=v;i++) if (zb.find(i) == zb.end()) {
		zb.insert(i);
		res = min(res, go(level + 1) + 1);
		zb.erase(i);
	}
	return res;
}

int main() {
scanf("%d",&z);
for (q=1;q<=z;q++) {
	scanf("%d %d %d",&c,&d,&v);
	r = 0;
	zb.clear();
	for (i=0;i<d;i++) {
		scanf("%d",&c);
		zb.insert(c);
	}
	if (zb.find(1) == zb.end()) {
		r++;
		zb.insert(1);
	}
	if (v > 1 && zb.find(2) == zb.end()) {
		r++;
		zb.insert(2);
	}
	printf("Case #%d: %d\n", q, r + go(0));
}
return 0;
}

