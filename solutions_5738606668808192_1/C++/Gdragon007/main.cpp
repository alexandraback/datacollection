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
#define MAX 10000010
using namespace std;

int pri[MAX], vis[MAX], cnt;

void get_prime()
{
    for(int i = 2; i <= 10000000; i ++)
    {
        if(!vis[i])
        {
            pri[cnt ++] = i;
        }
        for(int j = 0; j < cnt && i * pri[j] <= 10000000; j ++)
        {
            vis[i *pri[j]] = 1;
            if(i % pri[j] == 0)
            {
                break;
            }
        }
    }
}

char str[110];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    get_prime();
    int t, Case = 0, n, m;
    scanf("%d",&t);
    while(t --)
    {
        Case ++;
        printf("Case #%d: ",Case);
        scanf("%d%d",&n,&m);
        int x = 16;
        int sta = 1<<(x - 2);
        for(int i = 0; i < sta && m; i ++)
        {
            memset(str, 0, sizeof(str));
            for(int j = 0; j < x - 2; j ++)
            {
                if(i&(1<<j))
                {
                    str[j + 1] = '1';
                }
                else
                {
                    str[j + 1] = '0';
                }
            }
            str[0] = str[x - 1] = '1';
            vector<int> divs;
            bool flag = 0;
            for(int k = 2; k <= 10; k ++)
            {
                LL ans = 0;
                for(int j = 0; j < x; j ++)
                {
                    ans *= k;
                    if(str[j] == '1')
                    {
                        ans ++;
                    }
                }
                bool finds = 0;
                for(int j = 0; j < cnt && pri[j] < ans; j ++)
                {
                    if(ans % pri[j] == 0)
                    {
                        finds = 1;
                        divs.push_back(pri[j]);
                        break;
                    }
                }
                if(!finds)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                for(int j = 0; j < n / x; j ++)
                {
                    printf("%s",str);
                }
                for(int j = 0; j < divs.size(); j ++)
                {
                    printf(" %d",divs[j]);
                }
                printf("\n");
                m --;
            }
        }
    }
    return 0;
}
