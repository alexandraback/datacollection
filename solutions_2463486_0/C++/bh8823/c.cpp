#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MAXL 10000000
using namespace std;
const int INF = 987654321;
const int MOD = 1000000007;

long long SQ[MAXL+1];
int temp[15];
bool isFair(long long x) {
	int idx = 0;
	while (x != 0) {
		int d = x % 10;
		temp[idx++] = d;
		x /= 10;
	}
	// idx = len
	for (int i = 0; i < idx -1 - i; i++) {
		if (temp[i] != temp[idx - 1]) return false;
	}
	return true;
}

int calc(long long n, long long m) {
	int idx1 = lower_bound(SQ, SQ + MAXL + 1,n) - SQ;
	int idx2 = lower_bound(SQ, SQ + MAXL + 1,m) - SQ;
	if (SQ[idx2] > m) idx2--;
	int ret = 0;
	while (idx1 <= idx2) {
		if (isFair(idx1) && isFair(SQ[idx1])) ret++;
		idx1++;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);

	for (long long i = 0; i <= MAXL; i++) SQ[i] = i * i;
	//printf("%lld\n", a);
	int loop = 1;
	while (loop <= T) {
		long long n, m;
		scanf("%lld",&n);
		scanf("%lld",&m);
		
		
		//for (int i = 0; i < 4; i++)
		//	scanf("%s",board[i]);
		printf("Case #%d: %d\n", loop, calc(n,m));
		loop++;
	}

	return 0;
}