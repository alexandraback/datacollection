#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <assert.h>

using namespace std;

const int MN = 242;

int a [MN];
int n;

ifstream in ("input.txt");
ofstream out ("output.txt");

int sum (int mask)
{
    int result = 0;
    int num = 1;
    for (int i=1; i <= n; i++) {
        if (mask & num) result += a [i];
        num <<= 1;
    }

    return result;
}

void output (int mask)
{
    int num = 1;
    for (int i=0; i < n; i++) {
        if (mask & num) out << a [i+1] << " ";
        num <<= 1;
    }
    out << endl;
}

int main()
{
    int T;
    in >> T;
    for (int t=1; t <= T; t++) {
        in >> n;
        bool found = false;
        out << "Case #" << t << ": ";
        for (int i=1; i <= n; i++) in >> a [i];
        random_shuffle (a+1, a+n+1);
        for (int m1 = 1; m1 < (1 << n); m1++) {
            if (found) break;
            for (int m2=1; m2 < (1 << n); m2++) {
                if (found) break;
                if ((!(m1 & m2)) && (m1) && (m2)) {
                    if (sum (m1) == sum (m2)) {
                        //cerr << sum (1) << " " << sum (2);
                        out << endl;
                        output (m1);
                        output (m2);
                        found = true;
                    }
                }
            }
        }
    }
}
