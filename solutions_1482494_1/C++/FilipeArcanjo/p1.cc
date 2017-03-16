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
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define NDEBUG
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

int solve(int n, const vector<int> &ns1, const vector<int> &ns2)
{
	vector<int> g(n);
	int sol = 0;
	int s = 0;
	bool ok = false;
	int c2 = 0;
	do {
		ok = false;
		if (!ok) FORN(j, 0, n) {
			if (s >= ns2[j] and g[j] == 0) {
				WRITE("A");
				WATCH(j);
				s += 2;
				g[j] = 2;
				c2++;
				ok = true;
				sol++;
				break;
			}
		}
//(g[j] == 0 && s >= ns1[j]) or 
		if (!ok) FORN(j, 0, n) {
				if (g[j] == 1 && s >= ns2[j]) {
				WRITE("B");
				WATCH(j);
					g[j] = 2;
					c2++;
					s += 1;
					sol++;
					ok = true;
					break;
				}
		}
		if (!ok) {
			int x = -1;
			FORN(j, 0, n) {
				if (g[j] == 0 && s >= ns1[j]) {
					if (x == -1) x = j;
					if ( ns2[j] > ns2[x] ) x = j;
				}
			}
			if (x != -1)  {
				WRITE("C");
				WATCH(x);
				g[x] = 1;
				s+=1;
				sol++;
				ok=true;
			}
		}

	} while (ok);

	if (c2 == n) 
	return sol;
	return INT_MAX;
}

int main(){
	//Descomente para acelerar cin
	//ios::sync_with_stdio(false);
	int ntc;
	cin >> ntc;
	FORN(tc, 0, ntc) {
		int n;
		cin >> n;
		vector<int> ms1(n);
		vector<int> ms2(n);
		FORN(i, 0, n) cin >> ms1[i] >> ms2[i];
		int ans = solve(n, ms1, ms2);
		cout << "Case #" << (tc+1) << ": ";
		if (ans == INT_MAX)
			cout << "Too Bad" << endl; 
		else
			cout << ans << endl;
	}
	
}
