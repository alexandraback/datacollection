#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MaxN = 1e2;
const int MaxLen = 1e2;

string s[MaxN];
int perm[MaxN];
string newS[MaxN];
string tmp;
int last[26];

int main () {
	int t;
	scanf ("%d", &t);
	for (int tests = 0; tests < t; tests++) {
		int n;
		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		for (int i = 0; i < n; i++)
			perm[i] = i;
		int ans = 0;
		do {
			for (int i = 0; i < 26; i++) last[i] = -1;
			tmp = "";
			for (int i = 0; i < n; i++)
				tmp += s[perm[i]];
			bool ok = true;
			for (int i = 0; i < (int)tmp.length(); i++) {
				int ps = tmp[i] - 'a';
				if (last[ps] != -1) {
					if (i != last[ps] + 1) {
						ok = false;
						break;
					}
				} 
				last[ps] = i;
			}
			if (ok)
				ans++;
		} while (next_permutation(perm, perm + n));

		printf ("Case #%d: %d\n", tests + 1, ans);
	}
}

