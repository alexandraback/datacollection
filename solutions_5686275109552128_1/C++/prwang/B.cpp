#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
template<class T> inline void mint(T& a, T b) { if (a > b) a = b; }
template<class T> inline void maxt(T& a, T b) { if (a < b) a = b; }
const int maxn = 2333;
inline int solve()
{
    priority_queue<int> Q;
    int n, t, ans(0x3f3f3f3f); scanf("%d", &n);
    while (n --> 0) scanf("%d", &t), Q.push(t);

    for (int s = 0; ; ++s)
    {
        int k = Q.top(), t = k >> 1; Q.pop();
        mint(ans, k + s); if (ans <= s) break;
        Q.push(t); Q.push(k - t);
    }
    return ans;
}
inline int solve2()
{
    int n, T(0), ans(0x3f3f3f3f); scanf("%d", &n);
    static int A[maxn];
    for (int i = 0; i < n; ++i) scanf("%d", A + i), maxt(T, A[i]);
    for (int t = T; t; --t)
    {
        int add = 0;
        for (int i = 0; i < n; ++i)
            add += max(A[i] / t + !!(A[i] % t) - 1, 0);
        mint(ans, add + t);
    }
    return ans;

}
int main()
{
    int T; scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt)
        printf("Case #%d: %d\n", tt, solve2());

}
