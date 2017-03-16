#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)

using namespace std;

char perm[27] = "yhesocvxduiglbkrztnwjpfmaq";

void solve() {
  char c;
  scanf(" ");
  while ((c=getchar()) && c!='\n') {
    if (c==' ') printf(" ");
    else printf("%c", perm[c-'a']);
  }
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d: ", i+1);
    solve();
    printf("\n");
  }
  return 0;
}
