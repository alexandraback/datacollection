#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define VAR(n,v) typeof(v) n=(v)
#define REP(i,n) for(int i=1; i<=(n); ++i)
#define FOR(i,a,b) for(VAR(i,a); i!=(b); ++i)
#define FORE(it,t) FOR(it,t.begin(),t.end())
typedef vector<int> vi;
#define pb push_back
typedef pair<int,int> pii;
#define mp make_pair
#define st first
#define nd second
typedef long long ll;
#define INF 1000000001
#define sz size()
#define ALL(t) t.begin(),t.end()
#define SC(a) scanf("%d", &a)
#define GET(a) int a; SC(a)
#define ISDEBUG 0
#define dprintf(...) if(0) \
	{printf("\033[31m"); printf(__VA_ARGS__); printf("\033[0m");}
template <class It> void dptab(It b, It e, const char* f="%d ")
	{if(ISDEBUG) {for(It it=b; it!=e; ++it) dprintf(f, *it); dprintf("\n"); }}

char name[1000100];
set<char> vowels;

ll thesq(ll len) {
	return len * (len+1) / 2;
}

ll result() {
	int n;
	scanf("%s %d", name, &n);
	vi t(strlen(name), 0);

	vi good;
	//good.pb(n-2);
	FOR(i,0,t.sz) {
		if(vowels.count(name[i]) == 0)
			t[i] = (i? t[i-1] : 0) + 1;
		if(t[i] >= n) {
			good.pb(i);
		}
	}
	dptab(ALL(t));
	if(good.sz==0) return 0;

	good.pb(t.sz);
	dptab(ALL(good));
	ll res = thesq(t.sz);
	res -= thesq(good.front());
	dprintf("resinit %lld\n", res);
	FOR(i,0,good.sz-1) {
		ll odj = 0;
		int len = good[i+1] - good[i];
		odj += thesq(len);
		odj += (n-2) * (ll) len;
		dprintf("odj = %lld\n", odj);
		res -= odj;
	}
	return res;
}

int main() {
	vowels.insert('a'); vowels.insert('e'); vowels.insert('i'); vowels.insert('o'); vowels.insert('u');
	GET(tests);
	REP(test,tests) {
		printf("Case #%d: %lld\n", test, result());
	}
	return 0;	
}

