#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

typedef long long LL;
#define CLR(a,b) memset(a,b,sizeof(a))
const int N = 1000+5;
char s[N];

void solve()
{
    string ans = "";
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (ans.empty()) {
            ans += s[i];
        } else {
            if (s[i] >= ans[0]) {
                ans = s[i] + ans;
            } else {
                ans += s[i];
            }
        }
    }
    printf("%s\n", ans.c_str());
}

int main()
{
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%s", s);
        solve();
    }
    return 0;
}