#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;
const int MAXL = 10;
vector<string> D[MAXL+1];
typedef vector<string>::iterator VIT;

void loadDict() {
  FILE* dictionary = fopen("garbled_email_dictionary.txt", "r");
  const int dictSize = 521196;
  char buf[MAXL+1];
  for (int i = 0; i < dictSize; i++) {
    fscanf(dictionary, "%s", buf);
    string s(buf);
    D[s.size()].push_back(s);
  }
  for (int i = 0; i <= MAXL; i++) sort(D[i].begin(), D[i].end());
}

int guessMin(string A){
  int M = INT_MAX/4100; int l = A.size();
  for (int i = 0; i < D[A.size()].size(); i++) {
    int m = 0;
    for (int j = 0; j < A.size(); j++) {
      if (A[j] == D[l][i][j]);
      else if (abs(A[j] - D[l][i][j]) >= 5) m++;
      else goto outer;
      if (m > M) continue;
    }
    M = min(M, m);
    outer:;
  }
  return M;
}

int mmin(int a, int b) { return a < b ? a : b; }
map<string, int> Map;
int findMin(string A) {
  if (Map.find(A) != Map.end()) return Map[A];
  if (A.size() == 0) return 0;
  int M = INT_MAX;
  for (int i = 1; i <= mmin(A.size(), MAXL); i++)
    M = min(M, 
              guessMin(A.substr(0,i)) + 
              findMin(A.substr(i, A.size()-i)));
  return Map[A] = M;
}

int main() {
  loadDict();
  int z; scanf ("%d", &z);
  char buf[4100];
  for (int t = 1; t <= z; t++) {
    scanf ("%s", buf);
    printf ("Case #%d: %d\n", t, findMin(string(buf)));
  }
  return 0;
}
