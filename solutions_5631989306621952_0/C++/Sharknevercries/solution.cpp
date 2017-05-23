#include<bits\stdc++.h>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        string s;
        deque<char> ans;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (ans.size() == 0)
                ans.push_back(s[i]);
            else if (s[i] >= ans.front())
                ans.push_front(s[i]);
            else
                ans.push_back(s[i]);
        }
        printf("Case #%d: ", c++);
        for (int i = 0; i < ans.size(); i++)
            printf("%c", ans[i]);
        putchar('\n');
    }
    return 0;
}