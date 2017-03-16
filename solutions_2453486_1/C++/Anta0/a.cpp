#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER)
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

bool check(char c, char x, char y, char z, char w) {
	bool r = true;
	r &= x != '.';
	r &= y != '.';
	r &= z != '.';
	r &= w != '.';
	int cnt = 0;
	cnt += x == c;
	cnt += y == c;
	cnt += z == c;
	cnt += w == c;
	r &= cnt == 4 || (cnt == 3 && (x == 'T' || y == 'T' || z == 'T' || w == 'T'));
	return r;
}
int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		static char b[4][5];
		rep(i, 4) cin >> b[i];
		int count = 0;
		rep(i, 4) rep(j, 4) count += b[i][j] != '.';
		string r;
		rep(xo, 2) {
			char c = "XO"[xo];
			bool won = false;
			rep(i, 4) {
				won |= check(c, b[i][0], b[i][1], b[i][2], b[i][3]);
				won |= check(c, b[0][i], b[1][i], b[2][i], b[3][i]);
			}
			won |= check(c, b[0][0], b[1][1], b[2][2], b[3][3]);
			won |= check(c, b[0][3], b[1][2], b[2][1], b[3][0]);
			if(won) r = c + string(" won");
		}

		if(r.empty()) {
			if(count == 16) r = "Draw";
			else r = "Game has not completed";
		}

		printf("Case #%d: %s\n", ii+1, r.c_str());
	}
	return 0;
}
