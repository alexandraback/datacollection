#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cmath>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define MP(a, b) make_pair(a, b)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}

char mapping[26];

int main() {

mapping[0] = 'y' - 'a';
mapping[1] = 'h' - 'a';
mapping[2] = 'e' - 'a';
mapping[3] = 's' - 'a';
mapping[4] = 'o' - 'a';
mapping[5] = 'c' - 'a';
mapping[6] = 'v' - 'a';
mapping[7] = 'x' - 'a';
mapping[8] = 'd' - 'a';
mapping[9] = 'u' - 'a';
mapping[10] = 'i' - 'a';
mapping[11] = 'g' - 'a';
mapping[12] = 'l' - 'a';
mapping[13] = 'b' - 'a';
mapping[14] = 'k' - 'a';
mapping[15] = 'r' - 'a';
mapping[16] = 'z' - 'a';
mapping[17] = 't' - 'a';
mapping[18] = 'n' - 'a';
mapping[19] = 'w' - 'a';
mapping[20] = 'j' - 'a';
mapping[21] = 'p' - 'a';
mapping[22] = 'f' - 'a';
mapping[23] = 'm' - 'a';
mapping[24] = 'a' - 'a';
mapping[25] = 'q' - 'a';

  int N;
  cin >> N;
  string s;
  getline(cin, s);
  REP(i, N) {
    printf("Case #%d: ", i+1);
    string s1, s2;
    getline(cin, s1);
    REP(i, s1.size()) {
      if (s1[i] != ' ')
        s2 += (char)(mapping[s1[i] - 'a'] + 'a');
      else
        s2 += ' ';
    }
    cout << s2 << endl;
  }
}
