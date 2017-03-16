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

const int maxn = 30;
int f[maxn][100000];
int inf = 1000000000;

int power[20];

int mask(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ans *= 3;
        ans += s[i] - '0';
    }
    return ans;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    
    power[0] = 1;
    for (int i = 1; i < 20; i++)
        power[i] = power[i - 1] * 3;
    
    int t;
    cin >> t;
    int cc = 1;
    while (t--)
    {
          int n;
          cin >> n;
          for (int i = 0; i < maxn; i++)
              for (int j = 0; j < 100000; j++)
                  f[i][j] = inf;
          f[0][0] = 0;
          vector<pair<int, int> > a(n);
          for (int i = 0; i < n; i++)
              cin >> a[i].first >> a[i].second;
          int pp = power[n] - 1;
          
          for (int stars = 0; stars <= 2 * n; stars++)
              for (int i = 0; i < pp; i++)
              {
                  string s = "";
                  int q = i;
                  while(q > 0)
                  {
                          s += q % 3 + '0';
                          q /= 3;
                  }
                  reverse(s.begin(), s.end());
                  while (s.length() != n)
                        s = "0" + s;
                  for (int j = 0; j < n; j++)
                  {
                      if (s[j] == '0')
                      {
                               if (a[j].first <= stars)
                               {
                                              string t = s;
                                              t[j] = '1';
                                              f[stars + 1][mask(t)] = min(f[stars + 1][mask(t)], f[stars][i] + 1);
                               }
                               if (a[j].second <= stars)
                               {
                                               string t = s;
                                               t[j] = '2';
                                               f[stars + 2][mask(t)] = min(f[stars + 2][mask(t)], f[stars][i] + 1);
                               }
                      }
                      else
                      {
                          if (s[j] == '1' && a[j].second <= stars)
                          {
                                          string t = s;
                                          t[j] = '2';
                                          f[stars + 1][mask(t)] = min(f[stars + 1][mask(t)], f[stars][i] + 1);
                          }
                      }
                  }
              }
              
          string s = "";
          for (int i = 0; i < n; i++)
              s += "2";
          cout << "Case #" << cc++ << ": ";
          if (f[n * 2][mask(s)] == inf)
             cout << "Too Bad";
          else
              cout << f[n * 2][mask(s)];
          cout << endl;
    }
    
    //system("pause");
    return 0;
}
