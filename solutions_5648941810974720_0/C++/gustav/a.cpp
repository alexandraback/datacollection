#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 2005;

char digits[][10] = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};

int cnt[26];
char s[MAX];

vector< int > sol;

void remove(int i, int times) {
  int n = strlen(digits[i]);
  REP(j, n) cnt[digits[i][j] - 'A'] -= times;
  REP(j, times) sol.push_back('0' + i);
}

int get(char c) {
  return cnt[c - 'A'];
}

void solve() {
  sol.clear();

  scanf("%s", s);
  int n = strlen(s);
  REP(i, n) ++cnt[s[i] - 'A'];

  int zeros = get('Z');
  remove(0, zeros);

  int twos = get('W');
  remove(2, twos);

  int sixes = get('X');
  remove(6, sixes);

  int fours = get('U');
  remove(4, fours);

  int sevens = get('S');
  remove(7, sevens);

  int ones = get('O');
  remove(1, ones);

  int threes = get('R');
  remove(3, threes);

  int fives = get('F');
  remove(5, fives);

  int nines = get('N') / 2;
  remove(9, nines);

  int eights = get('E');
  remove(8, eights);

  REP(i, 26) assert(cnt[i] == 0);

  sort(sol.begin(), sol.end());

  for (char c : sol)
    putchar(c);
  puts("");
}

int main(void) 
{
  int T;
  scanf("%d", &T);
  FOR(i, 1, T + 1) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}
