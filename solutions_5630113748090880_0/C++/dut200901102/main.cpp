#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1010;
const int inf = ~0U >> 1;
const int mod = 1e9 + 7;

int n;
map<int, int> cnt;
int main() {
    int _, _cas = 0;
    for(scanf("%d", &_); _--; ) {
        printf("Case #%d: ", ++_cas);
        cnt.clear();
        scanf("%d", &n);
        for(int i = 0; i < 2 * n - 1; ++i) 
            for(int j = 0, x; j < n; ++j)
                scanf("%d", &x), cnt[x]++;
            
        vector<int> ans;
        for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
            if(it->second & 1) {
                ans.push_back(it->first);
            }
        }
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}