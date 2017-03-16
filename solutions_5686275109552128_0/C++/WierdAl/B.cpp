#include<iostream>
#include <string>
using namespace std;

int min(int a,int b){
  if(a<=b)return a;
  else return b;
}

int main(){
  
  int T;
  cin >> T;
  
  for(int q=1;q<=T;q++){
    
    int D;
    cin >> D;
    
    int P[D] ;
    int ans=0;
    
    int max=0;
    for(int j=0;j < D; j++){
      cin >> P[j]; 
      if(P[j]>max){max=P[j];}
      //cout << a[j] << endl;
    }
    ans = max;
    
    int z = 2;
    
    while(z < ans){
      int sum=0;
      for(int j=0;j < D;j++){
	sum+= ( (P[j]-1)/z ) ;
      }
      ans = min (ans,sum+z);
      z += 1;
    }
    cout << "Case #" << q << ": "<<ans<<endl;
  }
  
  return 0;
}