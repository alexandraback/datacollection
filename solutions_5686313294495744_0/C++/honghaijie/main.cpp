#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;

int cs = 0;
string s[1010][2];
unordered_map<string, int> strs;
int n;
int ans;

unordered_map<string, int> ss;
void dfs(int step, int cnt) {

    if (ss.size() == strs.size()) {
        if (cnt < ans)
            ans = cnt;
        return;
    }
    if (step == n) return;
    ++ss[s[step][0]];
    ++ss[s[step][1]];
    dfs(step + 1, cnt + 1);
    if (--ss[s[step][0]] == 0) {
        ss.erase(s[step][0]);
    }
    if (--ss[s[step][1]] == 0) {
        ss.erase(s[step][1]);
    }
    dfs(step + 1, cnt);

}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        strs.clear();
        for (int i = 0; i < n; ++i) {
            cin>>s[i][0]>>s[i][1];
            s[i][0] += "##1";
            s[i][1] += "##2";
            if (strs.count(s[i][0]) == 0) {
                strs[s[i][0]] = strs.size();
            }
            if (strs.count(s[i][1]) == 0) {
                strs[s[i][1]] = strs.size();
            }
        }
        ans = 100000;
        dfs(0, 0);
        printf("Case #%d: ",++cs);
        cout<<n - ans<<endl;
    }
    return 0;
}
