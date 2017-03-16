#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
#endif
}

#define REP(i, n) for (int i = 0; i < (n); i++)

const int MAX = 3000;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"[";for(int i=0;i<v.size();i++)os<<" "<<v[i];os<<" ]";
    return os;
}

void solve() {
	set<vector<int> > v;
	int n; scanf("%d ", &n);
	vector<int> d(MAX);
	REP(i, 2 * n - 1) {
		REP(j, n) {
			int a; scanf("%d ", &a);
			d[a]++;
		}
	}
	vector<int> odd;
	REP(i, MAX) if (d[i] % 2) odd.push_back(i);
	sort(odd.begin(), odd.end());
	REP(i, odd.size()) {
		if (i) printf(" ");
		printf("%d", odd[i]);
	}
	printf("\n");
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
