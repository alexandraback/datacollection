#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    FILE * pFile = freopen("B-small-attempt0.in", "r", stdin);
    FILE * pFile2 = freopen("B-small-attempt0.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int no = 1; no <= t; no++)
    {
        int n, s, p, ti[100];
        scanf("%d %d %d", &n, &s, &p);
        for (int i = 0; i < n; i++)
            scanf("%d", &ti[i]);
        sort(ti, ti+n);
        int cnt = 0;
        int i;
        for ( i = n-1; i >= 0; i--)
        {
            if ( (ti[i]+2)/3 >= p ) cnt++;
            else break;
        }
        for (; i >= 0; i--)
        {
            if (s > 0 && ti[i] != 0)
            {
                if ( ti[i] == 3*(p-1) || ti[i] == (3*(p-1)-1) )
                {
                    cnt++;
                    s--;
                }
            }
            else
                break;
        }
        printf("Case #%d: %d\n", no, cnt);
    }
}
