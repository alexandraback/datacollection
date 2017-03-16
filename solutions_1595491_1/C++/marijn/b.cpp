#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    for (int c = 1; c <= n; c++) {
        int ans = 0;
        int N, S, p;
        scanf("%d %d %d", &N, &S, &p);
        int minneeded = max(0, p+p+p-2);
        int minneededs = max(1, p+p+p-2-2);
        vector<int> t(N);
        for (int i = 0; i < N; i++) {
            int sc;
            scanf("%d", &sc);
            if (sc >= minneeded) ans++;
            else if (S > 0) {
                if (sc >= minneededs) {
                    ans++;
                    S--;
                }
            }
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}