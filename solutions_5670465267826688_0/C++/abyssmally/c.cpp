#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back

struct numb {
	int x, min;
	numb() {}
	numb(int x, int min) : x(x), min(min) {}
};
int trs[4][4] = {
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}
};
int mns[4][4] = {
	{0,0,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,0,1,1}
};
numb mult(numb a, numb b) {
	numb res;
	res.x = trs[a.x][b.x];
	res.min = a.min ^ b.min ^ mns[a.x][b.x];
	return res;
}
numb poww(numb a, int p) {
	if (p==0) {
		numb b;
		b.x = 0; b.min = 0;
		return b;
	}
	if (p==1) return a;
	numb b = poww(a, p/2);
	if (p%2 == 0) {
		return mult(b, b);
	}
	return mult(mult(b, b), a);
}
int t, l, x; char str[123456];
numb lft[123456], rht[123456];
numb trg;
int main() {
	freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);

	trg = mult(mult(numb(1,0), numb(2,0)), numb(3,0));

	scanf("%d", &t);
	fo(tc,1,t+1) {
		scanf("%d %d %s", &l, &x, str);
		printf("Case #%d: ", tc);

		fo(i,0,l) str[l + i] = str[2*l + i] = str[3*l + i] = str[i];

		numb res = numb(0,0);
		fo(i,0,l) res = mult(res, numb(str[i]-'i'+1,0));
		res = poww(res, x);
		if (res.x != trg.x || res.min != trg.min) {
			puts("NO"); continue;
		}

		long long bl = 999999999999999999LL, br = -1;

		fo(i,0,4*l) {
			numb nw;
			nw.x = str[i]-'i'+1;
			lft[i] = i ? mult(lft[i-1], nw) : nw;
			if (lft[i].x == 1 && lft[i].min == 0) {
				bl = i; break;
			}
		}
		for (int i = 4*l-1; i >= 0; i--) {
			numb nw;
			nw.x = str[i]-'i'+1;
			rht[i] = (i != 4*l-1 ? mult(nw, rht[i+1]) : nw);
			if (rht[i].x == 3 && rht[i].min == 0) {
				br = l*x - (4*l-i); break;
			}
		}

		//printf("%d %d\n", bl, br);
		puts(bl+1 < br ? "YES" : "NO");
	}

	return 0;
}