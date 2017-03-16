#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        int A, N, res = 0;
        cin >> A >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        res = N;
        sort(v.begin(), v.end());

        if (A > 1) {
            int add = 0;
            for (int i = 0; i < N; i++) {
                if (v[i] < A) A += v[i];
                else {
                    while (A <= v[i]) A += A - 1, add++;
                    A += v[i];
                }
                res = min(res, N - i - 1 + add);
            }
        }

        cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
