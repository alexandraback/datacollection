#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()

template<class P, class Q> inline void mmin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void mmax(P &a, Q b) { if (a < b) a = b; }

typedef long long LL;
typedef pair<int, int> pii;

const int MAXn = 100*1000;
int a, b, k;

int solve()
{
	int ret = 0;
	rep(i, a) rep(j, b)
		ret += (i&j) < k;
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;
	for(int i=1; i<=nt; ++i) {
		cin >> a >> b >> k;
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;

/*	rep(i, 32) if(a & (1<<i))
	rep(j, 32) if(b & (1<<j)) {
			int x = a & ((-1) ^ ((1<<i)-1));
			int y = b & ((-1) ^ ((1<<j)-1));
			int c = x ^ y;
			if(c>=k)
				continue;
			rep(k, 32)
		}*/
}
