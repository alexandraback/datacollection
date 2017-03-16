#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#define MAX 105

using namespace std;

double dp[MAX][MAX];
double P[MAX];
bool seen[MAX][MAX];
char str[MAX];
int suf, n;
set<char> C;

double test(vector<char>& V, int s, double p) {
	if (s == 0) {
		int m = 0, i, j;
		for (i = 0; i < (int)V.size(); i++) {
			bool is = true;
			for (j = 0; j < n && i + j < (int)V.size(); j++)
				if (str[j] != V[i + j])
					is = false;
			if (is && j == n)
				m++;
		}
		return p * (double)m;
	} else {
		double ans = 0.0;
		for (set<char>::iterator it = C.begin(); it != C.end(); ++it) {
			V.push_back(*it);
			ans += test(V, s - 1, p * P[*it - 'A']);
			V.pop_back();
		}
		return ans;
	}
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int c, cc, i, j, k, s;
	scanf("%d\n", &c);
	for (cc = 0; cc < c; cc++) {
		C.clear();
		scanf("%d %d %d\n", &k, &n, &s);
		scanf("%s\n", str);
		for (i = 0; i < 26; i++)
			P[i] = 0.0;
		for (i = 0; i < k; i++) {
			P[str[i] - 'A'] += 1.0 / (double)k;
			C.insert(str[i]);
		}
		scanf("%s\n", str);
		for (suf = 1; suf < n; suf++) {
			bool is = true;
			for (j = 0; suf + j < n; j++)
				if (str[j] != str[suf + j])
					is = false;
			if (is)
				break;
		}
		bool can = true;
		for (i = 0; i < n; i++)
			if (P[str[i] - 'A'] == 0.0)
				can = false;
		if (! can || s < n) {
			printf("Case #%d: 0.0\n", cc + 1);
			continue;
		}
		int mp = 1 + (s - n) / suf;
		vector<char> V;
		double p = test(V, s, 1.0);
		printf("Case #%d: %.8lf\n", cc + 1, (double)mp - p);
	}
	return 0;
}


