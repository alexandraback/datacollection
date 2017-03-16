#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int t, n, s, l, l1, l2, j;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int ans = 0;
        cin >> n >> s >> l;
        l1 = l * 3 - 2; l2 = l * 3 - 4;
        if (l2 <= 0) {
            if (l > 0) l2 = l; else
            if (l == 0) l2 = 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &j);
            if (j >= l1) ans++; else
                if (s > 0 && j >= l2) {ans++; s--;}
        }
        cout << "Case #" << tt + 1 << ": " << ans << endl;
    }
}
