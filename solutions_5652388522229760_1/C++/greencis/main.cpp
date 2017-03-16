#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int t, u[10], cnt;
ll n, cur, x;

int main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);

    cin >> t;
    for (int ttt = 1; ttt <= t; ++ttt) {
        cin >> n;
        if (n == 0) { cout << "Case #" << ttt << ": INSOMNIA\n"; continue; }
        for (int j = 0; j < 10; ++j)
            u[j] = 0;
        cur = 0;
        cnt = 0;
        for (int iter = 0; iter < 1000000; ++iter) {
            cur += n;
            x = cur;
            while (x) {
                cnt += u[x % 10] ^ 1;
                u[x % 10] = 1;
                x /= 10;
            }
            if (cnt >= 10)
                break;
        }
        cout << "Case #" << ttt << ": " << cur << "\n";
    }

    return 0;
}
