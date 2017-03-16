#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXP = 1000;

vector<int> a;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << (t + 1) << ": ";

        int n;
        cin >> n;
        a.resize(n);
        for (int &i: a) cin >> i;

        int ans = 1e9;
        for (int p = 1; p <= MAXP; ++p) {
            int cur = 0;
            for (int i: a) cur += (i - 1) / p;
            ans = min(ans, cur + p);
        }
        cout << ans << endl;
    }

    return 0;
}
