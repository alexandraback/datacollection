#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 155
#define INF (1<<30)
int N, M;
int Board[MAXN][MAXN];

int tcase, caseNo;
int LargestRow[MAXN];
int LargestCol[MAXN];

int main(){
    for(scanf("%d",&tcase), caseNo = 1; tcase; tcase -= 1, caseNo++) {
          scanf("%d %d", &N, &M);
          for(int i=0; i<N; ++i) {
          	  for(int j=0; j<M; ++j) {
          	  	  scanf("%d", &Board[i][j]);
          	  }
          }
          for(int i=0; i<N; ++i) LargestRow[i] = -INF;
          for(int i=0; i<M; ++i) LargestCol[i] = -INF;
          for(int i=0; i<N; ++i){
          	  for(int j=0; j<M; ++j) LargestRow[i] = max(LargestRow[i], Board[i][j]);
          }
          for(int i=0; i<M; ++i){
          	  for(int j=0; j<N; ++j) LargestCol[i] = max(LargestCol[i], Board[j][i]);
          }
          bool isPossible = true;
          for(int i=0; i<N; ++i)
          	 for(int j=0; j<M; ++j)
          	 	 if(LargestRow[i] > Board[i][j] && LargestCol[j] > Board[i][j]) isPossible = false;
          printf("Case #%d: %s\n", caseNo, isPossible?"YES":"NO");
    }
    return 0;
}
