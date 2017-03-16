#include<iostream>
#include <string>
using namespace std;

int main(){
  
  int T;
  cin >> T;
  
  for(int q=1;q<=T;q++){
    
    int n;
    cin >> n;
    
    int a[n] ;
    string str;
    int ans=0;
    int standing=0;
    
    cin >> str;

    for(int j=0;j <= n; j++){
      a[j] = str[j] - '0';
      //cout << a[j] << endl;
    }
    standing += a[0];
    
    for(int j=1;j<=n;j++){
      if(standing>=j){
	standing+=a[j];
      }
      else{
	int temp=(j-standing);
	ans+=temp;
	standing=standing + a[j]+temp;
      }
            
    }
    cout << "Case #" << q << ": "<<ans<<endl;
  }
  
  return 0;
}