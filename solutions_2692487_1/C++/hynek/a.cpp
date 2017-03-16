#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
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
#include <string>
#include <utility>
#include <vector>

using namespace std;
const long double PI = acos((-1.0l));
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORD(i,a,b) for(int i=(b)-1; i>=(a); i--)
#define FORV(i,v) for(int i=0; i<(v).size(); i++)
#define FORVD(i,v) for(int i=(v).size()-1; i>=0; i--)
#define FORE(it,c) for (__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define FORED(it,c) for (__typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++)
#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl
#define SIZE(a) ((int)(a).size())
#define CLEAR(a) memset((a),0,sizeof(a))
#define ALL(a) (a).begin(),(a).end()






int main() {
	//freopen("a.in", "r", stdin);
	int t;
	cin >> t;
    FOR(e, 1, t+1)
    {
        int a, n;
        cin >> a >> n;
        vector<int> motes(n);
        REP(i, n) {
            cin >> motes[i];
        }
        sort(ALL(motes));
        int best = n;
        int used = 0;
        REP(i, n) {
            int x = motes[i];
            if(x < a) {
                a += x;
            }
            else {
                int rem = n - i;
                best = min(best, used + rem);
                while(used < best && x >= a) {
                    a += a-1;
                    used++;
                }
                a += x;
            }
        }
        best = min(best, used);
        cout << "Case #" << e << ": " << best << endl;
	}
	return 0;
}

