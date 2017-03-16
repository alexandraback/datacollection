#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define LL long long
#define LD long double

using namespace std;

LL rrr,tt;
long double rr,t;
LL l,r;
LL ans;

bool check(LL mid){
	LD x = mid * 1.0;
	LD tx = 2 * x * rr + x * (2 * x - 1);
	if (tx > t) return false;
	else return true;
}

int erfen(LL l, LL r){
	if (l == r) return l;
	LL mid = (l + r + 1) / 2;
	if (check(mid)) return erfen(mid, r);
	else return erfen(l, mid - 1);
}

int main(){
	
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	int num;
	scanf("%d", &num);
	for (int z = 1; z <= num; z++){
		cin >> rrr >> tt;
		rr = rrr;
		t = tt;
		l = 0;
		r = 1000000000;
		ans = erfen(l,r);
		printf("Case #%d: %lld\n", z, ans);
	}

	return 0;

}
