#include <algorithm>
#include <iostream>
using namespace std;

int a[111];

int main()
{
    int T, N, S, p;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N >> S >> p;
        for (int i = 0; i < N; ++i) cin >> a[i];
        sort(a, a + N);

        int res = 0;
        for (int i = 0; i < N; ++i) {
            int r = p + 2 * max(p - 1, 0);
            if (r <= a[i]) { ++res; continue; }
            if (S > 0) {
                r = p + 2 * max(p - 2, 0);
                if (r <= a[i]) { ++res; --S; }
            }
        }

        cout << "Case #" << (t + 1) << ": " << res << endl;
    }
    return 0;
}
