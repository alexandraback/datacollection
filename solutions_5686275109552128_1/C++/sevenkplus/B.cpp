#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define N 1010

int a[N], n;

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		int s = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			s += a[i];
		}
		int c = (s-1)/n+1;
		int S = 1000;
		for (int i = 1; i <= 1000; i ++) {
			int T = 0;
			for (int j = 0; j < n; j ++) {
				T += (a[j]-1)/i;
			}
			S = min(S, i+T);
		}
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
