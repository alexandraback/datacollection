//#pragma comment(linker, "/stack:1000000")

#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define MP make_pair
const double EPS=1e-7;
const double Pi=acos(-1.0);
#define FILL(a,v) memset(a,v,sizeof(a))
#define INF 1000000000

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PII;

VI coins;
int c,d,v;

set<int> possible() {
	set<int> res;

	REP(i, coins.size()) {
		VI p(res.begin(), res.end());
		REP(j, p.size()){
			int next = coins[i]+p[j];
			if (next <= v)
				res.insert(next);
		}
		res.insert(coins[i]);
	}

	return res;
}

int solve() {
	cin >> c >> d >> v;

	coins.clear();
	int a;
	REP(i, d){
		cin >> a;
		coins.push_back(a);
	}

	set<int> p = possible();

	while(p.size() != v) {
		int t;
		FOR(i,1,v+1)
			if (p.count(i) == 0) {
				t = i;
				break;
			}

		//cout<<"Adding " << t << endl;
		
		coins.push_back(t);
		p = possible();
	}

	return coins.size() - d;

}

int main(int argc, char** argv)
{
//	freopen("gazmyas.in","r",stdin);
//  freopen("gazmyas.out","w",stdout);

	int t;
	cin >> t;
	REP(tt, t) {
		int res = solve();
		printf("Case #%d: %d\n", tt+1, res);
	}

	
	return 0;
}