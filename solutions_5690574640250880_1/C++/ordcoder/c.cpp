#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#if !defined(ID)
#define ID(x)
#endif
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){ID(cerr<<' '<<_;E($...);)}
#define E($...) E(#$,'=',$,'\n')

vector<string> ans;
bool swapped;
int m;
void printans(int tc, bool can = true) {
	printf("Case #%d:\n", tc);
	if (!can) {
		puts("Impossible");
		return;
	}
	ans[0][0] = 'c';
	if (swapped) {
		vector<string> sans(ans.front().size(), string(ans.size(), '!'));
		for (size_t i = 0; i < ans.size(); ++i)
			for (size_t j = 0; j < ans[i].size(); ++j)
				sans[j][i] = ans[i][j];
		ans = sans;
	}
	for (const auto &s: ans)
		puts(s.c_str());
	int cnt = 0;
	for (const auto &s: ans) for (char ch: s) if (ch == '*') ++cnt;
	assert(cnt == m);
}

int main() {
	ios_base::sync_with_stdio(false);
	int tn;
	scanf("%d", &tn);
	for (int tc = 1; tc <= tn; ++tc) {
		int r, c;
		scanf("%d%d%d", &r, &c, &m);
		int l = r * c - m;
		//E(r, c, m);
		assert(l > 0);
		swapped = r > c;
		if (swapped) swap(r, c);
		ans.assign(r, string(c, '*'));
		
		if (l == 1) {
			printans(tc);
		} else if (m == 0) {
			ans.assign(r, string(c, '.'));
			printans(tc);
		} else if (r == 1) {
			fill(&ans[0][0], &ans[0][l], '.');
			printans(tc);
		} else if ((r == 2) && (l & 1)) {
			printans(tc, false);
		} else {
			if (l < 4) {
				printans(tc, false);
				continue;
			}
			if ((l < 9) && (l & 1)) {
				printans(tc, false);
				continue;
			}
			for (int i = 1; i < r; ++i) {
				assert(l >= 0);
				for (int j = 1; j < c; ++j) {
					int dl = 1;
					if (i == 1) dl *= 2;
					if (j == 1) dl *= 2;

					if (!l) break;
					assert(l >= dl);
					if (l == 2 && dl == 1 && i + 1 < r) break;
					if (l == 2 && dl == 1) assert(j + 1 < c);
					if (l == 3 && dl == 2 && i == 1) break;

					ans[0][0] = ans[i][0] = ans[0][j] = ans[i][j] = '.';
					l -= dl;
				}
				assert(l >= 0);
				if (!l) break;
			}
			assert(l == 0);
			printans(tc);
		}
	}
	return 0;
}
