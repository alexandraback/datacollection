//GCJ QB p1

#include <iostream>
#include <cstdio> 
#include <cstring>

using namespace std;

const int MAXN = 220;
int j[MAXN], n;

int main()
{
    freopen("in1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int tci = 1; tci <= tc; tci++)
    {
        cout << "Case #" << tci << ":";
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) { cin >> j[i]; sum += j[i]; }
        for (int i = 0; i < n; i++)
        {
            double s, mid, l = 0.0, r = 1.0;
            while (l < r - 1e-11)
            {
                mid = (l + r) * 0.5;
                s = 0.0;
                for (int k = 0; k < n; k++)
                    s += max((double)(j[i] - j[k]) / sum + mid, 0.0);
                if (s >= 1.0 - 1e-12) r = mid; else l = mid;
            }
            printf(" %.8lf", (l + r) * 50);
        }
        printf("\n");
    }
    return 0;
}
