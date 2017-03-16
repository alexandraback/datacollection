#include <bits/stdc++.h>

using namespace std;

int k, l, s;
string keys;
string tar;
vector <int> occur;

string str;

void dfs(){
    if(str.length() == s) {
        int occ = 0;
        for(int i = 0 ; str[i] ; i++) {
            int j = 0;
            while(tar[j] && str[i + j] && tar[j] == str[i+j]) {
                j++;
            }
            if(j == tar.length()) {
                occ ++;
            }
        }
        occur.push_back(occ);
        str = str.substr(0, str.length() - 1);
        return;
    }
    for(int i = 0 ; keys[i] ; i++) {
        str += keys[i];
        dfs();
    }
    str = str.substr(0, str.length() - 1);
    return;
}

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t ; cas ++) {
        cin >> k >> l >> s;
        cin >> keys;
        cin >> tar;
        occur.clear();
        str = "";
        dfs();
        int maxv = -1;
        for(int i = 0 ; i < occur.size() ; i++) {
            maxv = max(maxv, occur[i]);
        }

        double ans = 0.0;
        for(int i = 0 ; i < occur.size() ; i++) {
            ans += maxv - occur[i];
        }
        
        printf("Case #%d: %.7f\n", cas, ans / occur.size() + 1e-9);
    }
    return 0;
}
