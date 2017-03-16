#include <iostream>
#include <fstream>

#include <cstring>

#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

typedef pair<int,int> II;

#define SZ(a) int((a).size())

#define INF 1000000000

vector<string> words;

II find_diff(const string& S, int idx, const string& W, int& ndif) {
   if (SZ(W) > idx+1)
      return II(-2, -2);

   ndif = 0;
   II res(-1, -1);
   for (int i = idx, j = SZ(W)-1; j >= 0; --i, --j) {
      if (S[i] != W[j]) {
         ++ndif;
         if (res.second < 0)
            res.second = j;
         if (res.first >= 0 && res.first - j < 5) return II(-2, -2);
         res.first = j;
      }
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   ifstream dict_file("garbled_email_dictionary.txt");
   string w;
   while (dict_file >> w)
      words.push_back(w);
   dict_file.close();

// cerr << AC.nodes.size() << endl;
   
   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      string S;
      cin >> S;
      int N = S.size();
//      cout << "N = "  << N << endl;

      VVI DP(N+1, VI(6, INF));

      DP[0][5] = 0;
      for (int i = 1; i <= N; ++i) {
         for (int j = 0; j < words.size(); ++j) {
            int len = SZ(words[j]);
            if (i < len) continue;

            int ndif = 0;
            II cur = find_diff(S, i-1, words[j], ndif);
            if (cur.first == -2) continue;

            if (cur.first == -1) {
               for (int last = 0; last <= 5; ++last) {
                  int nlast = min(last + len, 5);
                  if (DP[i][nlast] > DP[i - len][last]) {
                     DP[i][nlast] = DP[i - len][last];
                  }
               }
            }
            else {
               for (int last = 0; last <= 5; ++last) {
                  if (last + cur.first + 1 < 5) continue;
                  int nlast = min(len - cur.second - 1, 5);
                  if (DP[i][nlast] > DP[i - len][last] + ndif) {
                     DP[i][nlast] = DP[i - len][last] + ndif;
                  }                  
               }
            }
         }
      }

      int res = INF;
      for (int last = 0; last <= 5; ++last)
         res = min(res, DP[N][last]);
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
