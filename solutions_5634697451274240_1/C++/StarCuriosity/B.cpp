#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}

int func(const vector<int>& a)
{
    int ans = 0;

    for(int i = 1; i < a.size(); ++i)
        if (a[i - 1] != a[i])
            ++ans;
    if (a.back() == 1)
        ++ans;

    return ans;
}

void solve(int numtest)
{
    cout << "Case #" << numtest << ": ";
    string s;
    cin >> s;
    vector<int> a;
    for(char x : s)
        a.push_back(x == '-');
    cout << func(a) << '\n';
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
        solve(i);
}

