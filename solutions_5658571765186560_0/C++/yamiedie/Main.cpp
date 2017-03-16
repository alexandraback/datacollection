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
		if(x == 1) {
			g();
		}
		if(x == 2) {
			if(r % 2 == 0 || c % 2 == 0)
				g();
			else
				f();
		}
		if(x == 3) {
			if(r * c % 3 != 0) 
				f();
			else {
				if(r == 1)
					f();
				else if(r == 2)
					g();
				else 
					g();
			}
		}
		if(x == 4) {
			if(r * c % 4)
				f();
			else {
				if(r == 1)
					f();
				else if(r == 2)
					f();
				else if(r == 3)
					g();
				else
					g();
			}
		}
		if(x > 4) f();
	}
	return 0;
}
				