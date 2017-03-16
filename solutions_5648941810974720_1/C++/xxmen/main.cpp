#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int sum[100];
int ans[10];
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t, Case = 0;
    cin>>t;
    while (t--)
    {
        printf("Case #%d: ", ++Case);
        string s;
        cin>>s;
        int len = (int)s.length();
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < len; i++)
        {
            sum[s[i]]++;
        }
        ans[0] = sum['Z'];
        ans[2] = sum['W'];
        ans[4] = sum['U'];
        ans[5] = sum['F'] - ans[4];
        ans[6] = sum['X'];
        ans[7] = sum['V'] - ans[5];
        ans[8] = sum['G'];
        ans[9] = sum['I'] - ans[8] - ans[6] - ans[5];
        ans[3] = sum['H'] - ans[8];
        ans[1] = sum['N'] - ans[7] - 2 * ans[9];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < ans[i]; j++)
                printf("%d", i);
        printf("\n");
    }
    
    
}