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

bool poss3(vi &s, int n, int i1, int i2, int i3){
	int h2 = m[mp(i1, i2)], h1 = m[mp(i2, i3)];
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
		if(k1 == i1 && k2 == h1)
			p1 = true;
		else if(p1 && k1 == h2 && k2 == i3){
			p = true;
		}
	}
	return p;
}

bool poss2(vi &s, int n, int i1, int i2){
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
		if(k1 == i1 && k2 == i2)
			return true;
	}
	return false;
}

int pot(int n, int exp){
	exp %= 4;
	int res = 0;
	FOR(i,0,exp){
		res = m[mp(res,n)];
	}
	return res;
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
	vi sv(n);
	FOR(i,0,n){
		sv[i] = p1[s[i]];
	}
	int block = 0;
	FOR(i,0,n){
		block = m[mp(block, sv[i])];
	}
	bool p = false;

	//first possibility: both cuts are made in one part
	int i1, i2 = 2, i3;
	FOR(p1,0,4){		
		FOR(i,0,8){
			if(m[mp(pot(block,p1),i)] == 1)
				i1 = i;
		}
		FOR(p2,0,4){
			FOR(i,0,8){
				if(m[mp(i,pot(block,p2))] == 3)
					i3 = i;
			}
			if((x-1)%4 == (p1+p2)%4 && x-1 >= p1 + p2){
				if(poss3(sv, n, i1, i2, i3)){
					p = true;
				}
			}
		}
	}

	//second possibility: two blocks are cut
	FOR(p1,0,4){
		FOR(i,0,8){
			if(m[mp(pot(block,p1),i)] == 1)
				i1 = i;
		}
		FOR(p3,0,4){
			FOR(i,0,8){
				if(m[mp(i,pot(block,p3))] == 3)
					i3 = i;
			}
			FOR(p2,0,4){
				FOR(i,0,8){
					FOR(j,0,8){
						if(m[mp(i, m[mp(pot(block,p2),j)])] == 2){
							if((x-2)%4 == (p1+p2+p3)%4 && 
								(x-2) >= p1 + p2 + p3){
								if(poss2(sv, n, i1, i) && 
									poss2(sv, n, j, i3)){
									p = true;}
							}
						}
					}
				}
			}
		}
	}

	cout << "Case #" << tc+1 << ": ";
	if(p)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
  }
}
