#include <bits/stdc++.h>

using namespace std;
                                                                          	
#define forn(i, x, n) for (int i = int(x); i <= int(n); ++i)
#define for1(i, n, x) for (int i = int(n); i >= int(x); --i)
#define file ""     
#define F first                       
#define S second 
#define pb push_back   

typedef long long ll; 
typedef pair <ll, ll> PII;
typedef double ld;
                                                                                          
const int N = 2e6; 
const int INF = 1e9 + 9;
const int B = 1e9 + 7;

int n;    

int main () {
#ifdef machine42
	freopen (file"in", "r", stdin);
	freopen (file"out", "w", stdout);
#endif		
	ios_base :: sync_with_stdio (0);
	cin.tie(0);

	int tests;
	cin >> tests;
	forn(test, 1, tests) {
		cout << "Case #" << test << ": ";
		string s;
		cin >> s; 
		string res;
		res.pb(s[0]);
		forn(i, 1, s.size() - 1)
			if (s[i] >= res[0])
				res.insert(0, string(1, s[i]));
			else
				res.pb(s[i]);	
		cout << res << "\n";
	}
	
	return 0;         	
}
