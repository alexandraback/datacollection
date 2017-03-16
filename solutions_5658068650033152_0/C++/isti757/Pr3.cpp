#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    for(int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);

        int N, M, K;
        cin >> N >> M >> K;

        int res = K;
        for(int r = 1; r <= N; r++)
            for(int c = 1; c <= M; c++) {
                int ans = r*c+2*r+2*c;
                if(ans >= K)
                    res = min(2*c+2*r, res);
            }

        printf("%d\n", res);
    }

    return 0;
}
