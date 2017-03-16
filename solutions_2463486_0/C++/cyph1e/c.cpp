#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool is_palin(long long n) {
    long long k = n, m = 0;
    while (k > 0) {
        m = 10 * m + k % 10;
        k /= 10;
    }
    return m == n;
}

int main()
{
    vector<int> xs;
    for (long long i = 0; i <= 10000000; ++i)
        if (is_palin(i) && is_palin(i * i))
            xs.push_back(i * i);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long lo, hi;
        cin >> lo >> hi;
        long long res = upper_bound(xs.begin(), xs.end(), hi) -
                        lower_bound(xs.begin(), xs.end(), lo);
        cout << "Case #" << t << ": " << res << endl;
    }

    return 0;
}

