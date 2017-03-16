#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    cin>>t;
    for(int cas = 1; cas <= t; cas++)
    {
        char s[2010];
        cin>>s;
        int num[100];
        int ans[10];
        memset(num,0,sizeof(num));
        int len = strlen(s);
        for(int i = 0; i < len; i++)
            num[s[i]]++;
        ans[0] = num['Z'];
        ans[2] = num['W'];
        ans[4] = num['U'];
        ans[5] = num['F'] - ans[4];
        ans[6] = num['X'];
        ans[7] = num['V'] - ans[5];
        ans[8] = num['G'];
        ans[9] = num['I'] - ans[8] - ans[6] - ans[5];
        ans[3] = num['H'] - ans[8];
        ans[1] = num['N'] - ans[7] - 2 * ans[9];
        printf("Case #%d: ",cas);
        for(int i = 0; i <= 9; i++)
            for(int j = 0; j < ans[i]; j++)
                printf("%d",i);
        printf("\n");
    }
    return 0;
}
