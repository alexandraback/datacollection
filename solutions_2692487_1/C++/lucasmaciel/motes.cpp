#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 101

int main(){
  int motes[MAX], costs[MAX];
  int t, a, n, tests = 0;
  scanf("%d", &t);
  while (t--){
    scanf("%d %d", &a, &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &motes[i]);
    sort(motes, motes+n);
    for (int i = 0; i < n; ++i){
      if (a > motes[i]){
	if (i) costs[i] = costs[i-1];
	else costs[i] = 0;
	a += motes[i];
      }
      else{
	int c = 0;
	if (a-1 == 0){
	  costs[i] = n;
	  continue;
	}
	while (a <= motes[i]){
	  a += a-1;
	  ++c;
	}
	a += motes[i];
	if (i) costs[i] = costs[i-1]+c;
	else costs[i] = c;
      }
    }
    int movs = n;
    for (int i = 0; i < n; ++i)
      movs = min(movs, costs[i]+n-i-1);
    printf("Case #%d: %d\n", ++tests, movs);
  }
  return 0;
}
