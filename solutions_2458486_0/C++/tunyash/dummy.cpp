#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

vector<int> dp[(1 << 20) + 5];
bool is[(1<<20)+5];
int key[22];
vector<int> nkey[22];
int match[205];
int able[55];
int skey[55];
string mask(int m, int n)
{
   string s = "";
   for (int i = 0; i < n; i++)
      if (m & (1<<i)) s.pb('1'); else s.pb('0');
   return s;
}

void solve(int test)
{
   int n, sk;
   cin >> sk >> n;
   int cnt = 0;
  // cout << sk << ' ' << n << endl;
   for (int i = 0; i < 205; i++) match[i] = -1;
   
   for (int i = 0; i < sk; i++)
   {
      cin >> skey[i];       
      if (match[skey[i]] == -1) match[skey[i]] = cnt++;
      skey[i] = match[skey[i]];
    //  cout << skey[i] <<  ' ';
   }
  // cout << endl; 
   for (int i = 0; i < n; i++) nkey[i].clear();
   for (int i = 0; i < n; i++)
   {
       cin >> key[i];
       if (match[key[i]] == -1) match[key[i]] = cnt++;
       key[i] = match[key[i]];
       int sz;
       cin >> sz;
       for (int j = 0; j < sz; j++)
       {
          int t;
          cin >> t;
          if (match[t] == -1) match[t] = cnt++;
          nkey[i].pb(match[t]);
       }
   }
   for (int i = 0; i < (1<<n); i++) {is[i] = 0; dp[i].clear();}
   is[0] = 1;
 /*  for (int i = 0; i < n; i++)
   {
      cout << i << "(" << key[i] << "): ";
      for (int j = 0; j < (int)nkey[i].size(); j++) cout << nkey[i][j] << ' ';
      cout << endl; 
   }   */
   for (int i = 0; i < (1<<n); i++)
      if (is[i])
      {
        // cout << mask(i,n) << endl;
         for (int j = 0; j < cnt; j++)
            able[j] = 0;
         for (int j = 0; j < n; j++)
            if (i & (1<<j))
            {
               able[key[j]] --;
               for (int k = 0; k < (int)nkey[j].size(); k++)
                 able[nkey[j][k]]++;
            }
         for (int j = 0; j < sk; j++) able[skey[j]] ++;
       //  for (int j = 0; j < cnt; j++)
       //     cout << able[j] << ' ';
       //  cout << endl;
         for (int j = 0; j < n; j++)
            if ((!(i&(1<<j))) && able[key[j]] > 0) 
            {
            //   cout << "j=" << j << endl;
               vector<int> nval = dp[i];
               nval.pb(j);
               if (!is[i|(1<<j)])
               {
                   dp[i|(1<<j)] = nval;
                   is[i|(1<<j)] = 1;
               }
               else
               {
                  dp[i|(1<<j)] = min(dp[i|(1<<j)], nval);
               }
            }
      }
   cout << "Case #" << test << ": ";
   if (is[(1<<n)-1])
   {
       assert((int)dp[(1<<n)-1].size() == n);
       for (int i = 0; i < (int)dp[(1<<n)-1].size(); i++)
          cout << dp[(1<<n)-1][i]+1 << " \n"[(int)dp[(1<<n)-1].size()-1==i];
       
       for (int i = 0; i < cnt; i++) able[i] = 0;
       for (int i = 0; i < sk; i++) able[skey[i]]++;
       for (int i = 0; i < n; i++)
       {
           int cur = dp[(1<<n)-1][i];
           if (able[key[cur]] == 0) assert(false);
           able[key[cur]]--;
           for (int j = 0; j < (int)nkey[cur].size(); j++)
               able[nkey[cur][j]]++;
       }
   }
   else cout << "IMPOSSIBLE\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}