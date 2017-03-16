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

vector<LL> wys;

bool isVowel(char c) {
	if (c == 'a' || c =='e' || c=='i' || c=='o' || c == 'u') return true;
	return false;
}

LL solve() {
	string txt;
	int dl;
	cin >> txt >> dl;
	LL n = SIZE(txt);
	int akt = 0;
	wys.clear();
	REP(i, n) {
		if (isVowel(txt[i])) {
			akt = 0;
		} else {
			++akt;
			if (akt >= dl) {
				//printf("PB: %d\n", i);
				wys.PB(i);
			}
		}
	}
	LL res = 0;
	if (wys.empty()) return 0;
	int wsk = 0;
	REP(i, n - dl + 1) {
		//printf("i : %d\n", i);
		while (wsk < SIZE(wys) && wys[wsk] < i + dl-1) ++wsk;
		//printf("wsk : %d\n", wsk);
		if (wsk == SIZE(wys)) break;
		//printf("wys: %d\n", wys[wsk]);
		res = res + n - wys[wsk];
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