
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

int R,C,D;
string grid[100];
int xs,xl,ys,yl;
ll dx[300],dy[300];
set<pii > dirs;
int gcd(int a, int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int calc(){
	dirs.clear();
	FOR(r,0,R)FOR(c,0,C)if(grid[r][c] == 'X'){
		xs = r*2-1;
		ys = c*2-1;
		xl = R*2-xs-4;
		yl = C*2-ys-4;
	}
	dx[150] = dy[150] = 0;
	FOR(i,1,150){
		dx[150-i] = dx[150-i+1] - xs;
		dx[150+i] = dx[150+i-1] + xl;
		dy[150-i] = dy[150-i+1] - ys;
		dy[150+i] = dy[150+i-1] + yl;
		++i;
		dx[150-i] = dx[150-i+1] - xl;
		dx[150+i] = dx[150+i-1] + xs;
		dy[150-i] = dy[150-i+1] - yl;
		dy[150+i] = dy[150+i-1] + ys;
	}
	FOR(i,10,290)FOR(j,10,290)if(dx[i]*dx[i]+dy[j]*dy[j]<=D*D){
		if(dx[i]==0&&dy[j]==0)continue;
		int gc = gcd(abs(dx[i]),abs(dy[j]));
		dirs.insert(mp(dx[i]/gc,dy[j]/gc));
	}
	return sz(dirs);
}

int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		cin >> R >> C >> D;
		FOR(i,0,R)cin >> grid[i];
		cout <<"Case #" << tcc << ": " << calc() << endl;
	}
	return 0;
}

