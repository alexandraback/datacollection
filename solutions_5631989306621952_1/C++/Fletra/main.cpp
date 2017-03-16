#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp(a,b) make_pair(a,b)
#define F first
#define S second

#define all(x) x.begin(), x.end()
#define sqr(x) ((x)*(x))
#define eps 1e-8
#define inf (int)(1e9+7)
#define infll (ll)(1e18+3)
#define sz(x) ((int)x.size())

typedef long long ll;
typedef  double ld;
typedef vector < ll > vll;
typedef vector < int > vi;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;
typedef int huint;

const ld PI = acosl(-1);




int main() {
#ifdef DEBUG
    freopen("/Users/rzmn/Documents/acm/acm/input.txt", "r", stdin);
    freopen("/Users/rzmn/Documents/acm/acm/output.txt", "w", stdout);
#else
    //freopen("gunman.in", "r", stdin);
    //freopen("gunman.out", "w", stdout);
#endif
    cout.precision(10);
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    
    int Tcase; cin >> Tcase;
    for (int test = 1; test <= Tcase; ++test) {
        string s; cin >> s;
        deque<char> t; t.push_front(s[0]);
        for (int i = 1; i<sz(s); ++i) {
            if (s[i] >= t.front()) t.push_front(s[i]);
            else t.push_back(s[i]);
        }
        
        
        cout << "Case #" << test << ": ";
        while (!t.empty()) {
            cout << t.front(); t.pop_front();
        }
        cout << '\n';
        
    }
    
    
    
    
    
    
#ifdef DEBUG
    cerr << "\n == TIME : " << clock() / ld(CLOCKS_PER_SEC) << " == " << endl;
#endif
}