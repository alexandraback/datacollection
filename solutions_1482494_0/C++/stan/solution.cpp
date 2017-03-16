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
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    forn(it, tc) {
        cout << "Case #" << it + 1 << ": ";
        int n; cin >> n;
        vi a(n), b(n);
        forn(i, n) {
            cin >> a[i] >> b[i];
        }
        vi used(n);
        int stars = 0;
        int ans = 0;
        int cnt = 0;
        while (true) {
            bool f = false;
            forn(i, n) {
                if (used[i] != 2 && b[i] <= stars) {
                    stars += 2 - used[i];
                    ++ans;
                    used[i] = 2;
                    ++cnt;
                    f = true;
                }
            }
            if (cnt == n) break;
            if (f) continue;
            int mini = -1;
            forn(i, n) {
                if (used[i] == 0 && stars >= a[i]) {
                    if (mini == -1 || (b[mini] < b[i])) mini = i;
                }
            }
            if (mini == -1) {
                ans = -1;
                break;
            }
            used[mini] = 1;
            stars++;
            ans++;
        }
        if (ans == -1) {
            cout << "Too Bad" << endl;
        } else {
            cout << ans << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    readData();
    solve();
    return 0;
}
