#include <iostream>

using namespace std;

double ti(double c, double f, double x, int n)
{
    double s = 2;
    double r = 0;

    for (int i=0; i<n; i++)
    {
        r += c / s;
        s += f;
    }

    r += x / s;

    return r;
}

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        double c, f, x;
        cin >> c >> f >> x;

        int low = 0;
        int high = 1<<17;

        for (; low + 2 < high; )
        {
            int m1 = (low * 2 + high) / 3;
            int m2 = (low + high * 2) / 3;

            double f1 = ti(c, f, x, m1);
            double f2 = ti(c, f, x, m2);

            if (f1 < f2)
                high = m2;
            else
                low = m1;
        }

        cout.setf(ios::fixed);
        cout.precision(12);
        cout << "Case #" << tt << ": " << min(ti(c, f, x, low), ti(c, f, x, low+1)) << endl;
    }
    return 0;
}
