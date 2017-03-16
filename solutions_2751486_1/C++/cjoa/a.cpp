#include <iostream>

#include <algorithm>

using namespace std;

#define SZ(a) int((a).size())

typedef long long llong;

inline bool is_vowel(char c) {
   return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

#define MAXS 1000008
int C[MAXS];
int nxt[MAXS];
llong scan(const string& s, int n) {
   int ncons = 0;
   for (int i = 0; i < SZ(s); ++i) {
      if (is_vowel(s[i]))
         ncons = 0;
      else
         ++ncons;         
      C[i] = ncons;
   }

   for (int i = 0, last = -1; i < SZ(s); ++i) {
      if (C[i] >= n) {
         last = i - n + 1;
      }
      nxt[i] = last;
   }
   llong res = 0;
   for (int i = 0; i < SZ(s); ++i) {
      if (nxt[i] < 0) continue;
      res += nxt[i] + 1;
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      string S;
      int n;
      cin >> S >> n;
      llong res = scan(S, n);
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
