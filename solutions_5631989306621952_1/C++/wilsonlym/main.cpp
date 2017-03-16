#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

char str[1005];
char ans[2005];

int main()
{
    freopen("x.in", "r", stdin);
    freopen("x.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf(" %s", str);
        int lt = 1001, rt = 1001;
        ans[lt] = str[0];
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (ans[lt] <= str[i]) ans[--lt] = str[i];
            else                   ans[++rt] = str[i];
        }
        printf("Case #%d: ", cas);
        for (int i = lt; i <= rt; i++)
            printf("%c", ans[i]);
        puts("");
    }
    return 0;
}
