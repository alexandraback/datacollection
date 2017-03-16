# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <math.h>
# include <algorithm>
# include <string.h>
# include <stack>
# include <queue>
# include <sstream>
# include <set>
# include <map>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    int tt;
    cin >> tt;
    int test = 1;
    while (tt--)
    {
          int n;
          cin >> n;
          vector<double> p(n);
          double x = 0;
          for (int i = 0; i < n; i++)
              cin >> p[i], x += p[i];
          vector<double> ans(n);
          for (int i = 0; i < n; i++)
          {
              double l = 0, r = 1;
              double eps = 1e-11;
              while (fabs(l - r) > eps)
              {
                    double m = (l + r) / 2;
                    double points = p[i] + x * m;
                    
                    double ost = 1 - m;
                    for (int j = 0; j < n; j++)
                    {
                        if (i == j)
                           continue;
                        if (p[j] >= points)
                           continue;
                           
                        double need = points - p[j];
                        need /= x;
                        ost -= need;
                    }
                    
                    if (ost > 0)
                       l = m;
                    else
                        r = m;
              }
              ans[i] = l;
              ans[i] *= 100;
          }
          cout.precision(6);
          cout << "Case #" << test++ << ": ";
          for (int i = 0; i < n; i++)
              cout << fixed << ans[i] << " ";
          cout << endl;
    }
    //system("pause");
    return 0;
}
