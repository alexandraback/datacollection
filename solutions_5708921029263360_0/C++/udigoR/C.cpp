#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<vector<vector<vector<int>>>> countLim(11, vector<vector<vector<int>>>(11, vector<vector<int>>(11, vector<int>(11, 0)) ));

bool solve(vector<int> &v, int K, vector<int> hist, vector<map<int, int>> count, set<int> used, vector<int>& maxHist, vector<map<int, int>> &maxCOunt, set<int> &maxUsed, int &limit, int cl) {
  if (maxHist.size() < hist.size()) {
    maxHist = hist;
    maxCOunt = count;
    maxUsed = used;
    if (maxHist.size() == cl)
      return true;
    return false;
  } else {
    if (limit < 0)
      return true;
    for (int i = 0; i < v.size(); ++i) {
      if (used.find(v[i]) != used.end())
        continue;
      int a = v[i] % 100; 
      int b = 10*(v[i] / 100) + v[i] % 10;
      int c = v[i] / 10;
      if (count[0][a] >= K || count[1][b] >= K || count[2][c] >= K)
        continue;
      used.insert(v[i]);
      hist.push_back(v[i]);
      count[0][a]++;
      count[1][b]++;
      count[2][c]++;
      //limit--;
      bool isOk = solve(v, K, hist, count, used, maxHist, maxCOunt, maxUsed, limit, cl);
      if (isOk)
        return true;
      used.erase(used.find(v[i]));
      hist.erase((++hist.rbegin()).base());
      count[0][a]--;
      count[1][b]--;
      count[2][c]--;
    }
  }
}

void test() {
  for (int K = 1; K <= 10; ++K)
    for (int J = 1; J <= 3; ++J)
      for (int P = J; P <= 3; ++P)
        for (int S = P; S <= 3; ++S)
        {
          vector<int> v;

          for (int i = 1; i <= J; ++i)
            for (int p = 1; p <= P; ++p)
              for (int s = 1; s <= S; ++s)
                v.push_back(i * 100 + p*10 + s);

          vector<int> hist;
          vector<int> maxHist;
          set<int> used, maxUsed;
          vector<map<int, int>> count(3), maxCount(3);
          int limit = 20000000;
          maxHist.push_back(111);
          maxCount[0][11] = 1;
          maxCount[1][11] = 1;
          maxCount[2][11] = 1;
          maxUsed.insert(111);

          solve(v, K, maxHist, maxCount,maxUsed, maxHist, maxCount, maxUsed, limit, 1000);

          /*for (int i = 2; i<= K; ++i)
          solve(v, i, maxHist, maxCount, maxUsed, maxHist, maxCount, maxUsed, limit);
          */

          cout << J << " " << P << " " << S << " " << K << " " << maxHist.size() << endl;

          for (int i =0; i < maxHist.size(); ++i) {
            cout << maxHist[i] / 100 << " " << (maxHist[i] / 10) % 10 << " " << maxHist[i] % 10 << endl;
          }

        }
}

int main() {
  int T;
  cin >> T;

  for (int K = 1; K <= 10; ++K)
    for (int J = 1; J <= 3; ++J)
      for (int P = J; P <= 3; ++P)
        for (int S = P; S <= 3; ++S)
          countLim[K][J][P][S] = J * P *S;

  for (int J = 1; J <= 3; ++J)
    for (int P = J; P <= 3; ++P)
      for (int S = P; S <= 3; ++S)
        countLim[1][J][P][S] = J * P;

  countLim[2][1][1][3] = 2;
  countLim[2][1][2][3] = 4;
  countLim[2][1][3][3] = 6;
  countLim[2][2][2][3] = 8;
  countLim[2][2][3][3] = 12;
  countLim[2][3][3][3] = 18;

  for (int testCase=0; testCase < T; ++testCase)
  {
    int J, P, S, K;

    cin >> J >> P >> S >> K;

    vector<int> v;

    for (int i = 1; i <= J; ++i)
      for (int p = 1; p <= P; ++p)
        for (int s = 1; s <= S; ++s)
          v.push_back(i * 100 + p*10 + s);

    vector<int> hist;
    vector<int> maxHist;
    set<int> used, maxUsed;
    vector<map<int, int>> count(3), maxCount;
    int limit = 20000000;

    solve(v, K, hist, count,used, maxHist, maxCount, maxUsed, limit, countLim[K][J][P][S]);

    cout << "Case #"<<testCase+1<<": " << maxHist.size() << endl;

    for (int i =0; i < maxHist.size(); ++i) {
      cout << maxHist[i] / 100 << " " << (maxHist[i] / 10) % 10 << " " << maxHist[i] % 10 << endl;
    }

  }

  return 0;
}