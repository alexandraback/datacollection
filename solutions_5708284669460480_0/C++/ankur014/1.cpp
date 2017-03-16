#include <bits/stdc++.h>
using namespace std;

int k, l, s;
char key[20], tgt[20];
char cur[20];
int maxi, sum, cnt;

void f(int pos)
{
	if (pos == s) {
		int lc = 0;
		for (int i = 0; i < s; i++) {
			int id = 0;
			for (int j = i; j < s; j++) {
				if (cur[j] == tgt[id]) {
					id++;
					if (id == l) break;
				} else break;
			}
			if (id == l) lc++;
		}
		maxi = max(maxi, lc);
		sum += lc;
		cnt++;
		return;
	}

	for (int i = 0; i < k; i++) {
		cur[pos] = key[i];
		f(pos + 1);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int t;
	scanf("%d", &t);
	double ans;
	for (int kase = 1; kase <= t; ++kase) {
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s %s", key, tgt);
		
		maxi = -1;
		sum = 0;
		cnt = 0;

		f(0);

		ans = maxi - (sum / (cnt * 1.0));

		printf("Case #%d: %.9lf\n", kase, ans);
	}
	return 0;
}