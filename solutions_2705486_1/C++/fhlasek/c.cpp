/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAX_TRIE 2000000
#define P 26
int trie[MAX_TRIE][P], T = 1;
bool end[MAX_TRIE];

void add_to_trie (string text) {
  int t = 0;
  for (size_t i = 0; i < text.size(); i++) {
    int n = text[i] - 'a';
    if (trie[t][n]) t = trie[t][n];
    else t = trie[t][n] = T++;
  }
  end[t] = true;
}

void load () {
  ifstream file;
  file.open("garbled_email_dictionary.txt");

  string text;
  while ( file >> text ) add_to_trie(text);
}

#define MAXN 4444
int dp[MAXN][5];
char input[MAXN];

void generate (int t, int pos, int changes, int last) {
  if (end[t]) dp[pos][last] = min(dp[pos][last], changes);
  if(input[pos] == '\0') return;

  if (trie[t][input[pos]-'a']) generate(trie[t][input[pos]-'a'], pos + 1, changes, max(0, last-1));
  if (last == 0) REP(i, 26) if(trie[t][i]) generate (trie[t][i], pos + 1, changes + 1, 4);
}


int main(int argc, char *argv[]){
  load();
  int T;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1);
    scanf("%s", input);
    int N = strlen(input);
    REP(i, N + 1) REP(j, 5) dp[i][j] = MAXN;
    dp[0][0] = 0;
    REP(i, N) REP(j, 5) generate(0, i, dp[i][j], j);
    int best = MAXN;
    REP(i, 5) best = min(best, dp[N][i]);
    printf("%d\n", best);
  }
   
  return 0;
}

