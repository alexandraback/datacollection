
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

int P[1024];

int main() {
	int TC;
	cin >> TC;
	FOR(tc, 1, TC+1){
		int D;
		cin >> D;
		FOR(i,0,D)cin >> P[i];
		int maxP = 0;
		FOR(i,0,D)maxP = max(maxP, P[i]);
		int bestRes = maxP;
		FOR(eatTime,1,bestRes){
			int special = 0;
			FOR(i,0,D)special += ((P[i] + eatTime - 1) / eatTime) - 1;
			bestRes = min(bestRes, special + eatTime);
		}
		cout << "Case #" << tc << ": " << bestRes << endl;
	}
	return 0;
}
