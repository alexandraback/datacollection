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

double f[500];

int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    int t;
    cin >> t;
    int cc = 1;
    while (t--)
    {
          memset(f, 0, sizeof(f));
          int a, b;
          cin >> a >> b;
          vector<double> pr(a);
          for (int i = 0; i < a; i++)
              cin >> pr[i];
              
              
          for (int i = 0; i < (1 << a); i++)
          {
              string s = "";
              int q = i;
              while (q > 0)
              {
                    s += q % 2 + '0';
                    q /= 2;
              }
              reverse(s.begin(), s.end());
              while (s.length() < a)
                    s = "0" + s;
              
              double cur;
              if (s[0] == '0')
                 cur = pr[0];
              else
                  cur = 1 - pr[0];
              for (int j = 1; j < a; j++)
                  if (s[j] == '0')
                     cur *= pr[j];
                  else
                      cur *= 1 - pr[j];
                      
              
              for (int j = 1; j <= a; j++)
              {
                  int types = 0;
                  string t = s;
                  for (int we = 0; we < j; we++)
                      t.erase(t.end() - 1, t.end());
                  types += j;
                  types += b - t.length();
                  while (t.length() < b)
                        t = t + "0";
                  bool ok = true;
                  for (int we = 0; we < t.length(); we++)
                      if (t[we] == '1')
                         ok = false;
                         
                  types++; //enter
                         
                  if (!ok)
                     types += b + 1;
                     
                  f[j] += cur * types;
                                    
                      
              }
              if (i == 0)
                     f[b + 1] += cur * (b - a + 1);
                  else
                      f[b + 1] += cur * (b - a + 1 + 1 + b);
          }
          cout << "Case #" << cc++ << ": ";
          
          double ans = 1e20;
          for (int i = 1; i <= a; i++)
              ans = min(ans, f[i]);
          ans = min(ans, 1 + (double)b + 1);
          ans = min(ans, f[b + 1]);
          cout.precision(6);
          cout << fixed << ans << endl;
          
    }
    //system("pause");
    return 0;
}
