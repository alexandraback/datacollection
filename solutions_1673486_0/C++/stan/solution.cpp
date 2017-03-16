#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, v.size())
#define pb push_back
#define all(v) v.begin(), v.end()
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;

void require(bool cond, const string& message = "Runtime error")
{
    if (!cond) {
        cerr << message << endl;
        assert(false);
    }
}

void readData()
{
}

void solve()
{
    int tc; cin >> tc;
    cout.precision(10);
    cout << fixed;
    forn(it, tc) {
        cout << "Case #" << it + 1 << ": ";
        int a, b; cin >> a >> b;
        vector<double> p(a);
        forn(i, a) cin >> p[i];
        double ans = b + 2;
        double correctProb = 1.0;
        forn(i, a) {
            ans = min(ans, correctProb * (a - i + b - i + 1) + (1 - correctProb) * (a - i + b - i + b + 2));
            correctProb *= p[i];
        }
        ans = min(ans, correctProb * (b - a + 1) + (1 - correctProb) * (b - a + 1 + b + 1));
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    readData();
    solve();
    return 0;
}
