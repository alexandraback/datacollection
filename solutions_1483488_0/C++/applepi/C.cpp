#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
using namespace std;

int tr[10], n, l, r;
set<int> mem;

bool ana (int v, int p)
{
    int er = 0;
    if (tr[p] == 0) return false;
    for (int i = p; i >= 0; i--) er = (er * 10) + tr[i];
    for (int i = n; i > p; i--) er = (er * 10) + tr[i];
    bool cr = (er >= l && er <= r && er > v);
    if (cr)
    {
        if (mem.find(er) != mem.end()) return false;
        mem.insert(er);
        return true;
    }
    else return false;
}

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int kase; scanf("%d", &kase);
    for (int kk = 1; kk <= kase; kk++)
    {
        int res = 0;
        scanf("%d %d", &l, &r);
        for (int i = l; i <= r; i++)
        {
            n = 0; int tt = i;
            mem.clear();
            while (tt) tr[n++] = tt % 10, tt /= 10;
            --n;
            for (int j = 0; j < n; j++) if (ana(i, j)) ++res;
        }
        printf("Case #%d: %d\n", kk, res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
