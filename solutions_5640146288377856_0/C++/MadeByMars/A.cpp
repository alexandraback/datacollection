#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define MP(i,j) make_pair(i,j)
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> PII;

int v[1000005], f[1000005];
int r, c, w, m[16];
template <class T>void up(T&a,T b){if(a<b)a=b;}
template <class T>void down(T&a,T b){if(a>b)a=b;}
int dfs(int now)
{
    int a[11];
    int x = now, s = 0;
    if (v[now]) return f[now];
    memset(a, 0, sizeof(a));
    v[now] = 1;
    for (; x; x /= 3)
    {
        a[++a[0]] = x % 3;
        s += (a[a[0]] == 2);
    }
    if (s == w) return 0;
    int bj = 0;
    for (int i = 1; i + w - 1 <= c; i++)
    {
        int flag = 1;
        for (int j = 1; j <= c; j++)
        {
            if (j >= i && j <= i + w - 1)
            {
                if (a[j] == 1)
                {
                    flag = 0;
                    break;
                }
            }
            else if (a[j] == 2)
                {
                    flag = 0;
                    break;
                }
        }
        if (flag)
        {
            bj = 1;
            break;
        }
    }
    if (!bj) {
        return -10000;
    }
    f[now] = ~0U>>1;
    for (int i = 1; i <= c; i++)
        if (a[i] == 0)
            down(f[now], max(dfs(now + m[i - 1]), dfs(now + m[i - 1] * 2)) + 1);
    return f[now];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    m[0] = 1;
    for (int i = 1; i <= 11; i++)
        m[i] = m[i - 1] * 3;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        scanf("%d%d%d", &r, &c, &w);
        memset(v, 0, sizeof(v));
        memset(f, 0, sizeof(f));
        printf("%d\n", dfs(0));
    }
    return 0;
}
