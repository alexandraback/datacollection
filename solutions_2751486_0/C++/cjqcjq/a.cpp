#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <deque>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int32_t N = 1000001;

char A[N];
vector<int32_t> P, S;
int32_t n, l;
bool vol[26];
char v[] = {'a', 'e', 'i', 'o', 'u'};

int32_t main() {
    for (int32_t i = 0; i < 26; i++) {
        vol[i] = true;
    }
    for (int32_t i = 0; i < 5; i++) {
        vol[v[i] - 'a'] = false;
    }
    int32_t cas = 0;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic++) {
        scanf("%s%d", A, &n);
        l = strlen(A);
        A[l] = 'e';
        int32_t s = -1;
        int32_t c = 0;
        P.clear();
        S.clear();
        for (int32_t i = 0; i <= l; i++) {
            if (vol[A[i] - 'a']) {
                c++;
            } else {
                if (c >= n) {
                    P.push_back(i - 1);
                    S.push_back(s + 1);
                }
                c = 0;
                s = i;
            }
        }
        int64_t ans = 0;
        for (int32_t i = 0; i < l; i++) {
            int32_t idx = lower_bound(P.begin(), P.end(), i + n - 1) - P.begin();
            if (idx < P.size()) {
                ans += l - max(i + n - 1, S[idx] + n - 1);
            }
        }
        printf("Case #%d: %lld\n", ic, ans);
    }
    return 0;
}
