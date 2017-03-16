#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <iomanip>




using namespace std;

const int MAXN = 100;

int T;
double D;
int N, A;
double t[MAXN], x[MAXN];
double a[MAXN];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for(int ncase = 1; ncase <= T; ncase++)
    {
        cout << "Case #"<< ncase << ":" <<endl;
        cin >> D >> N >> A;
        for(int i = 0; i < N; i++)
        {
            cin >> t[i] >> x[i];
        }
        for(int i = 0; i < A; i++)
        {
            cin >> a[i];
        }
        if(N == 1)
        {
            for(int i = 0; i < A; i++)
            {
                double ans = sqrt(D * 2 / a[i]);
                printf("%.7f\n", ans);
            }
            continue;
        }
        double v = (x[1] - x[0]) / (t[1] - t[0]);
//        cout << "V" << v << endl;
        for(int i = 0; i < A; i++)
        {
            double delta = sqrt(double(v * v + 2 * a[i] * ( x[0])));
            double tt = (delta + v) / a[i];
            double maxDist = tt * v + x[0];
            double ans = 0;
            if(maxDist > D)
            {
                ans = sqrt(D * 2 / a[i]);

            }
            else
            {
                ans = tt + (D - maxDist) / v;
            }
            printf("%.7f\n", ans);
        }
    }













    return 0;
}

