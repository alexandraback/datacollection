#include <bits/stdc++.h>
using namespace std;

//E F G H I N O R S T U V Z

string s[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR" ,
"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[26];
vector<int> ret;
bool dfs(int dep, int depth)
{
    bool flag = false;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] > 0) {
            flag = true;
            break;
        }
    }
    if(!flag) {
        for(int i = 0; i < ret.size(); i++) {
            cout<<ret[i];
        }
        cout << endl;
        return true;
    }
    if(flag) {
        int c[26];
        memset(c, 0, sizeof(c));
        for(int i = 0; i < s[dep].length(); i++) {
            c[s[dep][i] - 'A']++;
        }
        bool f = true;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] < c[i]) {
                f = false;
                break;
            }
        }
        if(f) {
            for(int i = 0; i < 26; i++) {
                cnt[i] -= c[i];
            }
            ret.push_back(dep);
            if(dfs(dep, depth + 1)) {
                return true;
            }
            ret.pop_back();
            for(int i = 0; i < 26; i++) {
                cnt[i] += c[i];
            }
        }
        if(dep < 9 && dfs(dep + 1, depth + 1))
            return true;
        return false;
    }
}
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, ca = 1;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < str.length(); i++) {
            cnt[str[i] - 'A'] ++;
        }
        ret.clear();
        printf("Case #%d: ", ca++);
        dfs(0, 0);
    }
    return 0;
}
