#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void solve(){
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < abs(x); ++i){
		if (x > 0){
			putchar('W');
			putchar('E');
		}		
		else {
			putchar('E');
			putchar('W');
		}
	}
	for (int i = 0; i < abs(y); ++i){
		if (y > 0){
			putchar('S');
			putchar('N');
		}
		else {
			putchar('N');
			putchar('S');
		}
	}
	puts("");
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
