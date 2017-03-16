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
#include <iomanip>
#include <cassert>
#include <unordered_set> // C++11
#include <unordered_map> // C++11
#include <tuple>         // C++11
#include <bitset>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
 
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }
 
#define N (1024)
 
map<char, int> p1 = {{'1', 0},{'i',1},{'j',2},{'k',3}};
map<pii, int> m = {{{0,0},0}, {{0,1},1}, {{0,2},2}, {{0,3},3},
                   {{0,4},4}, {{0,5},5}, {{0,6},6}, {{0,7},7},
				   {{1,0},1}, {{1,1},4}, {{1,2},3}, {{1,3},6},
				   {{1,4},5}, {{1,5},0}, {{1,6},7}, {{1,7},2},
				   {{2,0},2}, {{2,1},7}, {{2,2},4}, {{2,3},1},
				   {{2,4},6}, {{2,5},3}, {{2,6},0}, {{2,7},5},
				   {{3,0},3}, {{3,1},2}, {{3,2},5}, {{3,3},4},
				   {{3,4},7}, {{3,5},6}, {{3,6},1}, {{3,7},0},
				   {{4,0},4}, {{4,1},5}, {{4,2},6}, {{4,3},7},
				   {{4,4},0}, {{4,5},1}, {{4,6},2}, {{4,7},3},
				   {{5,0},5}, {{5,1},0}, {{5,2},7}, {{5,3},2},
				   {{5,4},1}, {{5,5},4}, {{5,6},3}, {{5,7},6},
				   {{6,0},6}, {{6,1},3}, {{6,2},0}, {{6,3},5},
				   {{6,4},2}, {{6,5},7}, {{6,6},4}, {{6,7},1},
				   {{7,0},7}, {{7,1},6}, {{7,2},1}, {{7,3},0},
				   {{7,4},3}, {{7,5},2}, {{7,6},5}, {{7,7},4}};

bool poss(vi &s, int n){
	bool p1 = false, p = false;
	int k1 = 0, k2 = 0;
	FOR(i,0,n){
		k2 = m[mp(k2, s[i])];
	}
	FOR(i,0,n){
		k1 = m[mp(k1, s[i])];
		FOR(j,0,8){
			if(m[mp(s[i], j)] == k2){
				k2 = j;
				break;
			}
		}
		if(k1 == 1 && k2 == 1)
			p1 = true;
		else if(p1 && k1 == 3 && k2 == 3){
			p = true;
		}
	}
	return p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin >> TC;
  FOR(tc, 0, TC){
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	vi sv(n *x);
	FOR(i,0,n*x){
		sv[i] = p1[s[i%n]];
	}
	bool p = poss(sv, n*x);
	cout << "Case #" << tc+1 << ": ";
	if(p)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
  }
}
