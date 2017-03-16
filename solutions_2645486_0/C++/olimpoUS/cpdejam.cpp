#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <utility>
#include <ctime>
#include <limits.h>
using namespace std;
long long E,R,N;
long long V[15],D[15][15];
void Solve(){
  cin >> E >> R >> N;
  memset(D,0,sizeof(D));
  for(int i = 0 ; i < N ; i++) {
     cin >> V[i];
     for(int j = 0 ; j <= E ; j++)
     {
       //cout << D[i][j] << " ";
       for(int k = 0 ; k <= j; k++)
         D[i+1][min(E,j-k+R)] = max(D[i+1][min(E,j-k+R)] , D[i][j] + k*V[i]);
     }
     //cout << endl;
  }
  cout <<D[N][min(E,R)] <<endl;
}
int main(){
  freopen("inp.txt","r",stdin);
  freopen("outp.txt","w",stdout);
  int te;
  scanf("%d",&te);
  for(int t = 1 ; t <= te ; ++t){
     printf("Case #%d: ",t);
     Solve();
  }
  return 0;
}
