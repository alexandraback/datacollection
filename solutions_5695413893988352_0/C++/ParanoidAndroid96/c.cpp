#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define FILE "file"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const ull ULLINF = numeric_limits<ull>::max();
const double PI = acos(-1.0);

map<string, int> m;
int n;

void solve(string s, int ind)
{
    if(ind == s.size())
        m[s] = abs(atoi(s.substr(0, n).c_str()) - atoi(s.substr(n, n).c_str()));
    else if(isdigit(s[ind]))
        solve(s, ind + 1);
    else
    {
        for(int i = 0; i < 10; i++)
        {
            s[ind] = char(i + '0');
            solve(s, ind + 1);
        }
    }
}

int main()
{
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++)
    {
        string a, b;
        m.clear();
        cin >> a >> b;
        n = a.size();
        solve(a + b, 0);
        int best = INF;
        for(auto k: m)
        {
            if(k.second < best)
                best = k.second, a = k.first.substr(0, n), b = k.first.substr(n, n);
            else if(best == k.second && a > k.first.substr(n, n))
                best = k.second, a = k.first.substr(0, n), b = k.first.substr(n, n);
            else if(best == k.second && a == k.first.substr(0, n) && b > k.first.substr(n, n))
                best = k.second, a = k.first.substr(0, n), b = k.first.substr(n, n);
        }
        cout << "Case #" << tt << ": " << a << " " << b << '\n';
    }
    return 0;
}
