#include <bits/stdc++.h>
using namespace std;

int main(){
	int test;
	int r, c, w;
	freopen("A-large.in", "r",stdin);
	freopen("test.out", "w", stdout);
	scanf("%d", &test);
	for (int i=1; i<= test; i++){
		scanf("%d %d %d", &r, &c, &w);
		int carry = (c/w)*r + w-1 ;
		printf("Case #%d: %d\n", i, (c % w == 0)? carry : carry + 1);
	}
}