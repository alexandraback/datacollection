#include <iostream>
#include <cstring>
#include <cstdio>

#define MOD 1000000007

using namespace std;

long long dp[10004][30];
int n;
string s[101];
int mark[101];

long long solve(int mask, int last) {
    if(mask == 0) return 1;
    if(dp[mask][last] != -1) return dp[mask][last];
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(mask&(1<<i)) {
            memset(mark, 0, sizeof(mark));
            if(last == s[i][0]-'a') {
                mark[s[i][0]-'a'] = 1;
                int pos = 0;
                bool flag = true;
                while(s[i][pos]-'a' == last && pos < s[i].size()) pos++;
                for(int j = pos; j < s[i].size();) {
                    int ch = s[i][j]-'a';
                    while(ch == s[i][j]-'a' && j < s[i].size()) {
                        j++;
                    }
                    if(mark[ch]) flag = false;
                    for(int k = 0; k < n; k++) {
                        if(!(mask&(1<<k))) {
                            for(int l = 0; l < s[k].size(); l++) if(s[k][l]-'a' == ch) flag = false;
                        }
                    }
                    mark[ch] = 1;
                }
                if(flag) {
                    ans = (ans + solve(mask^(1<<i), s[i][s[i].size()-1]-'a'))%MOD;
                }
            }
            else {
                int pos = 0;
                bool flag = true;
                for(int j = pos; j < s[i].size();) {
                    int ch = s[i][j]-'a';
                    while(ch == s[i][j]-'a' && j < s[i].size()) {
                        j++;
                    }
                    if(mark[ch]) flag = false;
                    for(int k = 0; k < n; k++) {
                        if(!(mask&(1<<k))) {
                            for(int l = 0; l < s[k].size(); l++) if(s[k][l]-'a' == ch) flag = false;
                        }
                    }
                    mark[ch] = 1;
                }
                if(flag) {
                    ans = (ans + solve(mask^(1<<i), s[i][s[i].size()-1]-'a'))%MOD;
                }
            }
        }
    }
    return dp[mask][last] = ans;
}

int main()
{
    int t;
    freopen("in1.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> t;
    int cs = 0;
    while(t--) {
        cin >> n;
        cs++;
        cout << "Case #" << cs << ": ";
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }

        cout << solve((1<<n)-1, 27) << endl;
    }
}
