#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

char s[2048];
map<char, int> mp;
int ans[10];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        mp.clear();
        scanf("%s", s);
        for (int i = 0; i < strlen(s); ++i) {
            mp[s[i]]++;
        }
        for (int i = 0; i < 10; ++i) {
            ans[i] = 0;
        }
        ans[0] = mp['Z'];
        ans[2] = mp['W'];
        ans[4] = mp['U'];
        ans[6] = mp['X'];
        ans[8] = mp['G'];
        ans[1] = mp['O'] - ans[0] - ans[2] - ans[4];
        ans[3] = mp['T'] - ans[2] - ans[8];
        ans[5] = mp['F'] - ans[4];
        ans[7] = mp['S'] - ans[6];
        ans[9] = mp['I'] - ans[5] - ans[6] - ans[8];
        printf("Case #%d: ", ++cas);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < ans[i]; ++j) {
                printf("%d", i);
            }
        }
        puts("");
    }
    return 0;
}