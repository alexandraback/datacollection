#include <iostream>

#include <algorithm>

using namespace std;

typedef long long llong;

inline bool is_vowel(char c) {
   return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool f(const string& s, int ini, int fin, int n) {
   int kcons = 0;
   for (int k = ini; k < fin; ++k) {
      if (is_vowel(s[k]))
         kcons = 0;
      else {
         kcons++;
         if (kcons >= n)
            return true;
      }
   }
   return false;
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
      llong res = 0;
      for (int i = 0; i < S.size(); ++i)
         for (int j = i+n; j <= S.size(); ++j)
            res += f(S, i, j, n);
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
