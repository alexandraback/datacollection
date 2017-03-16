#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        cout << "Case #" << cas + 1 << ": ";
        ll N;
        cin >> N;
        if (N == 0)
        {
            cout << "INSOMNIA\n";
            continue;
        }
        int seen = 0;
        ll cur;
        for (cur = N; ; cur += N)
        {
            ll v = cur;
            while (v)
            {
                seen |= 1 << (v % 10);
                v /= 10;
            }
            if (seen == (1 << 10) - 1)
                break;
        }
        cout << cur << '\n';
    }
}
