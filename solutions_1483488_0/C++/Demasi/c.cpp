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
  map<pair<int, int>, int> foi;

  for(scanf("%d", &T), caso = 1; caso <= T; caso++)
  {
    int r, A, B;

    foi.clear();
    scanf("%d %d", &A, &B);

    int tam;
    char s[256];
    sprintf(s, "%d", A);
    tam = strlen(s);

    int dez = 1;
    for(int i = 0; i < tam-1; i++)
      dez *= 10;

    r = 0;
    for(int n = A; n <= B; n++)
    {
      int m = n;
      for(int i = 0; i < tam; i++)
      {
        int d = m%10;
        m = (d*dez)+(m/10);

        if (n >= A && n <= B && m >= A && m <= B && n != m)
          if (foi.find(make_pair(n,m)) == foi.end())
          {
            foi[make_pair(n,m)] = 1;
            foi[make_pair(m,n)] = 1;
            r++;
          }
      }
    }

    printf("Case #%d: %d\n", caso, r);
  }

  return(0);
}

