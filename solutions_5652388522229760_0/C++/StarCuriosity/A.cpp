#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}


inline void func(vector<int>& a, long long val)
{
    string s = to_string(val);
    for(char c : s)
        a[c - '0'] = 1;
}

void solve(int numtest)
{
    cout << "Case #" << numtest << ": ";
    long long n;
    cin >> n;
    if (n == 0)
        return void(cout << "INSOMNIA\n");

    vector<int> mask(10, 0);
    int tmp = 0;

    while(count_if(mask.begin(), mask.end(), [](int x){return x == 1;}) < 10)
        func(mask, (++tmp) * n);

    cout << n * tmp << '\n';
}

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int i = 1; i <= T; ++i)
        solve(i);

}

