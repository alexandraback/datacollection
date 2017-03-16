#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a); i<(b); ++i)
//#define REP(i,n) FOR(i,1,(n)+1)
typedef vector<int> vi;
#define pb push_back
#define sz size()
typedef pair<int,int> pii;
#define mp make_pair
#define st first
#define nd second
typedef long long ll;
#define INF 1000000001
//#define VAR(n,v) typeof(v) n=(v)
#define ALL(t) t.begin(),t.end()
#define SC(a) scanf("%d", &a)
#define GET(a) int a; SC(a)

#define ISDEBUG 1
#define dprintf(...) if(ISDEBUG) \
{printf("\033[31m"); printf(__VA_ARGS__); printf("\033[0m");}
template <class It> void dptab(It b, It e, const char* f="%d ") {
	if(ISDEBUG) {
		for(It it=b; it!=e; ++it) dprintf(f, *it); dprintf("\n");
}}

int main() {
	GET(t);
	FOR(ti,0,t) {
		GET(rows);
		GET(cols);
		GET(width);
		int res = 0;
		res += (rows - 1) * cols / width;
		res += (double) (cols - width) / width;
		if(cols % width != 0) {
			res += 1;
		}
		res += width;
		printf("Case #%d: %d\n", ti + 1, res);
	}
	return 0;
}
