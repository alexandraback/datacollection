#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
#define vi vector<int>
#define vs vector<string>
#define vl vector<LL>
#define pb push_back
#define endl "\n"

void solve()
{
   int J, P, S, K;
   cin >> J >> P >> S >> K;

   map<int, int> mp1;
   map<int, int> mp2;
   map<int, int> mp3;

   struct A
   {
      int j;
      int p;
      int s;
      explicit A(int jj, int pp, int ss)
      {
         j = jj;
         p = pp;
         s = ss;
      }
   };

   vector<A> ans;
   for (int j = 0; j < J; j++)
      for (int p = 0; p < P; p++)
         for (int s = 0; s < S; s++)
         {
            bool valid = true;
            //1
            int curr1 = 20 * j + p;
            auto it1 = mp1.find(curr1);
            if (it1 != mp1.end() && it1->second >= K)
               valid = false;

            // 2
            int curr2 = 20 * j + s;
            auto it2 = mp2.find(curr2);
            if (it2 != mp2.end() && it2->second >= K)
               valid = false;

            // 3
            int curr3 = 20 * p + s;
            auto it3 = mp3.find(curr3);
            if (it3 != mp3.end() && it3->second >= K)
               valid = false;

            if (valid)
            {
               ans.pb(A(j + 1, p + 1, s + 1));
               if (it1 == mp1.end())
                  mp1[curr1] = 1;
               else
                  it1->second++;

               if (it2 == mp2.end())
                  mp2[curr2] = 1;
               else
                  it2->second++;

               if (it3 == mp3.end())
                  mp3[curr3] = 1;
               else
                  it3->second++;
            }
         }
   int sz = (int) ans.size();
   cout << sz << endl;
   for (int i = 0; i < sz; i++)
   {
      cout << ans[i].j << " " << ans[i].p << " " << ans[i].s << endl;
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   ULL T = 0;
   cin >> T;
   for (ULL i = 1; i <= T; ++i)
   {
      cout << "Case #" << i << ": ";
      solve();
   }

   return 0;
}

