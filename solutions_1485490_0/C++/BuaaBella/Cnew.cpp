#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
struct Seq
{
    long long num;
    int x;
}a[110],b[110];

void init()
{
    if (n == 2)
    {
        if (a[1].x == a[2].x)
        {
            a[1].num += a[2].num;
            n--;
        }
    }else if (n == 3)
    {
        if (a[1].x == a[2].x)
        {
            a[1].num += a[2].num;
            a[1].x = a[2].x;
            if (a[1].x == a[3].x)
            {
                a[1].num += a[3].num;
                a[1].x = a[3].x;
                n = 1;return;
            }else{
                a[2] = a[3];
                n = 2;
            }
        }else
        {
            if (a[2].x == a[3].x)
            {
                a[2].num += a[3].num;
                a[2].x = a[3].x;
                n = 2;
            }
        }
    }
}
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data1.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int ca = 1; ca <= T; ca++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; ++i)
            scanf("%lld%d",&a[i].num,&a[i].x);
        for (int i = 1; i <= m; ++i)
            scanf("%lld%d",&b[i].num,&b[i].x);
        init();

        long long ans = 0;
        long long tmp = 0;
        long long res = 0;
        if (n == 1)
        {
            for (int i = 1; i <= m; ++i)
            {
                if (a[1].x == b[i].x)
                    tmp += b[i].num;
            }
            ans = min(a[1].num,tmp);
        }else if (n == 2)
        {
            res = 0;
            for (int i = 0; i <= m; ++i)
            {
                tmp = 0;
                for (int j = 1; j <= i; ++j)
                    if (b[j].x == a[1].x)
                        tmp += b[j].num;
                res += min(tmp,a[1].num);
                tmp = 0;
                for (int j = i + 1; j <= m; ++j)
                    if (b[j].x == a[2].x)
                        tmp += b[j].num;
                res += min(tmp,a[2].num);
                ans = max(ans,res);
            }
        }else
        {
            res = 0;
            for (int s = 0; s <= m + 1; ++s)
                for (int t = s; t <= m + 1; ++t)
                {
                    tmp = 0;res = 0;
                    for (int i = 1; i <= s && i <= m; ++i)
                        if (b[i].x == a[1].x)
                            tmp += b[i].num;
                    res += min(tmp,a[1].num);
                    tmp = 0;
                    for (int i = s + 1; i <= t && i <= m; ++i)
                        if (b[i].x == a[2].x)
                            tmp += b[i].num;
                    res += min(tmp,a[2].num);
                    tmp = 0;
                    for (int i = t + 1; i <= m; ++i)
                        if (b[i].x == a[3].x)
                            tmp += b[i].num;
                    res += min(tmp,a[3].num);
    //printf("%d   %d   %lld\n",s,t,res);
                    ans = max(ans,res);
                }
            if (a[1].x == a[3].x)
            {
                a[1].num += a[3].num;
                a[1].x = a[3].x;
                tmp = 0;
                for (int i = 1; i <= m; ++i)
                {
                    if (a[1].x == b[i].x)
                        tmp += b[i].num;
                }
                res = min(a[1].num,tmp);
                ans = max(res,ans);
            }
        }
        printf("Case #%d: %lld\n",ca,ans);
    }
    return 0;
}
