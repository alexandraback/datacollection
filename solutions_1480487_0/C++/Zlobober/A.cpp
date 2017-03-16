#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 250;

double A[N];

void go()
{
    int n;
    cin >> n;
    double S = 0;
    for (int i = 0; i < n; i++)
        cin >> A[i], S += A[i];
    for (int i = 0; i < n; i++)
    {
        double a = 0, b = 1;
        swap(A[i], A[0]);
        for (int it = 0; it < 100; it++)
        {
            double t = (a + b) / 2;
            double u = A[0] + S * t;
            double s = 0;
            for (int i = 1; i < n; i++)
                s += max(0.0, (u - A[i]) / S);
            if (s + t > 1)
                b = t;
            else
                a = t;
        }
        cout << 100 * a << ' ';
        swap(A[i], A[0]);
    }
}

int main()
{
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        go();
        cout << endl;
    }
}
