#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
using namespace std;

void FreeRun(double& v, double& x, double a, double t)
{
    double v1 = v + a * t;
    double distance = (v + v1) / 2 * t;
    x += distance;
    v = v1;
}

double TimeNeeded(double v, double d, double a)
{
    return (sqrt(2*a*d+v*v)-v)/a;
}

int main()
{
    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");
    int T;
    in >> T;
    for (int X = 0; X < T; X++)
    {
        double D;
        int A, N;
        in >> D >> N >> A;
        double *x = new double[N];
        double *t = new double[N];
        double *a = new double[A];
        for (int i = 0; i < N; i++)
        {
            in >> t[i] >> x[i];
        }
        for (int i = 0; i < A; i++)
        {
            in >> a[i];
        }

        for (int i = 0; i < N; i++)
        {            
            if (x[i] >= D)
            {
                N = i + 1;
                double v = (x[i]-x[i-1]) / (t[i]-t[i-1]);
                t[i] = t[i-1] + (D-x[i-1]) / v;
                x[i] = D;
            }
        }

        out << "Case #" << (X+1) << ":" << endl;
        for (int i = 0; i < A; i++)
        {
            cout << i << " ";
            double time = 0, pos = 0, velo = 0;
            for (int j = 0; j < N-1; j++)
            {
                FreeRun(velo, pos, a[i], t[j+1]-t[j]);
                if (pos > x[j+1])
                {
                    pos = x[j+1];
                    velo = (x[j+1]-x[j]) / (t[j+1]-t[j]);
                }
            }
            time = t[N-1];
            if (pos < D)
            {
                time += TimeNeeded(velo, D-pos, a[i]);
            }
            out.precision(12);
            out << time << endl;
        }
        delete [] x;
        delete [] t;
        delete [] a;
    }
    in.close();
    out.close();
    return 0;
}
