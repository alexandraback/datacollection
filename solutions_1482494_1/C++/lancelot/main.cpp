#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
int n;
bool mk[1053];
struct level
{
    int a, b;
} num[N];

bool cmp(level x,level y)
{
    if (x.b == y.b) return x.a > y.a;
    return x.b < y.b;
}
int lancelot()
{
    sort(num, num + n, cmp);
    int tmp = 0, res = 0;
    memset(mk, 0, sizeof (mk));
    for (int i = 0; i < n; i++)
    {
        while (tmp < num[i].b)
        {
            bool f = false;
            for (int j = n - 1; j >= i; j--)
            {
                if (!mk[j] && tmp >= num[j].a)
                {
                    f = true;
                    tmp += 1;
                    res++;
                    mk[j] = 1;
                    break;
                }
            }
            if (!f)
            break;
        }
        if (tmp >= num[i].b)
        {
            tmp += 1;
            if (!mk[i])
            {
                tmp += 1;
                mk[i]=1;
            }
        }
        else
        return -1;
    }
    return res + n;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    //freopen("bs.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for (int Cas = 1; Cas <=T; ++Cas)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        scanf("%d%d", &num[i].a, &num[i].b);
        printf("Case #%d: ", Cas);
        int ans = lancelot();
        if (ans == -1)
        printf("Too Bad\n");
        else printf("%d\n", ans);
    }
}
