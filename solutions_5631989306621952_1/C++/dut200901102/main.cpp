#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;
const int inf = ~0U >> 1;
const int mod = 1e9 + 7;

char s[N], ans[N];

int main() {
    int _, _cas = 0;
    for(scanf("%d", &_); _--; ) {
        printf("Case #%d: ", ++_cas);
        scanf("%s", s);
        int len = strlen(s);
        int L = 0, R = len - 1;
        for(int i = len - 1; i >= 0; --i) {
            bool flag = false;
            for(int j = 0; j < i; ++j) {
                if(s[j] > s[i]) flag = true;
            }
            if(flag) ans[R--] = s[i];
            else ans[L++] = s[i];
        }
        ans[len] = 0;
        cout << ans << endl;
    }
    return 0;
}