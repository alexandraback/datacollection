#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,n)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e3 + 5;

int n;
multiset<pair<int,pii> > secik;

void solve() {
	scanf("%d",&n);
	secik.clear();
	REP(i,n) {
		int x;
		scanf("%d",&x);
		secik.insert(mp(-x,mp(1,x)));
	}
	
	int res = inf;
	int ile_podzialow = 0;
	while (ile_podzialow < res) {
		res = min(res, ile_podzialow - secik.begin() -> st);
		pii x = secik.begin() -> nd;
		secik.erase(secik.begin());
		secik.insert(mp(-((x.nd + x.st)/(x.st + 1)),mp(x.st+1,x.nd)));
		++ile_podzialow;
	}
	printf("%d\n",res);
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	int test;
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		solve();
	}
	return 0;
}
