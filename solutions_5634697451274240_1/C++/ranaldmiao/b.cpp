#include <bits/stdc++.h>
using namespace std;
int TC, N, ans;
char str[1050];
int main () {
    scanf("%d", &TC);
    for (int T = 1; T <= TC; ++T) {
        scanf("%s", str);
        N = strlen(str);
        ans = 1;
        for (int i = 1; i < N; ++i) {
            if (str[i] != str[i-1]) ++ans;
        }
        if (str[N-1] == '+') --ans;
        printf("Case #%d: %d\n", T, ans);
    }
}