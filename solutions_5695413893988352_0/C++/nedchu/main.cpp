#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
const int N = 25;

char a[N], b[N];
char out[N*5];
int n, cas = 1;
LL tempa[N], tempb[N];
LL ansa, ansb, ans;

bool ck(char ch) {
	return ch == '?';
}

void update() {
	LL cura = 0, curb = 0;
	for (int i = 0; i < n; i++) {
		cura = cura * 10 + tempa[i];
		curb = curb * 10 + tempb[i];
	}
	if (abs(cura - curb) < ans) {
		ans = abs(cura - curb);
		ansa = cura, ansb = curb;
	} else if (abs(cura - curb) == ans) {
		if (cura < ansa) {
			ansa = cura, ansb = curb;
		} else if (cura == ansa && curb < ansb) {
			ansb = curb;
		}
	}
}

void dfsb(int pos) {
	if (pos == n) {
		update();
	} else if (ck(b[pos])) {
		for (int i = 0; i < 10; i++) {
			tempb[pos] = i;
			dfsb(pos+1);
		}
	} else {
		tempb[pos] = b[pos] - '0';
		dfsb(pos+1);
	}
}

void dfsa(int pos) {
	if (pos == n) {
		dfsb(0);
	}	else if (ck(a[pos])) {
		for (int i = 0; i < 10; i++) {
			tempa[pos] = i;
			dfsa(pos+1);
		}
	} else {
		tempa[pos] = a[pos] - '0';
		dfsa(pos+1);
	}
}

int main() {
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%s%s", a, b);
		n = strlen(a);
		ans = 1e18;
		sprintf(out, "Case #%%d: %%0%dI64d %%0%dI64d\n", n, n);
		dfsa(0);
		printf(out, cas, ansa, ansb);
	}
	return 0;
}
