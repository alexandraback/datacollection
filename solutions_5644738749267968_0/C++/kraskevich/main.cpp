#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

int readDoulbe()
{
    string s;
    cin >> s;
    int res = 0;
    s = s.substr(2, s.length() - 2);
    while (s.length() < 5)
        s += '0';
    assert(s.length() == 5);
    for (int i = 0; i < 5; i++)
        res = res * 10 + (s[i] - '0');
    return res;
}

void solve(int test)
{
    cout << "Case #" << test << ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        a[i] = readDoulbe();
    for (int i = 0; i < n; i++)
        b[i] = readDoulbe();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans2 = 0;
    int ans1 = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
        while (p < n && b[p] < a[i])
            p++;
        if (p != n) {
            ans2++;
            p++;
        }
    }
    ans2 = n - ans2;
    for (int suf = 0; suf <= n; suf++) {
        bool ok = true;
        for (int i = suf; i < n; i++)
            if (b[i - suf] > a[i])
                ok = false;
        if (ok)
            ans1 = max(ans1, n - suf);
    }
    cout << ans1 << " " << ans2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(7);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    return 0;
}
