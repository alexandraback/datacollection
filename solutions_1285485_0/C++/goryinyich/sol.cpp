#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

int tc, m, n, d, r, c;
char s[100][100];

int gcd (int a, int b){
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a+b;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> tc;
	REP(ic,tc){
		scanf ("%d%d%d\n", &m, &n, &d);
		REP(i,m) gets (s[i]);
		//checking that the data is ok
		REP(i,n) if (s[0][i]!='#' || s[m-1][i]!='#'){
			cout << "FUCK!!!";
			return 0;
		}
		REP(i,m) if (s[i][0]!='#' || s[i][n-1]!='#'){
			cout << "FUCK!!!";
			return 0;
		}
		for (int i = 1; i < m-1; ++i)
			for (int j = 1; j < n-1; ++j) if (s[i][j]=='#'){
				cout << "FUCK!!!";
				return 0;
			}
		//solving, mothefucker
		REP(i,m) REP(j,n) if (s[i][j]=='X'){
			r = i; c = j; };
		r = 2*r-1; c = 2*c-1;
		m = m*2 - 4; n = n*2 - 4;

		vector<pair<int,int> > p;

		for (int i = -d; i <= d; ++i){
			for (int j = -d; j <= d; ++j) if (i!=0 || j!=0){
				int x = i*n + (i&1 ? n-c : c);
				int y = j*m + (j&1 ? m-r : r);
				int px = x - c, py = y - r;
				if (px*px + py*py <= 4*d*d) p.PB(MP(px,py));
			}
		}

		set<pair<int,int> > q;
		REP(i,SI(p)){
			int d = gcd (abs (p[i].first), abs (p[i].second));
			q.insert(MP(p[i].first/d, p[i].second/d));
		}

		cout << "Case #" << ic+1 << ": " << q.size() << endl;
	
	}
	return 0;
};