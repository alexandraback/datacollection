#include <iostream>
#include <fstream>

#define inf 1000000000
#define eps 1e-10

using namespace std;

ifstream fin ("test.in");
ofstream fout("test.out");

bool chosen[30][30];
int n,m,p,ans,cnt;

double mod(double a, double m)
{
    return a - ((long long)(a/m))*m;
}

struct runner
{
    double v,d,m;
}v[3];

int solve()
{
    fin >> n;

    int h = 1;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i].d >> h >> v[i].m;
    }

    if (n == 1 && h == 2)
    {
        ++n;
        v[n].d = v[1].d;
        v[n].m = v[1].m+1;
    }
    else if (n == 1)
        return 0;

    if (v[1].m > v[2].m)
        swap(v[1],v[2]);

    v[1].v = 360.0/v[1].m;
    v[2].v = 360.0/v[2].m;

    if (v[1].d < v[2].d)
    {
        double t = (v[1].d - v[2].d)/(v[2].v - v[1].v);
        v[1].d = mod(v[1].d + t*v[1].v, 360);
        v[2].d =  v[2].d + t*v[2].v;
        if (v[2].d > 360)
            return 0;
    }

    v[1].d += eps*v[1].v;
    v[2].d += eps*v[2].v;
    v[2].d += 360;

    double t = (v[1].d - v[2].d)/(v[2].v - v[1].v);
    v[2].d = v[2].d + t*v[2].v;
    if (v[2].d > 720)
        return 0;
    else return 1;
}

int main()
{
    int test;
    fin >> test;

    for (int k = 1; k <= test; ++k)
    {
        int ans = solve();

        fout << "Case #" << k << ": " << ans << "\n";
    }
}
