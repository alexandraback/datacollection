#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
typedef long double ld;

int R, N, M, K;
vector<vector<int> > allV;
vector<set<int> > allP;
vector<int> c;

void gen(int cur, int rem) {
	if (rem == 0) {
		allV.push_back(c);
		return;
	}
	if (cur > M)
		return;
	c.push_back(cur);
	gen(cur, rem - 1);
	c.pop_back();
	gen(cur + 1, rem);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("1.in", "rt", stdin);
	freopen("1A/C-small-1-attempt0.in", "rt", stdin);
	freopen("1A/C-small-1.out","wt",stdout);
//	freopen("1A/B-large.in", "rt", stdin);
//	freopen("1A/B-large.out","wt",stdout);
#endif
	int n;
	cin >> n;
	for (int tt = 0; tt < n; ++tt) {
		cout << "Case #" << tt + 1 << ":\n";

		cin >> R >> N >> M >> K;
		gen(2, N);
		allP.resize(allV.size());
		for (int i = 0; i < allV.size(); ++i) {
			for (int mask = 0; mask < (1 << N); ++mask) {
				int prod = 1;
				for (int j = 0; j < N; ++j) {
					if ((mask >> j) & 1)
						prod *= allV[i][j];
				}
				allP[i].insert(prod);
			}
//			foreach(allP[i], it)
//				cout << *it << " ";
//			cout << endl;
		}
		for (int r = 0; r < R; ++r) {
			vector<int> p;
			for (int k = 0; k < K; ++k) {
				int cur;
				cin >> cur;
				p.push_back(cur);
			}
			for (int i = 0; i < allV.size(); ++i) {
				bool valid = 1;
				for (int k = 0; k < K; ++k) {
					if(allP[i].count(p[k]) == 0)
						valid = 0;
				}
				if(valid) {
					for (int j = 0; j < N; ++j) {
						cout << allV[i][j];
					}
					cout << endl;
					goto Next;
				}
			}
			Next:;
		}
	}
	return 0;
}
