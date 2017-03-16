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

#define MAX 100100
double p[MAX],e[MAX];

int main(void)
{
  int caso, T;
  int A,B;

  for(scanf("%d", &T), caso = 1; caso <= T; caso++)
  {
    double r;

    scanf("%d %d", &A, &B);
    fi(A) scanf("%lf", p+i);

    e[0] = p[0];
    for(int i = 1; i < A; i++)
      e[i] = e[i-1]*p[i];

    r = (double)(A+B+1);
    fi(A)
    {
      int C = A-1-i;
      double temp = (double)(B-A+2*C+1) + (1.0-e[i])*(double)(B+1);
      temp = min(temp, (double)(B+2));
      r = min(r, temp);
    }

    printf("Case #%d: %lf\n", caso, r);
  }

  return(0);
}

