#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
const int INF           = 1000000009;
const double PI         = acos(-1.0);
const double eps        = 1e-8;
const int MAXN          =0;
const int MAXM          =0;

int t, T;
vector <pair<int, string > > v;
string s;
bool a[26];
int ans, n, i;
int main() {
   freopen("/Users/zisakadze/Projects/QT/plainCPP/input.txt","r",stdin);
   freopen("/Users/zisakadze/Projects/QT/plainCPP/output.txt","w",stdout);
   cin >> T;
   for (t = 1; t <=T; t++)
   {
       cin >> n;
       v.clear();
       for (i = 0; i < n; i++)
       {
            cin >> s;
            v.push_back(make_pair(i, s));
        }

       sort(v.begin(), v.end());
       ans = 0;
       do
       {

           s = "";
           for (i = 0; i < n; i++)
               s += v[i].second;
           char last_ch = s[0];
           for (i = 0; i < 26; i++)
               a[i] = false;

           a[last_ch - 'a'] = true;

           for (i = 1; i < s.length(); i++)
               if (s[i] != last_ch)
               {
                   if (a[s[i]-'a'])
                       break;
                   last_ch = s[i];
                   a[s[i]-'a'] = true;
               }
           if (i == s.length())
               ans ++;
       }while(next_permutation(v.begin(), v.end()));
       printf("Case #%d: %d\n", t, ans);

   }

    return 0;
}
