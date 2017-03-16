#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

long long gcd(long long x, long long y){
	while(x){
		long long t = y % x;
		y = x;
		x = t;
	}
	return y;
}

void solve(){
	long long p, q;
	scanf("%lld/%lld", &p, &q);
	long long d = gcd(p, q);
	p /= d;
	q /= d;
	int pos1 = -1;
	for(int i = 0; i < 41; i++)
		if(q & (1ll << i))
			if(pos1 == -1)
				pos1 = i;
			else{
				puts("impossible");
				return;
			}
	int pos2 = -1;
	for(int i = 0; i < 41; i++)
		if(p & (1ll << i))
			pos2 = i;
	printf("%d\n", pos1 - pos2);
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; test++){
		printf("Case #%d: ", test);
		solve();
	}
}
