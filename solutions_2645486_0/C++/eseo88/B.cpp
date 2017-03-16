#include<iostream>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

typedef long long int LL;
LL vs[100000];
LL E,R;
int n;

LL solve(int cur, int e) {
  if (cur == n){
    return 0;
  }
  LL maxv = 0, temp;
  for(int u =0; u<=e; ++u) {
    temp = solve(cur+1, MIN(e-u+R, E));
    temp += u*vs[cur];
    maxv = MAX(maxv, temp);
  }
  return maxv;
}



int main() {

  int cas;
  cin>>cas;

  for(int ca=1; ca<=cas; ++ca) {
    cin>>E>>R>>n;
    for(int i=0; i<n; ++i){
      cin>>vs[i];
    }
    cout<<"Case #"<<ca<<": "<<solve(0, E)<<endl;
  }

}
