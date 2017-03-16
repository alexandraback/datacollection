#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int T, J, P, S, K;
struct outfit_T
{
    int j, p, s;
    outfit_T() {}
    outfit_T(int j, int p, int s): j(j), p(p), s(s) {}
};
std::vector<outfit_T> os;
inline int bits(int x)
{
    int ans = 0;
    while (x)
    {
        if (x & 1)
            ans++;
        x >>= 1;
    }
    return ans;
}
bool check(int x)
{
    static int jp[4][4], ps[4][4], js[4][4];
    memset(jp, 0, sizeof(jp));
    memset(ps, 0, sizeof(ps));
    memset(js, 0, sizeof(js));
    for (int i = 0; i < J * P * S; i++)
        if (x & (1 << i))
        {
            int j = os[i].j;
            int p = os[i].p;
            int s = os[i].s;
            jp[j][p] ++;
            ps[p][s] ++;
            js[j][s] ++;
            if (jp[j][p] > K ||  ps[p][s] > K ||  js[j][s] > K)
                return false;
        }
    return true;
}
int main()
{
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++)
    {
        os.clear();
        scanf("%d%d%d%d", &J, &P, &S, &K);
        for (int j = 1; j <= J; j++)
            for (int p = 1; p <= P; p++)
                for (int s = 1; s <= S; s++)
                    os.push_back(outfit_T(j, p, s));
        int ans = 0;
        cerr << "Case: " << TT << endl;
        cerr << "os.size: " << os.size() << endl;
        for (int i = 0; i < (1 << os.size()); i++)
            if (bits(i) > bits(ans) && check(i))
                ans = i;
        // printf("%u\n", os.size());
        printf("Case #%d: %d\n", TT, bits(ans));
        // printf("%x\n", ans);
        for (int i = 0; i < J * P * S; i++)
            if (ans & (1 << i))
                printf("%d %d %d\n", os[i].j, os[i].p, os[i].s);
    }
    return 0;
}