//GCJ 2013 1A_C
//#include <iostream>
#include <fstream>

#define A(i) (((i)/16)+2)
#define B(i) ((((i)/4)%4) + 2)
#define C(i) (((i)%4)+2)

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int v[64][11];

void solve()
{
    int r, n, m, k;
    cin >> r >> n >> m >> k;
    for (int i = 0; i < r; ++i) {
        int w[7], good[64];
        for (int j = 0; j < 7; ++j)
            cin >> w[j];
        for (int j = 0; j < 64; ++j) {
            good[j] = 1;
            for (int p = 0; p < 7; ++p) {
                int flag = 0;
                for (int q = 0; q < 11; ++q) {
                    if (v[j][q] == w[p]) {
                        flag = 1;
                        break;
                    }
                }
                good[j] &= flag;
            }
            if (good[j]) {
                cout << A(j) << B(j) << C(j) << endl;
                break;
            }
        }
    }
}

void init()
{
    for (int i = 0; i < 64; ++i) {
        int a, b, c;
        a = A(i), b = B(i), c = C(i);
        int *p = v[i];
        p[0] = 1;
        p[1] = a;
        p[2] = b;
        p[3] = c;
        p[4] = a*a;
        p[5] = b*b;
        p[6] = c*c;
        p[7] = a*b;
        p[8] = a*c;
        p[9] = b*c;
        p[10] = a*b*c;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << t << ":\n";
        init();
        solve();
    }

    return 0;
}
