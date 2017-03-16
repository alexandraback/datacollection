#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN = 2010;

char s[MAXN];
char piv[] = {'Z', 'W', 'X', 'G', 'T', 'R', 'O', 'F', 'V', 'I'};

int T, N;
int cnt[11], cnt_s[26];
int val[] = {0, 2, 6, 8, 3, 4, 1, 5, 7, 9};

string str[] = {"ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR", "ONE", "FIVE", "SEVEN", "NINE"};

void remove(string name, int n) {
  for (char c : name) 
    cnt_s[c - 'A'] -= n; 
} 

inline void init() {
  memset(cnt, 0, sizeof cnt);
  memset(cnt_s, 0, sizeof cnt_s);
}

void solve(int t) {

  init();

  scanf("%s", s); N = strlen(s); 
  for (int i = 0; i < N; ++i) 
    ++cnt_s[s[i] - 'A'];

  for (int i = 0; i < 10; ++i) {
    cnt[val[i]] = cnt_s[piv[i] - 'A'];
    remove(str[i], cnt[val[i]]);
  }

  printf("Case #%d: ", t);

  for (int i = 0; i < 10; ++i) 
    for (int j = 0; j < cnt[i]; ++j)
      printf("%d", i);

  printf("\n");

}

int main(void) {

  scanf("%d", &T);
  for (int t = 0; t < T; ++t)
    solve(t + 1);

  return 0;

}

