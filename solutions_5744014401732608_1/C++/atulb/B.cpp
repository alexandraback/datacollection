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
   ULL B, M;
   cin >> B >> M;
   ULL ONE = 1;
   if (M > (ONE << (B - 2)))
   {
      cout << "IMPOSSIBLE";
      return;
   }
   cout << "POSSIBLE" << endl;

   vector<string> ret;
   for (ULL i = 0; i < B; i++)
   {
      string row(B, '0');
      ret.pb(row);
   }

   for (ULL i = 0; i < B - 1; i++)
      for (ULL j = 0; j < B - 1; j++)
      {
         if (i == j)
            continue;
         if (i < j)
            ret[i][j] = '1';
      }

//   for (ULL x=0;x<B;x++) {
//      cout << ret[x] << endl;
//   }
   if (M == (ONE << (B-2))) {
      M--;
      ret[0][B-1] = '1';
   }

   int i = (int) B - 2;
   while (i >= 0 && M != 0)
   {
      if ((M & (ONE << (i-1))) != 0)
      {
         M = M ^ (ONE << (i-1));
         ret[i][B - 1] = '1';
      }
      i--;
   }

   assert(M == 0);
   //cout << i << " " << M << endl;

   for (ULL x = 0; x < B; x++)
   {
      cout << ret[x];
      if (x != B - 1)
         cout << endl;
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
      cout << endl;
   }

   return 0;
}
