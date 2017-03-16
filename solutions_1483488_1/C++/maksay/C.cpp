#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <set>
using namespace std;
#define L(s) (int)((s).size())
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
#define inf 1000000000
#define ull unsigned long long
#define ll long long
#define all(s) (s).begin(), (s).end()
#define VI vector<int>
int cases, A, B;
int main() {
	freopen("/home/maksay/Downloads/C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> cases;
	for(int casenum = 1; casenum <= cases; ++casenum) {
		cerr << casenum << endl;
		cin >> A >> B;
		int ans = 0, p10 = 1;
		for(int i = A; i <= B; ++i) {
			while(p10 * 10 <= i) p10 *= 10;
			VI shifts(0);
			int x = i;
			for(int iter = 0; iter < 7; ++iter) {
				x = x / 10 + p10 * (x % 10);
				shifts.pb(x);
			}
			sort(all(shifts));
			shifts.resize(unique(all(shifts)) - shifts.begin());
			for(int j = 0; j < L(shifts); ++j) {
				if (A <= shifts[j] && shifts[j] <= B && shifts[j] != i) ++ans;
			}
		}
		printf("Case #%d: %d\n", casenum, ans / 2);
	}
	return 0;
}
