#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 11

int T, J, P, S, K;
int cnt[3][MAXN][MAXN];

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> J >> P >> S >> K;
    vector<vector<int> > outfits;
    for (int j = 1; j <= J; j++) {
      vector<int> outfit;
      outfit.push_back(j);
      for (int p = 1; p <= P; p++) {
        vector<int> poutfit = outfit;
        poutfit.push_back(p);
        for (int s = 1; s <= S; s++) {
          vector<int> soutfit = poutfit;
          soutfit.push_back(s);
          outfits.push_back(soutfit);
        }
      }
    }
    vector<vector<int> > bestComb;
    sort(outfits.begin(), outfits.end());
    vector<vector<int> > soutfits = outfits;
    int O = outfits.size();
    int tries = 500000;
    do {
      vector<vector<int> > comb;
      memset(cnt, 0, sizeof(cnt));
      for (int i = 0; i < O; i++) {
        if (cnt[0][outfits[i][0]][outfits[i][1]] >= K ||
            cnt[1][outfits[i][0]][outfits[i][2]] >= K ||
            cnt[2][outfits[i][1]][outfits[i][2]] >= K)
          break;
        cnt[0][outfits[i][0]][outfits[i][1]]++;
        cnt[1][outfits[i][0]][outfits[i][2]]++;
        cnt[2][outfits[i][1]][outfits[i][2]]++;
        comb.push_back(outfits[i]);
      }
      if (comb.size() > bestComb.size()) {
        bestComb = comb;
      }
      outfits = soutfits;
      random_shuffle(outfits.begin(), outfits.end());
      tries--;
    } while (tries);
    cout << "Case #" << t << ": " << bestComb.size() << endl;
    for (int i = 0; i < bestComb.size(); i++) {
      cout << bestComb[i][0] << " " << bestComb[i][1] << " " << bestComb[i][2] << endl;
    }
  }
  return 0;
}
