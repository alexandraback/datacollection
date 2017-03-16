#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define N 1000200
#define M 200020
#define LL long long
#define inf 0x3f3f3f3f


int x, r, c;
void f() {
	puts("RICHARD");
}
void g() {
	puts("GABRIEL");
}
int main() {
	//freopen("tt.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cas, kk = 0;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%d%d%d", &x, &r, &c);
		if(r > c) swap(r, c);
		printf("Case #%d: ", ++kk);
		if(r * c % x) {
			f();
			continue;
		}
		if(x == 1 || x == 2) g();
		if(x == 3) {
			if(r == 1) f();
			else
				g();
		}
		if(x == 4) {
			if(r == 1) f();
			else if(r == 2) f();
			else g();
		}
		if(x == 5) {
			if(r == 1) f();
			else if(r == 2) f();
			else g();
		}
		if(x == 6) {
			if(r == 1 || r == 2 || r == 3) f();
			else g();
		}
		if(x >= 7) f();
	}
	return 0;
}