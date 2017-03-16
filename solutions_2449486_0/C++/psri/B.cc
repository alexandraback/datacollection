#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>

using std::map;
using std::pair;
using std::vector;
using std::sort;


#define FOR(i, a , b) for(int i = (a); i <= (b); ++i)
#define FOREACH(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

int lawn[110][110];
int maxr[110];
int maxc[110];

int main(){
  int N, n, m, max;
  scanf("%d", &N);
  FOR(I, 1, N){
    scanf("%d %d", &n, &m);
    FOR(i, 0, n-1){
      max = 0;
      FOR(j, 0, m-1){
	scanf("%d", &lawn[i][j]);
	if(lawn[i][j] > max)
	  max = lawn[i][j];
      }
      maxr[i] = max;
    }
    FOR(i, 0, m-1){
      max = 0;
      FOR(j, 0, n-1){
	if(lawn[j][i] > max)
	  max = lawn[j][i];
      }
      maxc[i] = max;
    }
    bool flag = true;
    FOR(i, 0, n-1){
      FOR(j, 0, m-1){
	if(lawn[i][j] < maxr[i] && lawn[i][j] < maxc[j]){
	  flag = false;
	  break;
	}
      }
      if(!flag)
	break;
    }
    printf("Case #%d: ", I);
    if(flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}



// Local Variables:
// compile-command: "g++ -O3 -o B B.cc"
// End:
