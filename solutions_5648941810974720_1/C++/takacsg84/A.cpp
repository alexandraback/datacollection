#include <bits/stdc++.h>
#define REP(x, n) for (int x = 0; x < (int)(n); x++)
#define RREP(x, n) for (int x = (int)(n)-1; x >= 0; --x)
#define FOR(x, m, n) for (int x = (int)m; x < (int)(n); x++)
#define EACH(itr, cont) \
  for (typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X) (X).begin(), (X).end()
#define mem0(X) memset((X), 0, sizeof(X))
#define mem1(X) memset((X), 255, sizeof(X))

using namespace std;
typedef long long LL;

string numbers[10] = {"ZERO", "ONE", "TWO",   "THREE", "FOUR",
                      "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

// string numbers[10] = {"ONE", "SEVEN", "NINE"};

void remove(int x, int val, map<char, int> &M) {
  for (char ch : numbers[x]) M[ch] -= val;
}

void doStuff() {
  string s;
  cin >> s;
  int N = s.length() / 3;
  map<char, int> M;
  REP(i, s.length()) M[s[i]]++;
  vector<int> result(10);
  result[0] = M['Z'], remove(0, M['Z'], M);
  result[2] = M['W'], remove(2, M['W'], M);
  result[4] = M['U'], remove(4, M['U'], M);
  result[5] = M['F'], remove(5, M['F'], M);
  result[3] = M['R'], remove(3, M['R'], M);
  result[8] = M['G'], remove(8, M['G'], M);
  result[6] = M['X'], remove(6, M['X'], M);
  result[1] = M['O'], result[7] = M['V'], result[9] = M['I'];
  REP(i, 10) REP(j, result[i]) printf("%d", i);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t, T) printf("Case #%d: ", t + 1), doStuff();
  return 0;
}