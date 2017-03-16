#include<bits/stdc++.h>
using namespace std;

const int tab[5][5] = 
{{0, 0, 0, 0, 0},
{0, 1, 2, 3, 4},
{0, 2, -1, 4, -3},
{0, 3, -4, -1, 2},
{0, 4, 3, -2, -1}};

const int mn = 1e6 + 8;
char s[mn];
int pre[mn], suf[mn];
 
int Trans(int d, int p) {
	int pos = 1;
	if (d < 0) pos = -pos, d = -d;
	if (p < 0) pos = -pos, p = -p;
	d = tab[d][p];
	return d * pos;
}

inline void Solve() {
	int n, x; cin >> n >> x;
	scanf("%s", s);
	for (int i = 0; i < n; i++) s[i] -= 'g';
	
	for (int i = 1; i < x; i++)
		for (int j = 0; j < n; j++)
			s[i * n + j] = s[j];
	n *= x;
	
	int tt = Trans(2, 3); tt = Trans(tt, 4);	
	int p = 1, mp = -1;
	for (int i = 0; i < n; i++) {
		p = Trans(p, s[i]);
		if (p == 2 && mp == -1) mp = i;
	}
	
	if (p != tt || mp == -1) {puts("NO"); return ;}
	 
	p = 1;
	for (int i = n - 1; i >= 0; i--) {
		p = Trans(s[i], p);
		if (p == 4 && i > mp) {puts("YES"); return ;}
	}
	puts("NO");
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int _; cin >> _;
	for (int i = 1; i <= _; i++) {
		if (i == 27)
			int o = 1;
		printf("Case #%d: ", i);
		 Solve();
	}
}
