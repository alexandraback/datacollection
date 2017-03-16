#include <cstdint>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N;
int F[1000];
int link[1000];
int circle[1000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> F[i];
        F[i]--;
    }

    memset(link, 0, sizeof(link));
    memset(circle, 0, sizeof(circle));
    for (int i = 0; i < N; i++) {
        int min_f = i;
        int len = 1;
        int curr = i;
        while (true) {
            if (F[F[curr]] == curr) {
                link[curr] = max(len, link[curr]);
                break;
            }
            if (F[curr] == i) {
                // big circle
                circle[min_f] = len;
                break;
            }
            if (len > N) break;
            curr = F[curr];
            len++;
            min_f = min(curr, min_f);
        }
    }
    int max_circle = 0;
    for (int i = 0; i < N; i++) max_circle = max(max_circle, circle[i]);
    int sum_link = 0;
    for (int i = 0; i < N; i++) {
        if (F[F[i]] == i && i < F[i]) {
            sum_link += link[i] + link[F[i]];
        }
    }
    int ans = max(max_circle, sum_link);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
