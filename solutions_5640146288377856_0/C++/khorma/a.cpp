//In the name of God
//...
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double LD;


int r, c, w, mark[30], a[30];

bool bad() {
	for (int i = 0; i <= c - w; i++) {
		bool flag = false;
		for (int j = 0; j < i; j++)
			if (mark[j] == 2)
				flag = true;
		for (int j = i; j < w + i; j++)
			if (mark[j] == 1)
				flag = true;
		for (int j = w + i; j < c; j++)
			if (mark[j] == 2)
				flag = true;
		if (!flag)
			return false;
	}
	return true;
}
int main() {
	int test = 0;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		cin >> r >> c >> w;
		for (int i = 0; i < c; i++)
			a[i] = i;
		int ans = c + 2;
		do {
			fill(mark, mark + c, 0);
			int cnt = 0;
			for (int i = 0; i < c; i++) {
				mark[a[i]] = 1;
				if (bad()){
					mark[a[i]] = 2;
					cnt++;
					if (cnt == w)
						ans = min(ans, i + 1);
				}
			}
		} while (next_permutation(a, a + c));
		cout << "Case #" << tt << ": ";
		cout << ans << '\n';
	}
	return 0;
}
