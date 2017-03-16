#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int main() {
    int T;
    assert(scanf("%d", &T) != EOF);

    for (int ti = 1; ti <= T; ++ti) {
        long long E, R, N;
        assert(scanf("%lld %lld %lld", &E, &R, &N) != EOF);

        vector<int> v(N);
        for (int i = 0; i < N; ++i)
            assert(scanf("%d", &v[i]) != EOF);

        vector<int> h(N);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (v[j] > v[i]) {
                    h[i] = j;
                    break;
                }
            }
        }
        long long res = 0, e = E;
        for (int i = 0; i < N; ++i) {
            //cout << e << " " << res << endl;
            if (h[i] == 0) {
                res += v[i] * e;
                e = R;
            } else {
                long long remain = e + R * (h[i] - i) - E;
                //cout << "r = " << remain << endl;
                if (remain > 0) {
                    long long spend = min(e, remain);
                    res += v[i] * spend;
                    e += R - spend;
                } else {
                    e += R;
                }
            }
        }
        printf("Case #%d: %lld\n", ti, res);
    }    
    return 0;
}
