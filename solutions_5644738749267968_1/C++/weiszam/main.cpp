#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n,howmany;
double p[1005],q[1005];

int rendez(const void *a, const void *b)
{
    if ((*(double*)a)-(*(double*)b) < 0) return -1; return 1;
}

bool jo(int levon)
{
    for (int i = levon+1; i<=n; i++)
    {
        if (p[i]<q[i-levon]) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &howmany); FILE *out = fopen("ki.txt", "w");

    for (int ii = 1; ii<=howmany; ii++)
    {
        //printf("%d\n", ii);
        scanf("%d", &n);
        for (int i = 1; i<=n; i++) scanf("%lf", &p[i]);
        for (int i = 1; i<=n; i++) scanf("%lf", &q[i]);

        qsort(p+1, n, sizeof(double), rendez);
        qsort(q+1, n, sizeof(double), rendez);

        //printf("%.10f\n", p[1]);

        set<double> s; for (int i = 1; i<=n; i++) s.insert(q[i]);

        //printf("%.10f\n", *s.begin());

        int gyoz = 0;
        for (int i = 1; i<=n; i++)
        {
            set<double>::iterator it = s.lower_bound(p[i]);
            //printf("%f\n", *it);
            if (it == s.end()) gyoz++; else s.erase(it);
        }

        int veszt = 0;
        while (!jo(veszt)) veszt++;

        printf("Case #%d: %d %d\n", ii, n-veszt, gyoz);
        fprintf(out, "Case #%d: %d %d\n", ii, n-veszt, gyoz);
    }
    return 0;
}
