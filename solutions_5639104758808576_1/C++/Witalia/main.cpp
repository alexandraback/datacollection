#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << (t + 1) << ": ";

        int Smax;
        string s;
        cin >> Smax >> s;
        int sum = 0, ans = 0;
        for (int i = 0; i <= Smax; ++i) {
            int delta = max(0, i - sum);
            ans += delta;
            sum += delta + s[i] - '0';
        }
        cout << ans << endl;
    }

    return 0;
}
