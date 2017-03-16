#include <iostream>
using namespace std;

int main(){
  int t,m,n,i,j,k;
  bool a[2000];
  for (i=0; i<2000; i++) a[i]=false;
  a[1]=true;
  a[4]=true;
  a[9]=true;
  a[121]=true;
  a[484]=true;
  cin>>t;
  for(i=1;i<=t;i++){
    cout << "Case #" << i << ": ";
    cin>>m>>n;
    k=0;
    for(j=m; j<=n;j++) if (a[j]) k++;
    cout << k << endl;
  }
  return 0;
}
