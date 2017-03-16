#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("output.txt");

    fout.precision(6);
    fout.setf(ios::fixed,ios::floatfield);

    int t = 0;
    fin >> t;
    for (int count = 1; count <= t; ++count) {
        fout << "Case #" << count << ":" << endl;

        double d;
        int n, A;

        fin >> d >> n >> A;

        double t[n], x[n];
        for (int i = 0; i != n; ++i) {
            fin >> t[i] >> x[i];
        }

        for (int j = 0; j != A; ++j) {
            double a, v = 0, s = 0, tt = 0;
            double vx, sx = x[0];
            fin >> a;

            if (n == 1) {
                tt = sqrt(2 * d / a);
            }
            else {
                for (int i = 0; i != n - 1; ++i) {
                    vx = (x[i + 1] - x[i]) / (t[i + 1] - t[i]);
                    double tmpt = ((vx - v) + sqrt((v - vx) * (v - vx) + 2 * a * sx)) / a;
                    if (i != n - 2) {
                        if (t[i] + tmpt >= t[i + 1]) {
                            s += v * (t[i + 1] - t[i]) + a * (t[i + 1] - t[i]) * (t[i + 1] - t[i]) / 2;
                            v += a * (t[i + 1] - t[i]);
                            sx = x[i + 1] - s;
                        }
                        else {
                            v = sqrt(2 * a * (x[i + 1] - s));
                            s = x[i + 1];
                        }
                        tt = t[i + 1];
                    }
                    else {
                        if (t[i] + tmpt >= t[i + 1]) {
                            tt += (sqrt(v * v + 2 * a * (d - s)) - v) / a;
                        }
                        else {
                            double tmp = v * tmpt + a * tmpt * tmpt / 2;
                            if (tmp <= d - s) {
                                tt = t[i] + (d - x[i]) / vx;
                            }
                            else {
                                tt += (sqrt(v * v + 2 * a * (d - s)) - v) / a;
                            }
                        }
                    }
                }
            }
            fout << tt << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
