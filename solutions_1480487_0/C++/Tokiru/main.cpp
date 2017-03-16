#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <assert.h>

using namespace std;

const int MN = 242;

int n;
int result [MN];


int main()
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int T;
    in >> T;
    for (int t=1; t <= T; t++) {
        in >> n;
        double sum = 0;
        for (int i=1; i <= n; i++) {
            in >> result [i];
            sum += result [i];
        }

        double Sum = sum;

        out << "Case #" << t << ": ";
        for (int i=1; i <= n; i++) {
            double minans = 0;
            double maxans = 1;
            for (int it=0; it < 100; it++) {
                double ans = (maxans + minans) / 2;
                double x = Sum*ans + result [i];
                double sumk = 0;
                for (int j=1; j <= n; j++) {
                    if (i != j) {
                        if (x > result [j]) {
                            sumk += (x - result [j]) / Sum;
                        }
                    }
                }

                if (sumk + ans <= 1) minans = ans; else maxans = ans;
            }
            out << 100*(minans + maxans) / 2;
            if (i != n) out << " ";
        }
        out << endl;
    }
}
