#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <fstream>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int TC, N, nodes, next[2000000][26], term[2000000], tab[5000][10];
string S;

void init_trie() {
  nodes = 1;
  memset(next, 0, sizeof(next));
  memset(term, 0, sizeof(term));
  ifstream in("garbled_email_dictionary.txt");
  string s;
  while (in >> s) {
    int cur = 0;
    FOR(i, 0, sz(s)) {
      int c = s[i] - 'a';
      if (!next[cur][c]) next[cur][c] = nodes++;
      cur = next[cur][c];
    }
    term[cur] = 1;
  }
  in.close();
}

int rek(int, int);

int calc(int p, int sk, int node) {
  int res = oo;
  if (term[node]) res = min(res, rek(p, sk));
  if (p == N) return res;
  int c = S[p] - 'a';
  if (next[node][c]) {
    res = min(res, calc(p+1, max(0, sk-1), next[node][c]));
  }
  if (sk == 0) {
    FOR(i, 0, 26) {
      if (i == c) continue;
      if (next[node][i]) {
        res = min(res, 1 + calc(p+1, 4, next[node][i]));
      }
    }
  }
  return res;
}

int rek(int p, int sk) {
  if (p == N) return 0;
  int &res = tab[p][sk];
  if (res != -1) return res;
  return res = calc(p, sk, 0);
}

int main() {
  init_trie();
  cin >> TC;
  FOR(cs, 1, TC+1) {
    cin >> S;
    N = sz(S);
    memset(tab, -1, sizeof(tab));
    cout << "Case #" << cs << ": " << rek(0, 0) << endl;
  }
	return 0;
}
