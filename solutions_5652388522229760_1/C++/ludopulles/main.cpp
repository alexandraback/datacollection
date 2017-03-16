#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
//    for (int tc = 0; tc <= 1000 * 1000; tc++) {
//        n = tc;

        if (n == 0) {
            cout << "Case #" << tc << ": INSOMNIA" << endl;
        } else {
            bool used[10] = {};
            int rem = 10;

            ll num = n;
            while (rem > 0) {
                ll cur = num;
                while (cur > 0) {
                    if (!used[cur % 10]) {
                        used[cur % 10] = true;
                        rem--;
                    }
                    cur /= 10;
                }
                num += n;
            }

//            if ((tc & 4095) == 0)
            cout << "Case #" << tc << ": " << (num - n) << endl;
        }

    }
    return 0;
}
