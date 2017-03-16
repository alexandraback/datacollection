#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

struct Node {
  bool end;
  Node *next[26];

  Node()
    : end(false)
  {
    CLR(next, 0);
  }
};

Node * root;

void init() {
  char word[16];
  FILE * f = fopen("garbled_email_dictionary.txt", "r");
  root = new Node;

  while (fscanf(f, " %s", word) == 1) {
    Node * node = root;
    for (char * p = word; *p; ++p) {
      int x = *p - 'a';

      Node ** next = &node->next[x];
      if (!*next) {
        *next = new Node;
      }
      node = *next;
    }
    node->end = true;
  }
}

const int MAXDIST = 5;
int L;
char str[4096];
int dp[4096][MAXDIST];

void rec(int err, int i, int d, Node * node) {
  assert(0 <= i);
  assert(i <= L);
  assert(0 <= d);
  assert(d < MAXDIST);
  if (!node) return;
  if (node->end) dp[i][d] = min(dp[i][d], err);

  if (i == L) return;
  int x = str[i] - 'a';

  rec( err, i+1, max(d-1, 0), node->next[x] );

  if (d == 0) {
    FOR(y,26) {
      rec( err+1, i+1, MAXDIST-1, node->next[y] );
    }
  }
}

const int inf = 1000000;
void doit(int cas) {
  CLR(str, 0);
  scanf(" %s", str);
  L = strlen(str);

  FOR(i,L+1) FOR(d,MAXDIST) dp[i][d] = inf;
  dp[0][0] = 0;

  FOR(i,L) {
    FOR(d,MAXDIST) {
      rec(dp[i][d], i, d, root);
    }
  }

  int ans = inf;
  FOR(d,MAXDIST) ans = min( ans, dp[L][d] );
  assert(ans < inf);
  printf("Case #%d: %d\n", cas+1, ans);
}

int T;
int main() {
  init();
  scanf(" %d", &T);
  FOR(cas,T) doit(cas);
  return 0;
}
