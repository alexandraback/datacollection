#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 100;

int A[MAX_N][MAX_N],v[MAX_N];
int E,R,N;

int f(int d,int e){
  if(e > E) e = E;
  if(A[d][e] >= 0) return A[d][e];
  if(d == N) return 0;
  
  int best = 0;
  for(int i=0;i<=e;i++)
    best = max(v[d]*i + f(d+1,e-i+R),best);
  return A[d][e] = best;
}

void do_case(){
  cin >> E >> R >> N;
  for(int i=0;i<N;i++)
    cin >> v[i];
  
  for(int i=0;i<=N;i++)
    for(int j=0;j<=E;j++)
      A[i][j] = -1;
  
  cout << f(0,E) << endl;
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": "; do_case();
  }
  return 0;
}
