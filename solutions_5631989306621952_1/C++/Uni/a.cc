#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;

char s[1024];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int l = strlen(s);
        deque<char> dq;
        dq.push_back(s[0]);
        for (int i = 1; i < l; ++i) {
            if (dq.front() > s[i]) {
                dq.push_back(s[i]);
            } else {
                dq.push_front(s[i]);
            }
        }
        printf("Case #%d: ", ++cas);
        while (!dq.empty()) {
            printf("%c", dq.front());
            dq.pop_front();
        }
        puts("");
        // for (int i = 0; i < l; ++i) {

        // }
    }
    return 0;
}