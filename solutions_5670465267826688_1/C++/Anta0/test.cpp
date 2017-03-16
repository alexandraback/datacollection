#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

struct H {
	int x;
	H(): x(0) { }
	H(char c, bool sign = false) {
		x = c == '1' ? 0 : c == 'i' ? 1 : c == 'j' ? 2 : c == 'k' ? 3 : -99;
		if(sign) x += 4;
	}
	bool operator==(const H &that) const { return x == that.x; }
	H operator*(const H &that) const {
		static const int table[4][4] = {
			{ 0, 1, 2, 3 },
			{ 1, 4, 3, 6 },
			{ 2, 7, 4, 1 },
			{ 3, 2, 5, 4 }
		};
		H res;
		res.x = table[x % 4][that.x % 4] ^ ((x ^ that.x) & 4);
		return res;
	}
};
H operator^(H a, unsigned long long k) {
	H r;
	while(k) {
		if(k & 1) r = r * a;
		a = a * a;
		k >>= 1;
	}
	return r;
}

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int L; long long X;
		scanf("%d%lld", &L, &X);
		char *s = new char[L+1];
		scanf("%s", s);
		H prod;
		rep(i, L) prod = prod * H(s[i]);
		const H ij = H('i') * H('j'), ijk = ij * H('k');
		bool ans = false;
		if((prod ^ X) == ijk) {
			int K = (int)min<ll>(L * X, L * 8);
			H pre;
			bool oki = false;
			rer(i, 1, K) {
				pre = pre * H(s[(i-1) % L]);
				if(pre == H('i'))
					oki = true;
				else if(pre == ij)
					ans |= oki;
			}
		}
		printf("Case #%d: %s\n", ii+1, ans ? "YES" : "NO");
		delete[] s;
	}
	return 0;
}
