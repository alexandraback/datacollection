//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
int N, J;
int prim[NUM], tot;
void pre()
{
    for(int i = 2; i < NUM; ++i)
    {
        if(prim[i] == 0) prim[tot++] = i;
        for(int j = 0; j < tot && i * prim[j] < NUM; ++j)
        {
            prim[i * prim[j]] = 1;
            if(i % prim[j] == 0) break;
        }
    }
}
LL Random(LL mod)
{
    return 1ll * rand() * rand() % mod * rand() % mod * rand() % mod;
}
set<LL> st;
int ans[20];
int bit[50];
bool check(LL n)
{
    for(int i = N - 1; i >= 0; --i)
    {
        if(n & (1ll << i)) bit[i] = 1;
        else bit[i] = 0;
    }
    for(int b = 2; b <= 10; ++b)
    {
        ans[b] = -1;
        for(int i = 0; i < tot; ++i)
        {
            LL rem = 0;
            for(int j = N - 1; j >= 0; --j)
                rem = (rem * b + bit[j]) % prim[i];
            if(rem == 0 && n != prim[i])
            {
                ans[b] = prim[i];
                break;
            }
        }
        if(ans[b] < 0)
        {
            return false;
        }
    }
    return true;
}
void Output(LL n)
{
    for(int i = N - 1; i >= 0; --i)
    {
        putchar('0' + bit[i]);
    }
    for(int i = 2; i <= 10; ++i)
    {
        printf(" %d", ans[i]);
    }
    puts("");
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
    freopen("C-small.txt", "w", stdout);
#endif
    pre();
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:\n", cas);
        scanf("%d%d", &N, &J);
        LL a = 1ll << (N - 2), b = (1ll << (N - 1)) + 1, x;
        st.clear();
        while(J--)
        {
            while(true)
            {
                x = b + Random(a) * 2ll;
                if(check(x) && st.find(x) == st.end())
                {
                    st.insert(x);
                    Output(x);
                    break;
                }
            }
        }
    }
    return 0;
}
