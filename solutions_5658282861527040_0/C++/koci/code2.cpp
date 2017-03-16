#include <iostream>

using namespace std;

int main(){
  
  int n;
  cin >> n;
  for(int stevec=1;stevec<=n;stevec++){
    int a,b,k;
    cin >> a >> b >> k;
    int rez=0;
    for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
	if((i & j) < k){rez++;}
      }
    }
    cout << "Case #" << stevec << ": " << rez << '\n';
  }
  return 0;
}