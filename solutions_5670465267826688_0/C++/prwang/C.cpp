#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int i64;
const int maxn = 2333333;
char in[maxn];
int in2[maxn], sum[maxn];
bool vis[maxn];
int d[8][8] = 
{ //  1 -1, i -i, j -j, k -k
    { 0, 1, 2, 3, 4, 5, 6, 7 }, //1
    { 1, 0, 3, 2, 5, 4, 7, 6 }, //-1
    { 2, 3, 1, 0, 6, 7, 5, 4 }, //i
    { 3, 2, 0, 1, 7, 6, 4, 5 }, //-i
    { 4, 5, 7, 6, 1, 0, 2, 3 }, //j
    { 5, 4, 6, 7, 0, 1, 3, 2 }, //-j
    { 6, 7, 4, 5, 3, 2, 1, 0 }, //k
    { 7, 6, 5, 4, 2, 3, 0, 1 }, //-k
};
inline bool solve()
{
    i64 l, x; scanf("%lld%lld%s", &l, &x, in);
    //x = ((x - 1) & 31) + 1;
    for (int i = 1; i < x; ++i)
        memcpy(in + i * l, in + (i - 1) * l, l * sizeof(char));
    l = l * x;
    for (int i = 0; i < l; ++i)
        if (in[i] == 'i') in2[i] = 2;
        else if (in[i] == 'j') in2[i] = 4;
        else if (in[i] == 'k') in2[i] = 6;
    int cur = 0;
    for (int i = 0; i < l; ++i) sum[i] = cur = d[cur][in2[i]];
    if (cur != 1) return false;
    vis[l - 1] = false;
    for (int i = l - 2; i >= 0; --i) vis[i] = vis[i + 1] || sum[i] == 6;
    for (int i = 0; i < l - 2; ++i)
        if (vis[i] && sum[i] == 2) return true;
    return false;
}

const char *rsu[] = { "NO", "YES" };
int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        printf("Case #%d: %s\n", i, rsu[solve()]);
}
