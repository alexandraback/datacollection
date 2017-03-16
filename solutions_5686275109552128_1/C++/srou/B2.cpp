#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int specials(const vector<int> &diners, int maxtime) {
	int special = 0;
	for (int diner : diners) {
		special += (diner+maxtime-1) / maxtime - 1;
	}
	return special;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0;t<T;++t) {
		int D, P;
		scanf("%d", &D);
		vector<int> diners;
		for (int d = 0; d<D;++d) {
			scanf("%d", &P);
			diners.push_back(P);
		}


		int mintime = *max_element(diners.begin(), diners.end());
		for (int ti = mintime; ti>0; --ti) {
			mintime = min(mintime, ti+specials(diners, ti));
		}

		printf("Case #%d: %d\n", t+1, mintime);
	}
	return 0;
}