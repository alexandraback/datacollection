#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>

#define maxn 1000000
using namespace std;

char str[1010];
char ans[1010];
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int T;
    scanf("%d\n", &T);
    for (int kase=1;kase<=T;kase++)
    {
        scanf("%s", str);
        int l = strlen(str);
        ans[0] = str[0];
        for (int i=1;i<l;i++)
            if (str[i] < ans[0]) ans[i] = str[i];
            else
            {
                for (int j=i-1;j>=0;j--)
                    ans[j+1] = ans[j];
                ans[0] = str[i];
            }
        ans[l] = '\0';
        printf("Case #%d: %s\n", kase, ans);
    }
    return 0;
}
