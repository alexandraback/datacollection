#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define LL long long

using namespace std;

LL rr,tt;
double r,t;
double ans;

int main(){
	
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int num;
	scanf("%d", &num);
	for (int z = 1; z <= num; z++){
		cin >> rr >> tt;
		r = rr;
		t = tt;
	    ans = 2 * r - 1;
		ans = ans * ans + 4 * 2 * t;
		ans = sqrt(ans);
		ans = ans + 1 - 2 * r;
		ans /= 4;
		ans = floor(ans);
		printf("Case #%d: %d\n", z, int(ans));
	}

	return 0;

}
