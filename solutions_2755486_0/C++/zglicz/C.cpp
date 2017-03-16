#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
typedef short int sint;

struct attack{
	int l,r;
	int t, s;
	attack(int _l, int _r, int _t, int _s) : l(_l), r(_r), t(_t), s(_s) {}
	bool operator <(const attack &diffAttacks) const {
		if (t != diffAttacks.t) return t < diffAttacks.t;
		if (l != diffAttacks.l) return l < diffAttacks.l;
		if (r != diffAttacks.r) return r < diffAttacks.r;
		return s  < diffAttacks.s;
	}
};

const int dl = 1000;
int wys[2 * dl];
vector<attack> attacks;

void printWall() {
	REP(i, 2*dl) {
		printf("%3d ", i);
	}
	printf("\n");
	REP(i, 2*dl) {
		printf("%3d ", wys[i]);
	}
	printf("\n");
}

int solve() {
	attacks.clear();
	REP(i, 2 * dl) wys[i] = 0;
	int n;
	cin >> n;
	REP(i, n) {
		int di, ni, wi,ei,si,dd,dp,ds;
		cin >> di >> ni >> wi >> ei >> si >> dd >> dp >> ds;
		wi += dl;
		ei += dl;
		REP(j, ni) {
			attacks.PB(attack(wi, ei, di, si));
			//printf("add attacks: (l,r,t,s): %d, %d, %d, %d\n", wi, ei, di, si);
			wi += dp;
			ei += dp;
			si += ds;
			di += dd;
		}
	}
	sort(ALL(attacks));
	int wsk = 0 ;
	int res = 0;
	while (wsk < SIZE(attacks)) {
		int pom = wsk;
		//printf("on day: %d\n", attacks[pom].t);
		while (attacks[pom].t == attacks[wsk].t) {
			bool isAttack = false;
			FOR(i, attacks[pom].l, attacks[pom].r-1) {
				if (wys[i] < attacks[pom].s)
					isAttack = true;
			}
			if (isAttack) {
				++res;
				//printf("success\n");
			}
			pom++;
		}
		//printf("wsk : %d, pom: %d\n", wsk, pom);
		FOR(i, wsk, pom-1) {
			FOR(j, attacks[i].l, attacks[i].r - 1) {
				wys[j] = max(wys[j], attacks[i].s);
			}
		}
		//printWall();
		wsk = pom;
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	REP(i, t) {
		cout << "Case #" << (i+1) << ": " << solve() << endl;
	}
}