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
          vector<pair<int, int> > a(n);
          
          for (int i = 0; i < n; i++)
          {
              cin >> a[i].first >> a[i].second;
              swap(a[i].first, a[i].second);
              a[i].first = -a[i].first;
              a[i].second = -a[i].second;
          }
          sort(a.begin(), a.end());
         
          for (int i = 0; i < n; i++)
          {
              swap(a[i].first, a[i].second);
              a[i].first = -a[i].first;
              a[i].second = -a[i].second;
          }

          vector<int> mark(n, 0);
          
          int stars = 0;
          int ans = 0;
          
          while (true)
          {
                bool ac = false;
                
                for (int i = 0; i < n; i++)
                    if (mark[i] == 0 && a[i].second <= stars)
                    {
                                ac = true;
                                mark[i] = 2;
                                stars += 2;
                                ans++;
                    }
                    
                if (ac)
                   continue;
                
                for (int i = 0; i < n; i++)
                    if (mark[i] == 1 && a[i].second <= stars)
                    {
                                ac = true;
                                mark[i] = 2;
                                stars++;
                                ans++;
                                break;
                    }
                    
                if (ac)
                   continue;
                
                for (int i = 0; i < n; i++)
                    if (mark[i] == 0 && a[i].first <= stars)
                    {
                                ac = true;
                                mark[i] = 1;
                                stars++;
                                ans++;
                                break;
                    }
                
                if (!ac)
                   break;
          }
              
          bool ok = true;
          for (int i = 0; i < n; i++)
              if (mark[i] != 2)
                 ok = false;
          cout << "Case #" << cc++ << ": ";
          if (!ok)
             cout << "Too Bad";
          else
              cout << ans;
          cout << endl;
    }
    
    //system("pause");
    return 0;
}
