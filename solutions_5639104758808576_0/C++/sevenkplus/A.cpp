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
		string s;
		cin >> s;
		for (int i = 0; i <= n; i ++) 
			a[i] = s[i]-'0';
		for (int i = 1; i <= n; i ++)
			a[i] += a[i-1];
		int S = 0;
		for (int i = 1; i <= n; i ++) 
			S = max(S, i-a[i-1]);
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
