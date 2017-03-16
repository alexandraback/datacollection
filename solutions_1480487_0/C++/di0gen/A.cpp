#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int max_n = 100001;


int main()
{
    ifstream cin ("A-small-attempt0.in");
    ofstream cout("A-small-attempt0.out");
    int t;
    cin >> t;
    cout.precision(7);
    for (int count = 1; count <= t; count++)
    {
        int n;
        double x = 0;
        cin >> n;
        vector <double> s(n), res(n);
        for (int i = 0; i < n; i++)
            cin >> s[i], x += s[i];
        cout << "Case #" << count << ": ";
        for (int i = 0; i < n; i++)
        {
            double l = 0.0, r = 1.0;
            int iter = 70;
            while (iter--)
            {
                  double m = (l + r) / 2.0;
                  double cur = s[i] + m * x, X = x * (1 - m);
                  for (int j = 0; j < n; j++)
                      if (j != i && s[j] < cur)
                         X -= cur - s[j];
                  if (X < 0)
                     r = m;
                  else
                      l = m;
            }
            cout << fixed << 100.0 * (l + r) / 2.0;
            if (i < n - 1) cout << ' ';
            else cout << '\n';
        }
    }
    return 0;
}
