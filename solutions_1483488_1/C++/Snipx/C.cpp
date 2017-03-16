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

int to_i(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        n *= 10;
        n += s[i] - '0';
    }
    return n;
}

int f[10000000];

int len_s(int n)
{
       int ans = 0;
       while (n > 0)
       {
             ans++;
             n /= 10;
       }
       return ans;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");
    int ttt;
    cin >> ttt;
    int test = 1;
    
    for (int i = 0; i < 10000000; i++)
        f[i] = len_s(i);
    
    while (ttt--)
    {
          int a, b;
          cin >> a >> b;
          set<pair<int, int> > ans;
          for (int i = a; i <= b; i++)
          {
              string s = "";
              int q = i;
              while (q > 0)
              {
                    s += q % 10 + '0';
                    q /= 10;
              }
              reverse(s.begin(), s.end());
              int first = to_i(s);
              for (int j = 0; j < s.length() - 1; j++)
              {
                  int second = 0;
                  for (int we = j + 1; we < s.length(); we++)
                  {
                      second *= 10;
                      second += s[we] - '0';
                  }
                  for (int we = 0; we <= j; we++)
                  {
                      second *= 10;
                      second += s[we] - '0';
                  }
                      
                  if (second >= a && second <= b && first < second && f[first] == f[second])
                     ans.insert(make_pair(first, second));
              }
          }
          cout << "Case #" << test++ <<": " << ans.size() << endl;
    }
    
    //cout << clock() << endl;
    //system("pause");
    return 0;
}
