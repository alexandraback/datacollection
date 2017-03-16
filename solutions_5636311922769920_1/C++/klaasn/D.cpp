/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

long long pos(int K, int C, int current) {
  long long p = 0;
  for(int i=0; i < C; i++) {
    p = p * (long long) K;
    p += (long long) current;
    if (current < K - 1) {
      current ++;
    }
  }
  return p + 1;
}

bool possible(int K, int C, int S) {
  return K <= C * S;
}


int main() {
  assert(pos(10,3,0) == 13); 
  assert(pos(10,3,3) == 346); 
  assert(pos(10,3,6) == 679); 
  assert(pos(10,3,9) == 1000); 
  assert(pos(2,3,0) == 4); 

  assert(possible(2,3,2) == true);
  assert(possible(1,1,1) == true);
  assert(possible(2,1,1) == false);
  assert(possible(2,1,2) == true);
  assert(possible(3,2,3) == true);

  int N;
  cin >> N;
  for(int i=1;i<=N;i++) {
    int K, C, S;
    cin >> K; // length of sequence
    cin >> C; // level of tree
    cin >> S; // picks

    printf("Case #%d:", i); 
    if(!possible(K,C,S)) {
	printf(" IMPOSSIBLE\n");
	continue;
    }

    int start = 0;
    while(start < K) {
      printf(" %llu", pos(K, C, start));
      start += C;
    }
    printf("\n");
  }
  return 0;
  
  
}
