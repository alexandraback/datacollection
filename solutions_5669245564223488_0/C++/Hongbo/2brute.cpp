#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int a[15], n;
string s[15];

bool check(string str) {
    int n = str.length();
    bool v[30];
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; i ++)
        if(v[str[i] - 'a']) return false;
        else {
            v[str[i] - 'a'] = true;
            char now = str[i];
            while(str[i + 1] == now && i < n) i ++;
        }
    return true;
}

void work() {
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        a[i] = i;
    for(int i = 0; i < n; i ++) 
        cin >> s[i];
    do {
        string str = "";
        for(int j = 0; j < n; j ++)
            str += s[a[j]];
        ans += check(str);
    }while(next_permutation(a, a + n));
    cout << ans << endl;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++) 
        printf("Case #%d: ", i), work();
    return 0;
}
