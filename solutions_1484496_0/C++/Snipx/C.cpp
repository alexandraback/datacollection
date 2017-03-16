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
vector<string> f[10000000];
int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    int test = 1;
    int tt;
    cin >> tt;
    while (tt--)
    {
          int n;
          cin >> n;
          vector<int> a(n);
          for (int i = 0; i < n; i++)
              cin >> a[i];
          for (int i = 1; i < (1 << n); i++)
          {
              string s = "";
              int q = i;
              while (q > 0)
              {
                    s += q % 2 + '0';
                    q /= 2;
              }
              reverse(s.begin(), s.end());
              while (s.length() < n)
                    s = "0" + s;
              int c = 0;
              for (int j = 0; j < n; j++)
                  if (s[j] == '1')
                     c += a[j];
              f[c].push_back(s);
          }
          cout << "Case #" << test++ << ":" << endl;
          bool ok = false;
          for (int i = 0; i < 10000000; i++)
          {
              if (f[i].size() >= 2 && !ok)
              {
                              for (int j = 0; j < n; j++)
                                  if (f[i][0][j] == '1')
                                     cout << a[j] << " ";
                              cout << endl;
                              for (int j = 0; j < n; j++)
                                  if (f[i][1][j] == '1')
                                     cout << a[j] << " ";
                              ok = true;
              }
              f[i].clear();
          }
          if (!ok)
             cout << "Impossible";
          cout << endl;
    }
    //system("pause");
    return 0;
}
