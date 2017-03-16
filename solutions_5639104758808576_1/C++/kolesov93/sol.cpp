#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d\n", &T);

    for (int _t = 1; _t <= T; ++_t) {
        printf("Case #%d: ", _t);

        string s; int tmp; cin >> tmp;
        cin >> s;

        size_t ans = 0;
        size_t done = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            int count = s[i] - '0';
            if (count == 0) continue;

            if (done < i) {
                size_t need = i - done;
                ans += need;
                done += need;
            }
            done += count;
        }

        cout << ans << endl;
    }

    return 0;
}

