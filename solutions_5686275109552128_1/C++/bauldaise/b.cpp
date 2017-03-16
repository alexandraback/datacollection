#include <iostream>
#include <fstream>

using namespace std;

int p[10000];
int main()
{
    int t;
    ifstream f("in.in");
    ofstream g("out.out");
    f >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int d;
        f >> d;
        int maxp = 0;
        for (int i = 0; i < d; i++)
        {
            f >> p[i];
            maxp = max(p[i], maxp);
        }
        int ans = 10000;
        for (int i = 1; i <= maxp; i++)
        {
            int res = i;
            for (int j = 0; j < d; j++)
            {
                res += p[j] / i;
                if (p[j] % i == 0) res--;
            }
            ans = min(ans, res);
        }
        g << "Case #" << tt << ": " << ans << endl;
    }
    f.close();
    g.close();

}
