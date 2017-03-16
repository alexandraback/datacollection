
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int feld[1000][1000];
int maxi[2][1000];
bool check(){
		int R,C;
		cin >> R >> C;
		FOR(r,0,R)FOR(c,0,C)cin >> feld[r][c];
		memset(maxi,0,sizeof(maxi));
		FOR(r,0,R)FOR(c,0,C)maxi[0][r] = max(maxi[0][r], feld[r][c]);
		FOR(r,0,R)FOR(c,0,C)maxi[1][c] = max(maxi[1][c], feld[r][c]);
		FOR(r,0,R)FOR(c,0,C)if(feld[r][c] != min(maxi[0][r], maxi[1][c]))return false;
		return true;
}
int main() {
	int tc;
	cin >> tc;
	FOR(tcc, 1, tc + 1){
		cout << "Case #" << tcc <<": ";
		if(check())cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
