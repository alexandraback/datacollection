#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

vector<int64> v; 

bool palindromo(int64 x) {
	int64 y = 0;
	int64 aux = x;
	while (aux != 0) {
		y = y * 10 + aux % 10;
		aux = aux/10;
	}
	if (x == y) return true;
	return false;
}

void init() {
	for (int64 i = 1; i <= 10000000; i++) {
		if (palindromo(i) && palindromo(i*i)) {
			v.push_back(i*i);
			//printf("%lld\n", i*i);
		}
	}
}

int main()
{	
	int t;
	scanf("%d", &t);
	init();
	REP(k, t) {
		int64 a, b;
		scanf("%lld %lld", &a, &b);
		int x = lower_bound(v.begin(), v.end(), a) - v.begin();
		int y = upper_bound(v.begin(), v.end(), b) - v.begin();
		printf("Case #%d: %d\n", k+1, y-x);
	}
	return 0;
}