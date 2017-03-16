#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>

using namespace std;

int T;
int A, B;

int log10(int i)
{
  if( i >= 100000000) return 8;
  if( i >= 10000000) return 7;
  if( i >= 1000000) return 6;
  if( i >= 100000) return 5;
  if( i >= 10000) return 4;
  if( i >= 1000) return 3;
  if( i >= 100) return 2;
  if( i >= 10) return 1;
  return 0;
}

int pow10(int i)
{
  switch(i) {
    case 0: return 1;
    case 1: return 10;
    case 2: return 100;
    case 3: return 1000;
    case 4: return 10000;
    case 5: return 100000;
    case 6: return 1000000;
    case 7: return 10000000;
    case 8: return 100000000;
    case 9: return 1000000000;
    default: return 0;
  }
}
int main()
{
  scanf("%d\n", &T);
  for(int i = 1; i <= T; i++)
  {
    scanf("%d%d", &A, &B);
    long long res = 0;

    for(int j = A; j < B; j++)
    {
      int n = log10(j) + 1;
      set<int> s;
      for(int k = 1; k < n; k++) {
        int p = pow10(k);
        int rotate = (j / p) + (j%p)*(pow10(n-k)) ;
        //printf("%d, %d pow:%d-> %d\n", j, k , p, rotate);
        //if(rotate > j && rotate <= B) {
        //  printf("%d, %d\n", j, rotate);
        //}
        if(rotate > j && rotate <= B && s.find(rotate) == s.end()) {
          res++;
          s.insert(rotate);
        }
      }
    }

    printf("Case #%d: %lld\n", i, res);
  }
}

