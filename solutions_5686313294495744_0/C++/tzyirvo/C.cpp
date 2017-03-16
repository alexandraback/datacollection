/*
 * Problem: 
 * Link: 
 * Author: 
 * Handle: 
 * State: 
 * Date: 
 * Comments: 
 */
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
#define EPS 		1e-8
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define F(i,a)      FOR(i,0,a)
#define PB          push_back
#define S           size()
#define MP          make_pair
#define MS(v, x)	memset(v, x, sizeof v)
#define ALL(v)      v.begin(),v.end()
#define LLA(v)      v.rbegin(),v.rend()
#define fi          first
#define se          second
#define NL 			printf("\n")
#define SP 			system("pause")
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
const double PI = acos(-1.0);
#define BitSet(arg,posn) ((arg) | (1L << (posn)))
#define BitClr(arg,posn) ((arg) & ~(1L << (posn)))
#define BitTst(arg,posn) bool((arg) & (1L << (posn)))
#define BitFlp(arg,posn) ((arg) ^ (1L << (posn)))
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long   LL;

vector<pair<string, int> > A, B;
int G[1010][1010];
int ca[1010], cb[1010];

void run() {
	int N = in();
	MS(G, 0);
	MS(ca, 0);
	MS(cb, 0);
	set<string> sa;
	set<string> sb;
	A.clear();
	B.clear();
	map<string, int> m;
	int cnt = 0;
	F(i, N) {
		string a, b;
		cin >> a >> b;
		if(m[a] == 0) m[a] = ++cnt;
		if(m[b] == 0) m[b] = ++cnt;
		sa.insert(a);
		sb.insert(b);
		ca[m[a]]++;
		cb[m[b]]++;
		G[m[a]][m[b]] = 1;
	}
	int ans = 0;
	foreach(i, sa) {
		ans += ca[m[*i]];
	}
	foreach(j, sb) {
				ans += cb[m[*j]];
		}
		// cout << ans << endl;
	cout << ((ans / 2) - max(sa.S, sb.S)) << endl;
}

int main() {
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int n = in();
	FOR(i, 1, n+1) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}