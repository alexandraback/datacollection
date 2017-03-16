#include <iostream>
#include <cstring>
#include <fstream>
#include <list>
#include <cmath>
#include <iomanip>

using namespace std;



int main()
{
    ifstream f("b.in");
    ofstream g("b.out");
    int T, n, A;
    double d, x[2000], ts[2000], a;
    f >> T;
    for(int t = 1; t <= T; ++t)
    {
        f >> d >> n >> A;
        for(int i = 0; i < n; ++i)
        {
            f >> ts[i] >> x[i];
        }
        g << "Case #" << t <<":\n";
        for(int i = 0; i < A; i++)
        {
            f >> a;
            g << fixed << setprecision(10);
            if(n == 1)
            {
                g << sqrt(2.*d/a) << "\n";
            }
            else if(n == 2)
            {
                double v = (x[1] - x[0]) / ts[1];
                if(v*v + 2 * a * x[0] >= 0)
                {
                    double tt;
                    tt = (v - sqrt(v*v + 2 * a * x[0])) / a;
                    if(tt <= 0) {
                        tt = (v + sqrt(v*v + 2 * a * x[0])) / a;
                        cout << t << endl;
                    }
                    else {cout << v << " " << a << " " << x[0] << endl; }

                    double xx = x[0] + v * tt;
                    if(xx >= d)
                        g << sqrt(2.*d/a) << "\n";
                    else
                    {
                        g << tt + (d - xx) / v << "\n";
                    }
                }
                else g << sqrt(2.*d/a) << "\n";
            }
        }
    }
    f.close();
    g.close();
    return 0;
}
