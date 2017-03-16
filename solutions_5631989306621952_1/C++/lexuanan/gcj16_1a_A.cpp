#include <bits/stdc++.h>

using namespace std;

char s[1005];

int main() {
    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        scanf("%s", s);
        int n = strlen(s);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && s[i] > s[st.top()]) {
                st.pop();
            }
            st.push(i);
        }
        vector<char> ds;
        while (!st.empty()) {
            ds.push_back(s[st.top()]);
            s[st.top()] = 0;
            st.pop();
        }
        printf("Case #%d: ", nt);
        for (int i = ds.size()-1; i >= 0; i--) printf("%c", ds[i]);
        for (int i = 1; i < n; i++)
            if (s[i] > 0) printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
