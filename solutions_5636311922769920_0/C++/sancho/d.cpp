#include <bits/stdc++.h>

using namespace std;

#define forn(i, x, n) for(int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for(int i = int(n); i >= int(x); --i)
#define file ""
#define pb push_back
#define F first
#define S second
#define _bits __builtin_popcountll

typedef long long ll;
typedef pair <ll, ll> PII;

const int N = 2e6;
const int INF = 1e9 + 9;                                           
const int B = 1e9 + 7;
    
int main() {
#ifdef machine42
	freopen(file"in", "r", stdin);
	freopen(file"out", "w", stdout);
#endif
	ios_base :: sync_with_stdio (0);
	cin.tie(0);
                   
    int tests;
    cin >> tests;
    forn(test, 1, tests) {
    	cout << "Case #" << test << ": ";
        int k, c, s;
    	cin >> k >> c >> s;
    	if (s != k) {
    		cout << "IMPOSSIBLE\n";
    		continue;
    	}
    	forn(i, 1, s)
    		cout << i << " ";
    	cout << "\n";	
	}

    return 0;
}
