#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
  int T;
  int N;
  int p;
  int S;
  int test;
  cin >> T;
  int i=0;
  int j=0;
  int ans=0;
  int beta =0;
  for (i =0;i < T; i ++){
    ans =0;
    beta =0;
    cin >> N;
    cin >> S;
    cin >> p;
  //  cout << N << S << p ;
    for( j = 0;j< N;j++){
     cin >> test;
 //    cout << test;
     if (test > 3*(p-1)){
       ans = ans+1;
     }     
     if (test == 3*(p-1) && test  > 0){
       beta = beta+1;
     }     
     if (test == 3*(p-1) -1 && test  > 0){
       beta = beta+1;
     }    
    } 
    ans = ans + min(beta,S);
    cout << "Case #" << i+1 << ": " << ans <<  endl; 
  
  }  
  
  return 0;
}