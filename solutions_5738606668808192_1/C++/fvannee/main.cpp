#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#include <boost/multiprecision/cpp_int.hpp>

#define INF 1023123123
#define EPS 1e-11
#define LSOne(S) (S & (-S))

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define FORB(X,Y) for (int (X) = (Y);(X) >= 0;--(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define REPB(X,Y,Z) for (int (X) = (Y);(X) >= (Z);--(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;
using namespace boost::multiprecision;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void print_case(int i)
{
   cout << "Case #" << i + 1 << ": ";
}

vector<vector<cpp_int>> get_table(int size)
{
   vector<vector<cpp_int>> res(11);
   for (int i = 2; i <= 10; i++)
   {
      cpp_int ans = 1;
      for (int j = 0; j < size; j++)
      {
         res[i].push_back(ans);
         ans *= i;
      }
   }
   return res;
}

cpp_int to_num(const vector<vector<cpp_int>>& table, vi num, int base)
{
   cpp_int ans = 0;
   for (int i = 0; i < num.size(); i++)
   {
      if (num[i] == 1)
      {
         int idx = num.size() - 1 - i;
         ans += table[base][idx];
      }
   }
   return ans;
}

cpp_int estimate_prime(cpp_int num)
{
   int m = 10000;
   if (m > num)
      m = num.convert_to<int>();
   for (int i = 2; i < m; i++)
   {
      if (num % i == 0)
         return i;
   }
   return -1;
}

int main()
{
   int ntc;
   cin >> ntc;
   
   auto table = get_table(32);
   FORN(kk, ntc)
   {
      cout << "Case #" << kk + 1 << ":" << endl;
      int n, j;
      cin >> n >> j;
      vi s(n);
      s[0] = 1;
      s[s.size() - 1] = 1;
      int numfound = 0;
      for (int i = 0; i < (1 << 14) - 1 && numfound < j; i++)
      {
         int k = s.size() - 2;
         int carry = 1;
         while (carry == 1)
         {
            int sum = s[k] ^ carry;
            carry = s[k] & carry;
            s[k] = sum;
            k--;
         }

         bool prime = false;
         vector<cpp_int> divis(11);
         for (int base = 2; base <= 10 && !prime; base++)
         {
            cpp_int num = to_num(table, s, base);
            cpp_int divi = estimate_prime(num);
            prime = divi == -1;
            divis[base] = divi;
         }
         if (!prime)
         {
            FORN(l, s.size())
               cout << s[l];
            for (int base = 2; base <= 10; base++)
               cout << ' ' << divis[base];
            cout << endl;
            numfound++;
         }
      }
   }
}
