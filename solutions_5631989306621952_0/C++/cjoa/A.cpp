#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

string solve(const string& S) {
   const int N = S.size();
   string res;
   res += S[0];
   for (int i = 1; i < N; ++i) {
      if (S[i] >= res[0])
         res = string(1, S[i]) + res;
      else
         res += S[i];
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
      cin >> S;
      string res = solve(S);
      cout << "Case #" << tc << ": " << res << '\n';
   }

   return 0;
}
