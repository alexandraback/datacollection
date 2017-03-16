#include <cstring>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
using namespace std;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int case_num;
    cin >> case_num;
    for (int case_id = 1; case_id <= case_num; case_id++) {
        int ans = 0;
        int a, b;
        cin >> a >> b;
        char buf[64];
        int n = sprintf(buf, "%d", a);
        int e = pow(10, n - 1) + 0.1;

        for (int i = a; i <= b; i++) {
            int x = i;

            int cache[10];
            cache[0] = x;
            int cache_size = 1;

            for (int j = 1; j < n; j++) {
                x = x / 10 + x % 10 * e;
                if (x >= a && x <= b) {
                    int k = 0;
                    for (; k < cache_size; k++) {
                        if (cache[k] == x) {
                            break;
                        }
                    }
                    if (k == cache_size) {
                        cache[cache_size++] = x;
                    }
                }
            }

            ans += cache_size - 1;
        }

        ans /= 2;

        cout << "Case #" << case_id << ": " << ans << endl;
    }

    return 0;
}
