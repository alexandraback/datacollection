#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define LL long long
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define zero(x) ((x > +eps) - (x < -eps))
#define MAX 110
using namespace std;

int k, c, s;
LL powk[110];
vector<LL> ans;

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int t, Case = 0;
    scanf("%d",&t);
    while(t --)
    {
        Case ++;
        printf("Case #%d: ",Case);
        scanf("%d%d%d",&k,&c,&s);
        powk[0] = 1;
        for(int i = 1; i <= c; i ++)
        {
            powk[i] = powk[i - 1] * k;
        }
        if(s == k)
        {
            for(int i = 1; i <= s; i ++)
            {
                printf("%d%c",i,i == s ? '\n' : ' ');
            }
            continue;
        }
        if(c * s < k)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        int cnt = 1;
        for(int i = 1; i <= s; i ++)
        {
            if(cnt > k)
            {
                break;
            }
            LL no = 1;
            int re = cnt;
            for(int j = 1; j <= c; j ++)
            {
                no += powk[c - j] * min(k - 1, (re  - 1));
                re ++;
            }
            cnt += c;
            ans.push_back(no);
        }
        for(int i = 0; i < ans.size(); i ++)
        {
            printf("%lld%c",ans[i], i == ans.size() - 1 ? '\n' :' ');
        }
    }
    return 0;
}
