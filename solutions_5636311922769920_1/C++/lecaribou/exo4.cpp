#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iostream>
#include<queue>
#include<set>

using namespace std;

void solve_case(int k, int c, int s)
{
   int last_un = 0;
   vector<long long int> ans;
   while((last_un < k) && (ans.size() < s))
   {
      vector<int> poly (c,0);
      for(int i = 0; (i < c) && (last_un < k); i++)
      {
         poly[i] = last_un; last_un++;
      }
      long long int eval = 0;
      for(int i = 0; i < c; i++) eval = k*eval + poly[i];
      ans.push_back(eval);
   }
   if(last_un == k)
   {
      for(int i = 0; i < ans.size(); i++) cout << " " << (1 + ans[i]);
   }
   else cout << " IMPOSSIBLE";
}

int main()
{
   int t;
   cin >> t;
   for(int i = 1; i <= t; i++)
   {
      if(i > 1) cout << endl;
      int k, c, s;
      cin >> k >> c >> s;
      cout << "Case #" << i << ":";
      solve_case(k,c,s);
   }
}
