#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

bool possible(const vector<vector<int> >& lawn, int n, int m)
{
	FORN(i, 0, n) FORN(j, 0, m) if(lawn[i][j] < 1 or lawn[i][j] > 100) return false;
	vector<bool> forbiddenrow(n);
	vector<bool> forbiddencolumn(m);
	for(int h = 100; h > 0; h--){
		FORN(i, 0, n){
			FORN(j, 0, m){
				if(lawn[i][j] == h){
					if(forbiddenrow[i] and forbiddencolumn[j]){
						return false;
					}
				}
			}
		}

		FORN(i, 0, n){
			FORN(j, 0, m){
				if(lawn[i][j] == h){
					forbiddenrow[i] = true;
					forbiddencolumn[j] = true;
				}
			}
		}
	}
	return true;
}


int main(){
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<vector<int> > lawn(n, vector<int>(m));
		FORN(i, 0, n) FORN(j, 0, m) scanf("%d", &lawn[i][j]);
		string answer = possible(lawn, n, m) ? "YES" : "NO";
		cout << "Case #" << (tc + 1) << ": " << answer << endl;
	}
}
