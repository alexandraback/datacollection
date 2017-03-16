#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[1005];

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        scanf(" %s", s);
        int n = strlen(s);
        deque<char> d;
        FO(i,0,n) {
            if (d.empty() || s[i] >= d.front()) d.push_front(s[i]);
            else d.push_back(s[i]);
        }
        printf("Case #%d: ", Z);
        for (char c : d) printf("%c", c);
        printf("\n");
    }
}

