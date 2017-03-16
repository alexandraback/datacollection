#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef long long huge;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef pair<int, int> pi;
typedef vector<pair<int, int> > vpi;

#define oo 0x3f3f3f3f
#define fn(_i, _n) for(int (_i) = 0; (_i) < (_n); (_i)++)
#define fi(_n) fn(i, (_n))
#define fj(_n) fn(j, (_n))
#define fk(_n) fn(k, (_n))
#define foreach(_x) for(typeof((_x).begin()) it = (_x).begin(); it != (_x).end(); it++)
#define pb(_x) push_back((_x))
#define sz(_x) ((int)(_x).size())
#define all(_x) (_x).begin(), (_x).end()
#define rall(_x) (_x).rbegin(), (_x).rend()
#define mp(_x, _y) make_pair((_x), (_y))
#define fill(_x, _y) memset((_x), (_y), sizeof(_x))
#define zero(_x) fill(_x, 0)
#define shl(_n) (1<<(_n))
#define lshl(_n) (1LL<<(_n))

int main(void)
{
  int caso, T;
  char *str = "yhesocvxduiglbkrztnwjpfmaq";

  for(scanf("%d\n", &T), caso = 1; caso <= T; caso++)
  {
    char ch;

    printf("Case #%d: ", caso);
    while(scanf("%c", &ch) == 1)
    {
      if (ch >= 'a' && ch <= 'z')
        printf("%c", str[ch-'a']);
      else printf("%c", ch);
      if (ch == '\n') break;
    }

  }

  return(0);
}

