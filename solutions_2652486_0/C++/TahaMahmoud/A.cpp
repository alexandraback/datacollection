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
int M;
vector<int> v, ans;
bool vis[10];
int k, products[10];
void check(int indx, int prod) {
	if(indx == v.size()) {
		rep(i, 0, k)
			if(prod == products[i])
				vis[i] = true;
		return;
	}
	check(indx + 1, prod);
	check(indx + 1, prod * v[indx]);
}
void rec(int rem) {
	if(ans.size())
		return;
	if(rem == 0) {
		mems(vis, false);
		check(0, 1);
		bool ok = true;
		rep(i, 0, k)
			ok &= vis[i];
		if(ok)
			ans = v;
		return;
	}
	rep(i, 2, M + 1) {
		v.pb(i);
		rec(rem - 1);
		v.pop_back();
	}
}
int main() {
	Read();
	Write();
	int cases;
	cin >> cases;
	int n, r;
	rep(C, 1, cases + 1) {
		cin >> r >> n >> M >> k;
		cout << "Case #" << C << ": \n";
		rep(atta, 0, r) {
			rep(j, 0, k)
				cin >> products[j];
			ans.clear();
			v.clear();
			rec(n);
			rep(i, 0, ans.size())
				cout << ans[i];
			cout << endl;
		}
	}
}