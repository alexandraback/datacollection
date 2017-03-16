#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;


const LL MAXN = 1e14;
vector<LL> fair;

int solve() {
	LL A, B;
	scanf("%I64d %I64d", &A, &B);

	int res = 0;
	for(int i = 0; i < fair.size(); i++) {
		if(A <= fair[i] && fair[i] <= B) res++;
	}
	return res;

}

bool check(LL x) {
	LL z = x;
	LL y = 0;

	while(x) {
		y = 10*y + (x%10);
		x /= 10;
	}

	return z == y;

}
void init() {
	for(LL i = 1; i*i <= MAXN; i++) {
		if(check(i) && check(i*i)) { 
			fair.push_back(i*i);
		}
	}

}


int main() {
	init();
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
}