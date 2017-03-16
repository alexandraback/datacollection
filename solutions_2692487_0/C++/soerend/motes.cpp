#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    cin >> t;
    for (int c = 1; c <= t; ++c) {
        long long a;
        cin >> a >> n;
        vector<long long> motes(n);
        vector<int> ops(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> motes[i];
        if (a == 1) {
            cout << "Case #" << c << ": " << n << endl;
            continue;
        }
        sort(motes.begin(), motes.end());
        int o = 0;
        for (int i = 0; i < n; ++i) {
            while (motes[i] >= a) {
                a += a-1;
                ++o;
            }
            a += motes[i];
            ops[i] = o;
        }
        int best = 1000000;
        vector<int> ops2(n);
        for (int i = 0; i < n; ++i) {
            ops2[i] = ops[i] + n - i - 1;
            best = min(best, ops[i] + n - i - 1);
        }
        best = min(best, n);
        cout << "Case #" << c << ": " << best << endl;
    }
}
