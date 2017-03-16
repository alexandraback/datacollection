//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

long long DP[32][2][2][2];
string A, B, K;

long long dp(int i, bool dA, bool dB, bool dK) {
	if(i == -1) return dA && dB && dK ? 1 : 0;
	long long &ret = DP[i][dA][dB][dK];
	if(ret != -1) return ret;
	ret = 0;
	//trying 1
	if(dK || K[i] == '1') {
		if((dA || A[i] == '1') && (dB || B[i] == '1')) {
			ret += dp(i - 1, dA, dB, dK);
		}
	}
	//trying 0
	//0-0
	ret += dp(i - 1, dA | ('0' < A[i]), dB | ('0' < B[i]), dK | ('0' < K[i]));
	//0-1
	if(dB || B[i] == '1')
		ret += dp(i - 1, dA | ('0' < A[i]), dB, dK | ('0' < K[i]));
	//1-1
	if(dA || A[i] == '1')
		ret += dp(i - 1, dA, dB | ('0' < B[i]), dK | ('0' < K[i]));
	return ret;
}

string bits(int a) {
	string ret = "";
	if(a == 0) ret += '0';
	while(a) ret += (a & 1) + '0', a >>= 1;
	return ret;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cas = 1; cin >> t;
	while(t--) {
		cout << "Case #" << cas++ << ": ";
		int a, b, k, count = 0; cin >> a >> b >> k;
		A = bits(a);
		B = bits(b);
		K = bits(k);
		int maxLen = max(len(A), max(len(B), len(K)));
		for(int i = len(A); i < maxLen; i++) A += '0';
		for(int i = len(B); i < maxLen; i++) B += '0';
		for(int i = len(K); i < maxLen; i++) K += '0';
		memset(DP, -1, sizeof DP);
		cout << dp(maxLen - 1, 0, 0, 0) << '\n';
	}
	return 0;
}