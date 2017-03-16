
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
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

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

bool check(){
	int X, R, C;
	cin >> X >> R >> C;
	if(X >= 7)return false;
	if((R*C)%X != 0)return false;
	if(X == 1)return true;
	if(X == 2)return true;
	if(X == 3)return min(R, C) > 1;
	if(X == 4)return min(R, C) > 2;
	if(X == 5)return min(R, C) > 3;
	if(X == 6)return min(R, C) > 3;
	assert(false);
	return true;
}

int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1){
		cout << "Case #" << tc << ": ";
		if(check())cout << "GABRIEL\n";
		else cout << "RICHARD\n";
	}
	return 0;
}
