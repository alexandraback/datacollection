#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;

template <class T>
void printAnswer(const vector<T> ans)
{
    int i = 1;
    for (const auto& x : ans) {
        cout << "Case #" << i << ": " << x << endl;
        ++i;
    }
    return;
}


ll str2long(const string s)
{
    ll ans = 0;
    for (const auto& c : s)
        ans = 10 * ans + (c - '0');
    return ans;
}

bool match(ll x, string s)
{
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != '?' && (x % 10 != (s[i] - '0')))
            return false;
        x /= 10;
    }
    return x == 0;
}


pair<long, long> solve_simple(string s1, string s2)
{
    ll aBest = 0, bBest = 0;
    ll difBest = 9000000000000000000;
    for (ll a = 0; a < 1000; ++a) {
        if (!match(a, s1))
            continue;
        for (ll b = 0; b < 1000; ++b) {
            if (!match(b, s2))
                continue;
            if (abs(a - b) < difBest) {
                aBest = a, bBest = b;
                difBest = abs(a - b);
            }
        }
    }
    return mp(aBest, bBest);
}


string printAsTemplate(string s, ll x)
{
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '?') {
            s[i] = '0' + x % 10;
        }
        x /= 10;
    }
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        string s1, s2;
        cin >> s1 >> s2;
        auto ans = solve_simple(s1, s2);
        s1 = printAsTemplate(s1, ans.first);
        s2 = printAsTemplate(s2, ans.second);
        printf("Case #%d: %s %s\n", t, s1.c_str(), s2.c_str());
    }

    return 0;
}