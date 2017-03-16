#include <iostream>
#include <vector>
using namespace std;

void calculate(int* maxi, int curE, int E, int R, int N, vector<int> v, int constE, int cur){
  if (cur==N){
    if (curE>*maxi) *maxi=curE;
    return;
  }
  for (int i=0; i<=E; i++)
    calculate(maxi,curE+i*v[cur], E-i+R>=constE?constE:E-i+R,R,N,v,constE,cur+1);
}

int main(){
  int T,E,R,N,i,j,k;
  cin>>T;
  for (i=1; i<=T; i++){
    cout << "Case #" << i << ": ";
    cin>>E>>R>>N;
    vector<int> v(N);
    for (j=0; j<N; j++) cin>>v[j];
    k=-1;
    calculate(&k,0,E,R,N,v,E,0);
    cout << k << endl;
  }
  return 0;
}
