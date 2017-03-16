#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, s, p, res, k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d %d %d", &n, &s, &p);
        int nor = 0, snor = 0;
        if (p >= 2) nor = p * 3 - 2, snor = p * 3 - 4;
        else if (p == 1) nor = snor = 1;
        res = 0;
        for (int j = 0; j < n; j++)
        {
            int t; scanf("%d", &t);
            if (t >= nor) ++res;
            else if (t >= snor && s) --s, ++res;
        }
        printf("Case #%d: %d\n", i, res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
