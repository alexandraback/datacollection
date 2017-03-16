#include <stdio.h>
#include <algorithm>
using namespace std;

int vals[1234];

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", vals+i);
        sort(vals, vals+n);
        int mx = vals[n-1];
        int best = 2000;
        for (int check = 1; check <= mx; check++)
        {
            int mins = check;
            for (int i = 0; i < n; i++) mins += (vals[i]-1)/check;
            if (mins < best) best = mins;
        }
        printf("Case #%d: %d\n", t, best);
    }
}
