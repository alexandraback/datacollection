// esta3anna 3al sha2a belAllah ..
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<sstream>
#include<limits.h>
#include<iomanip>
#include<cstring>
#include<bitset>
#include<fstream>
#include<cmath>
#include<cassert>
#include <stdio.h>
#include<ctype.h>
using namespace std ;
#define rep(i,n,m) for(int i = (int)(n), _m = (int)(m); i < _m; ++ i)
#define	rrep(i,n,m) for(int i = (int)(n), _m = (int)(m); i >= _m; -- i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mems(arr, v) memset(arr, v, sizeof arr)
#define setBit(mask, bit) ((mask) | (1LL << (bit)))
#define resetBit(mask, bit) ((mask) & (~(1LL << (bit))))
#define flipBit(mask, bit) ((mask) ^ (1LL << (bit)))
#define is0(mask, bit)(((mask) & (1LL << (bit))) == 0)
#define is1(mask, bit)(((mask) & (1LL << (bit))) != 0)
#define removeLastBit(mask) ((mask) & ((mask) - 1LL))
#define firstBitOn(mask) ((mask) & ~((mask) - 1LL))
#define grayCode(mask) ((mask) ^ ((mask) << 1LL))
#define repSubMasks(subMask, mask) for(ll subMask = (ll)(mask), _mask = subMask; subMask; subMask = _mask & (subMask - 1))
int countBits(int mask) {int res = 0; while(mask) mask &= (mask - 1), ++ res; return res;}
#define INT_MAX  2000000000
#define INT_MIN -INT_MAX
#define EPS 1e-9
#define debug(x) cout << #x << " : " << x << endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define Read() freopen("input.txt","r",stdin)
#define Write() freopen("output.txt","w",stdout)
int dp[11][11];
int E, n, v[11], r;
int rec(int i, int e) {
	e = min(e, E);
	if(i == n)
		return 0;
	int &ret = dp[i][e];
	if(ret != -1)
		return ret;
	ret = rec(i + 1, e);
		rep(j, 0, e + 1)
			ret = max(ret, rec(i + 1, e - j + r) + v[i] * j);
	return ret;
}
int main() {
	Read();
	Write();
	int cases;
	cin >> cases;
	rep(C, 1, cases + 1) {
		cin >> E >> r >> n;
		rep(i, 0, n)
			cin >> v[i];
		mems(dp, -1);
		cout << "Case #" << C << ": " << rec(0, E) << endl;
	}
}