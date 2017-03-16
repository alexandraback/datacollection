#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

char s1[20], s2[20];
int ans = -1;
int n;
string ans1, ans2;

void dfs(int x, string x1, string x2) {
    if(x == n) {
        int val1 = 0, val2 = 0;
        for(int i = 0; i < n; i ++) {
            val1 = val1 * 10 + x1[i] - '0';
            val2 = val2 * 10 + x2[i] - '0';
        }
        int val = (val1 > val2) ? val1 - val2 : val2 - val1;
        if(ans == -1 || ans > val) {
            ans = val;
            ans1 = x1;
            ans2 = x2;
        }
        return ;
    }
    if(s1[x] == '?' && s2[x] == '?') {
        for(int i = 0; i < 10; i ++) {
            for(int j = 0; j < 10; j ++) {
                string nx1 = x1, nx2 = x2;
                nx1.push_back(i+'0');
                nx2.push_back(j+'0');
                dfs(x+1, nx1, nx2);
            }
        }
    } else if(s1[x] == '?') {
        for(int i = 0; i < 10; i ++) {
            string nx1 = x1;
            string nx2 = x2;
            nx1.push_back(i+'0');
            nx2.push_back(s2[x]);
            dfs(x+1, nx1, nx2);
        }
    } else if(s2[x] == '?') {
        for(int i = 0; i < 10; i ++) {
            string nx1 = x1;
            string nx2 = x2;
            nx2.push_back(i+'0');
            nx1.push_back(s1[x]);
            dfs(x+1, nx1, nx2);
        }
    } else {
        string nx1 = x1;
        string nx2 = x2;
        nx2.push_back(s2[x]);
        nx1.push_back(s1[x]);
        dfs(x+1, nx1, nx2);
    }
}

int main() {
    freopen("B.txt", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t ++) {
        scanf("%s%s", s1, s2);
        n = strlen(s1);
        ans = -1;
        dfs(0, "", "");
        printf("Case #%d: ", t);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}