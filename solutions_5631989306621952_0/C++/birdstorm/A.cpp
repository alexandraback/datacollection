#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T; cin>>T;
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" << cs << "...\n";
        printf("Case #%d: ", cs);
        scanf("%s", s);
        int n = strlen(s);
        string ans = "";
        for(int i = 0; i < n; i ++) {
            string tmp1 = s[i] + ans;
            string tmp2 = ans + s[i];
            if(tmp1 < tmp2) {
                ans = tmp2;
            } else {
                ans = tmp1;
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
