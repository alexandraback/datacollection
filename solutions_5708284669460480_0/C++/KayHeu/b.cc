#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define LL long long
using namespace std;
string s1, s2;
int k, l, s;
double ans = 0.0;
int maxn = 0;
void dfs(string now)
{
    if(now.size() == s)
    {
        int cnt = 0;
        for(int i = 0; i <= now.size() - s2.size(); i++)
        {
            int flag = true;
            for(int j = 0; j < s2.size(); j++)
                if(now[i + j] != s2[j])
                {
                    flag = false;
                    break;
                }
            if(flag)
                cnt++;
        }
        //if(cnt == 2)
            //cout << now << endl;
        maxn = max(cnt, maxn);
        double p = 1.0;
        for(int i = 0; i < now.size(); i++)
        {
            p *= (double)1.0 / s1.size();
        }
        ans += cnt * p;
        return ;
    }
    for(int i = 0; i < k; i++)
    {
        dfs(now + s1[i]);
    }
}
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int T, cse = 1;
    scanf("%d", &T);
    while(T--)
    {
        maxn = 0;
        ans = 0.0;
        //memset(alp, 0, sizeof(alp));
        scanf("%d%d%d", &k, &l, &s);
        ans = 0.0;
        if(l <= s)
        {
            cin >> s1 >> s2;
            dfs("");
        }
        //cout << maxn << endl;
        printf("Case #%d: %.8lf\n", cse++, (double)maxn - ans);
    }
    return 0;
}
