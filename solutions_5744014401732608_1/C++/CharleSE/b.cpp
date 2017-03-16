#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<stack>
using namespace std;
int main(){
  long long int T, B, M;
  cin >> T;
  for(int i=1; i<=T; i++){
    cin >> B >> M;
    vector<vector<int> > way(B, vector<int>(B));
    long long int res = 0;
    int j;
    for(j=B-1; res < M && j > 0; j--){
      way[0][j] = 1;
      if(res * 2 <= M){
        for(int k=B-1; k>j; k--){
          way[j][k] = 1;
        }
        if(j < B-1) res *= 2;
        else res = 1;
      }
      else break;
    }
    printf("Case #%d: ", i);
    if(j == 0 && res < M){
      printf("IMPOSSIBLE\n");
      continue;
    }
    else{
      printf("POSSIBLE\n");
      if(res < M){
        way[j][B-1] = 1;
        res += 1;
        long long int rest = M - res;
        for(int k = B-2; k > j; k--){
          way[j][k] = (rest % 2);
          rest = rest / 2;
        }
      }
      for(int k=0; k<B; k++){
        for(int l=0; l<B; l++)
          printf("%d", way[k][l]);
        printf("\n");
      }
    }
  }
  return 0;
}
