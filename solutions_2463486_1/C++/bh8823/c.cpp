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
vector<long long> ans;
bool isFair(long long x) {
	int idx = 0;
	while (x != 0) {
		int d = x % 10;
		temp[idx++] = d;
		x /= 10;
	}
	// idx = len
	for (int i = 0; i < idx -1 - i; i++) {
		//printf("%d %d\n", temp[i], temp[idx -1]);
		if (temp[i] != temp[idx - 1 - i]) return false;
	}
	return true;
}
void solve() {
	int idx1 = 1;
	int idx2 = MAXL;
	while (idx1 <= idx2) {
		if (isFair(idx1) && isFair(SQ[idx1])) {
			ans.push_back(SQ[idx1]);
		}
		idx1++;
	}
}

int calc(long long n, long long m) {
	int idx1 = lower_bound(ans.begin(), ans.end(), n) - ans.begin();
	int idx2 = lower_bound(ans.begin(), ans.end(), m) - ans.begin();
	if (idx2 < ans.size() && ans[idx2] == m) idx2++;
	//printf("idx1 = %d. idx2 = %d\n", idx1,idx2);
	return idx2 - idx1;
	/*
	int ret = 0;
	//printf("idx1 = %d. idx2 = %d\n", idx1,idx2);
	while (idx1 <= idx2) {
		if (isFair(idx1) && isFair(SQ[idx1])) {
			p
			//printf("a = %d. b= %lld\n", idx1,SQ[idx1]);
			ret++;
		}
		idx1++;
	}
	return ret;
	*/
}

int main() {
	int T;
	scanf("%d", &T);

	for (long long i = 0; i <= MAXL; i++) SQ[i] = i * i;
	solve();
	//isFair(SQ[111]);
	//printf("%d %lld %d %d\n", 111,SQ[111], isFair(111), isFair(SQ[111]));
	//printf("%d %lld\n", 1111,SQ[1111]);
	//printf("%d %lld\n", 11111,SQ[11111]);
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