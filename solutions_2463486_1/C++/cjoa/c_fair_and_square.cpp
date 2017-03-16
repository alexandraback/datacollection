#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long llong;

string num2str(llong x) {
   char buf[20];
   sprintf(buf, "%lld", x);
   return buf;
}

bool is_palindrome(const string& S) {
   for (int i = 0, j = int(S.size())-1; i < j; ++i, --j)
      if (S[i] != S[j]) return false;
   return true;
}

bool is_palindrome(llong x) {
   return is_palindrome(num2str(x));
}

string concat_rev1(const string& S) {
   string R = S;
   R.erase( int(R.size()-1) );
   reverse(R.begin(), R.end());
   return S + R;
}

string concat_rev2(const string& S) {
   string R = S;
   reverse(R.begin(), R.end());
   return S + R;
}

vector<llong> V1;
void gen1() {
   for (int n = 1; ; ++n) {
      llong n2 = n * llong(n);
      if (n2 > 100000000000000LL)
         break;
      if (is_palindrome(n) && is_palindrome(n2))
         V1.push_back(n2);
   }
}

vector<llong> V2;
void gen2() {
   // single digits
   for (int d = 1; d < 10000; ++d) {
      string s = num2str(d);
      string s1 = concat_rev1(s);
      int a1 = atoi(s1.c_str());
      llong aa = a1 * llong(a1);
      if (is_palindrome(aa) && aa <= 100000000000000LL)
         V2.push_back(aa);

      string s2 = concat_rev2(s);
      int a2 = atoi(s2.c_str());
      aa = a2 * llong(a2);
      if (is_palindrome(aa) && aa <= 100000000000000LL)
         V2.push_back(aa);
   }
   sort(V2.begin(), V2.end());
}

int how_many(llong x) {
   return upper_bound(V2.begin(), V2.end(), x) - V2.begin();
}

int how_many(llong A, llong B) {
// return how_many(B) - how_many(A-1);
// too few to risk it...
   int cnt = 0;
   for (int i = 0; i < V2.size(); ++i)
      if (A <= V2[i] && V2[i] <= B)
         ++cnt;
   return cnt;
}

int main(int argc, char* argv[]) {
// gen1();
   gen2();
// assert(V1 == V2);
/*
   fprintf(stderr, "sz = %d\n", (int) V.size());
   for (int i = 0; i < V.size(); ++i)
      fprintf(stderr, "%d: %lld\n", i, V[i]);
*/

   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      llong A, B;
      scanf("%lld %lld", &A, &B);
      int res = how_many(A, B);
      printf("Case #%d: %d\n", tc, res);
   }

   return 0;
}
