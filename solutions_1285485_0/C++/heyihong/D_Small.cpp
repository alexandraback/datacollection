#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for (int I=int(A);I<int(B);++I)
#define MEM(A,B) memset(A,B,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(B));
typedef __int64 LL;
const int N(32);
char s[N];
int ca, n, m, D, x, y, ans, t;
set<pair<int, int> > ha;
vector<double> q;
void go(int X, int Y, int a, int b, int c, int d)
{
     if (ha.count(make_pair(X, Y))) return;
	 if ((X - x) * (X - x) + (Y - y) * (Y - y) > D * D) return;
	 if (x != X || y != Y) q.push_back(atan2(X - x, Y - y));
	 //printf("%d %d\n", X, Y);
	 ha.insert(make_pair(X, Y));
	 go(X + a, Y, -c, b, -a, d);
	 go(X + c, Y, -c, b, -a, d);
	 go(X, Y + b, a, -d, c, -b);
	 go(X, Y + d, a, -d, c, -b);
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("D.out", "w", stdout);
	for (scanf("%d", &ca); ca; --ca) {
	    scanf("%d%d%d", &n, &m, &D);
		ha.clear();
		FOR(i, 0, n) {
		   scanf("%s", s);
		   FOR(j, 0, m)
		      if (s[j] == 'X') {
			     x = i; y = j;
			  }
		}
		q.clear();
		go(x, y, - (x - 1) * 2 - 1, -(y - 1) * 2 - 1, 2 * (n - 2 - x) + 1, 2 * (m - 2 - y) + 1);
		sort(q.begin(), q.end());
		ans = 0;
		FOR(i, 0, q.size())
		   if (i == 0 || fabs(q[i] - q[i - 1]) > 1e-6) ++ans;
		printf("Case #%d: %d\n", ++t, ans);
	}
	return 0;
}
