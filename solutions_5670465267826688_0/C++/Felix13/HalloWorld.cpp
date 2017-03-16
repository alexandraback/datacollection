#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <string.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_tree;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define INF 1000000001
#define LINF 1000000000000000001ll
#define PB push_back
#define EPS 1e-7
#define X first
#define Y second
#define MP make_pair
#define ITER(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()

int mn[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0,
		3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
int mult(int x, int y) {
	int sg = (x * y > 0 ? 1 : -1);
	x = abs(x);
	y = abs(y);
	return sg * mn[x][y];
}
int target[] = { 2, 3, 4 };

int ord(char c) {
	return c - 'i' + 2;
}
int main() {
	//ios::sync_with_stdio(0);
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int t;
	scanf("%d", &t);
	FOR(ttt,0,t)
	{
		string ans;
		LL x, n;
		string l;
		cin >> n >> x >> l;
		string lc=l;
		int total=x;
		--x;
		int vl = 1;
		FOR(i,0,l.size())
			vl = mult(vl, ord(l[i]));
		LL ad = min(100ll, x);
		FOR(i,0,ad)
			l += lc;
		x -= ad;
		int cur = 1;
		int p = 0;
		int endpos = -1;
		FOR(i,0,l.size())
		{
			cur = mult(cur, ord(l[i]));
			if (abs(cur) == target[p]) {
				if (-cur == target[p])
					cur = -1;
				else
					cur = 1;
				p++;
			}
			if (p == 3) {
				//xz
				endpos = i;
				break;
			}
		}
		if (endpos == -1)
			ans = "NO";
		else {
			int ful = endpos / n;
			endpos %= n;
			for (++endpos; endpos < n; ++endpos)
				cur = mult(cur, ord(l[endpos]));
			int toend = total - ful-1 ;
			int twol = mult(vl, vl);
			int tail = 1;
			if (toend % 2) {
				tail = vl;
				toend--;
			}
			if (twol == -1 && (toend / 2) % 2 == 1)
				tail = mult(tail, -1);
			if (mult(cur, tail) == 1)
				ans = "YES";
			else
				ans = "NO";
		}
		printf("Case #%d: %s\n", ttt + 1, ans.c_str());
	}
	return 0;
}
