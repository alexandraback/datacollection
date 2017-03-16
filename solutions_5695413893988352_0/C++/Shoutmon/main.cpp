#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
const int INF = 0x3fffffff;

int strToInt(string str) {
    int sum = 0;
    for(int i = 0; i < str.length(); i++) {
        sum = sum * 10 + str[i] - '0';
    }
    return sum;
}

void DFS(int idx, string &str, string now, set<string> &st) {
    if(idx == str.length()) {
        st.insert(now);
        return;
    }
    if(str[idx] != '?') {
        DFS(idx + 1, str, now + str[idx], st);
    } else {
        for(char i = '0'; i <= '9'; i++) {
            DFS(idx + 1, str, now + i, st);
        }
    }
}

int main() {
//    freopen("B-small.in", "r", stdin);
//    freopen("B-small.out", "w", stdout);
    int T, tcase = 1;
    cin >> T;
    while(T--) {
        string str1, str2;
        cin >> str1 >> str2;
        set<string> st1, st2;
        DFS(0, str1, "", st1);
        DFS(0, str2, "", st2);
        int ans = INF;
        string ans1, ans2;
        for(set<string>::iterator it1 = st1.begin(); it1 != st1.end(); it1++) {
            for(set<string>::iterator it2 = st2.begin(); it2 != st2.end(); it2++) {
                int num1 = strToInt(*it1);
                int num2 = strToInt(*it2);
                if(abs(num2 - num1) < ans) {
                    ans = abs(num2 - num1);
                    ans1 = *it1;
                    ans2 = *it2;
                }
            }
        }
        cout << "Case #" << (tcase++) << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}