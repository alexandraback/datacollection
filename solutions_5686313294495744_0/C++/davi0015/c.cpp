#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

map<string, int> ori1, ori2;

int solve(int index, vector<bool> &isOri, vector<string> &word1, vector<string> &word2) {
  if (index == word1.size()) {
    int count = 0;
    forn(i, isOri.size()) {
      if (!isOri[i]) {
        if (ori1[word1[i]] == 0 || ori2[word2[i]] == 0) {
          count = 0;
          break;
        } else {
          count++;
        }
      }
    }
    return count;
  } else {
    isOri[index] = true;
    ori1[word1[index]]++;
    ori2[word2[index]]++;
    int oriSol = solve(index + 1, isOri, word1, word2);

    isOri[index] = false;
    ori1[word1[index]]--;
    ori2[word2[index]]--;
    int fakeSol = solve(index + 1, isOri, word1, word2);
    return max(oriSol, fakeSol);
  }
}

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    int N;
    cin >> N;

    vector<string> word1(N), word2(N);
    forn(j, N) {
      cin >> word1[j] >> word2[j];
    }

    vector<bool> isOri(N);
    int maxFake = solve(0, isOri, word1, word2);
    cout << "Case #" << i + 1 << ": " << maxFake << endl;
  }

  return 0;
}
