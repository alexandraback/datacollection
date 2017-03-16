#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int seen[201];
bool doit(const vector<vector<int> >& chests, int* u, int cur, int goal) {
  if (cur == goal) return true;
  if (seen[cur]) return false;
  seen[cur] = true;

  for (int ch = 0; ch < chests.size(); ch++)
    if (!u[ch] && chests[ch][1] == cur) {
      for (int i = 2; i < chests[ch].size(); i++)
        if (doit(chests, u, chests[ch][i], goal)) return true;
    }

  return false;
}

bool possible(const vector<int>& keys, const vector<vector<int> >& chests) {
  int nk[201], nc[201], u[201];
  memset(nk, 0, sizeof(nk));
  memset(nc, 0, sizeof(nc));
  memset(u, 0, sizeof(u));
  for (int i = 0; i < keys.size(); i++) nk[keys[i]]++;
  for (int i = 0; i < chests.size(); i++) nc[chests[i][1]]++;

  for(;;) {
    int type;
    for (type = 1; type <= 200; type++)
      if (nc[type] && nk[type]) break;
    if (type > 200) break;

    // Greedily pick a chest with its own key type as a descendant.
    memset(seen, 0, sizeof(seen));
    int ch;
    for (ch = 0; ch < chests.size(); ch++)
      if (!u[ch] && chests[ch][1] == type) {
        bool loopy = false;
        for (int i = 2; i < chests[ch].size(); i++)
          if (doit(chests, u, chests[ch][i], type)) {loopy = true; break;}
        if (loopy) break;
      }
    if (ch == chests.size()) {
      // Failing that, any chest will do.
      for (ch = 0; ch < chests.size(); ch++)
        if (!u[ch] && chests[ch][1] == type) break;
      assert(ch < chests.size());
    }

    u[ch] = true;
    nc[type]--;
    nk[type]--;
    for (int i = 2; i < chests[ch].size(); i++) nk[chests[ch][i]]++;
  }

  for (int type = 1; type <= 200; type++) if (nc[type]) return false;
  return true;
}

main() {
  int T, K, N, prob=1;
  for (cin >> T; T--;) {
    cout << "Case #" << prob++ << ":";
    cin >> K >> N;
    vector<int> keys(K);
    vector<vector<int> > chests(N);
    for (int i = 0; i < K; i++) cin >> keys[i];
    for (int i = 0; i < N; i++) {
      chests[i].push_back(i+1);
      chests[i].push_back(0);
      cin >> chests[i][1];
      int nk, x;
      cin >> nk;
      for (int j = 0; j < nk; j++) {
        cin >> x;
        chests[i].push_back(x);
      }
    }

    if (!possible(keys, chests)) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }

    while (chests.size()) {
      for (int i = 0; i < chests.size(); i++) {
        int j;
        for (j = 0; j < keys.size(); j++) if (keys[j] == chests[i][1]) break;
        if (j == keys.size()) continue;

        vector<int> keys2 = keys;
        vector<vector<int> > chests2 = chests;
        keys2.erase(keys2.begin()+j);
        keys2.insert(keys2.end(), chests[i].begin()+2, chests[i].end());
        chests2.erase(chests2.begin()+i);
        if (possible(keys2, chests2)) {
          cout << ' ' << chests[i][0];
          swap(keys, keys2);
          swap(chests, chests2);
          break;
        }
        assert(i+1 < chests.size());
      }
    }
    cout << endl;
  }
}
