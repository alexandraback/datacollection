#include <bits/stdc++.h>
using namespace std;

int len;
string s, t;
char ch[10];
int now[10];
string ret1, ret2;
int diff;

void dfs(int dep)
{
    if(dep == 2*len) {
        int num1 = 0, num2 = 0;
        string str1 = "", str2 = "";
        for(int i = 0; i < len; i++) {
            num1 = num1 * 10 + now[i];
            str1 += now[i] + '0';
        }
        for(int i = len; i < 2 * len; i++) {
            num2 = num2 * 10 + now[i];
            str2 += now[i] + '0';
        }
        if(abs(num1 - num2) < diff) {
            diff = abs(num1 - num2);
            ret1 = str1;
            ret2 = str2;
        } else if(abs(num1- num2) == diff) {
            if(str1 < ret1 || str1==ret1&&str2<ret2) {
                ret1 = str1;
                ret2 = str2;
            }
        }
        return ;
    }
    if(ch[dep] != '?') {
        now[dep] = ch[dep] - '0';
        dfs(dep + 1);
    } else 
    for(int i = 0; i < 10; i++) {
        now[dep] = i;
        dfs(dep + 1);
    }
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out" ,"w", stdout);
    int T, ca = 1;
    cin >> T;
    while(T--) {
        diff = 1111111;
        cin >> s >> t;
        printf("Case #%d: ", ca++);
        len = s.length();
        for(int i = 0; i < len; i++) {
            ch[i] = s[i];
        }
        for(int i = 0; i < len; i++) {
            ch[len + i] = t[i];
        }
        dfs(0);
        cout << ret1 << " " << ret2 << endl;
    }
    return 0;
}
