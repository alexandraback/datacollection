#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int t, k, c, s;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> k >> c >> s;
        cout << "Case #" << tc << ":";
        for (int i = 1; i <= s; i++) {
            cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}
