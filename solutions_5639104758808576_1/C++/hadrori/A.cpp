#include <bits/stdc++.h>
using namespace std;

int n;
char s[1024];

void solve()
{
        int sum = s[0]-'0', ans = 0;
        for (int i = 1; i < n; i++) {
                if(sum < i) {
                        ans += i-sum;
                        sum = i;
                }
                sum += s[i]-'0';
        }
        printf("%d", ans);
}

void input()
{
        scanf("%d", &n);
        n++;
        scanf("%s", s);
}

int main()
{
        int t; scanf("%d", &t);
        for (int i = 0; i < t; i++) {
                printf("Case #%d: ", i+1);
                input();
                solve();
                puts("");
        }

        return 0;
}
