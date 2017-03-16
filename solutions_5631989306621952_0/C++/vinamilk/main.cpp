#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ld long double

using namespace std;

const int nm = 1010;

char s[nm];
int n;
char kq[nm];

void solve(int test) {
	printf("Case #%d: ", test);
	scanf("%s", s);
	n = strlen(s);
	string kq = "";
	kq = kq + s[0];
	for (int i = 1; i < n; ++i) {
		string tmp = kq + s[i], tmp2 = s[i] + kq;
		if (tmp > tmp2)
			kq = tmp;
		else
			kq = tmp2;
	}
	cout << kq << "\n";
}

int main() {
#ifdef LOCAL
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}

