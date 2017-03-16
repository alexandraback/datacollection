#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 20001000;
bool v[maxn];
int buf[maxn];
int ind[maxn];
int group_count = 0;

void prepare() {
    int buf_ind = 0;
    for (int i = 1; i < maxn; ++i)
        if (!v[i]) {
            v[i] = true;
            int len = 1;
            int ct = 1;
            while (ct * 10 <= i) {
                ++len;
                ct *= 10;
            }
            ind[group_count++] = buf_ind;
            int now = buf_ind;
            buf[buf_ind++] = i;
            int nn = i;
            for (int j = 0; j < len; ++j) {
                nn = nn % ct * 10 + nn / ct;
                if (nn < maxn && !v[nn]) {
                    v[nn] = true;
                    buf[buf_ind++] = nn;
                }
            }
        }
    ind[group_count] = buf_ind;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    prepare();
    int T;
    cin >> T;
    for (int cc = 1; cc <= T; ++cc)
    {
        int lower, upper;
        long long ans = 0;
        cin >> lower >> upper;
        for (int i = 0; i < group_count && buf[ind[i]] <= upper; ++i) {
            long long cnt = 0;
            for (int j = ind[i]; j < ind[i+1]; ++j)
                if (buf[j] <= upper && buf[j] >= lower) ++cnt;
            ans += cnt * (cnt - 1) / 2;
        }
        cout << "Case #" << cc << ": " << ans << endl;
    }
        
    return 0;
}
