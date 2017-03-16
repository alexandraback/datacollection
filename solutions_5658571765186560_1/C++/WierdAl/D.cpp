#include<iostream>
#include <string>
using namespace std;

int min(int a,int b){
  if(a<=b)return a;
  else return b;
}

int max(int a,int b){
  if(a<=b)return b;
  else return a;
}

int main(){
  
  int T;
  cin >> T;
  
  for(int q=1;q<=T;q++){
    
    int X,R,C;
    
    cin >> X;
    cin >> R;
    cin >> C;
    
    bool ans = true;
    
    if(X>=7)ans=false;
    else if(X>R and X >C)ans=false;
    else if((R * C%X) != 0)ans =false;
    else if ( (X+1)/2 > min(R,C) )ans=false;
    else if (X==1 or X==2 or X==3)ans=true;
    else if(X==4){ans = min(R,C)>2 ;}
    else if(X==5){ans = !(min(R,C)==3 and max(R,C)==5) ;}
    else if(X==6){ans=min(R,C)>3;}
    
    if(ans){
      cout << "Case #" << q << ": "<<"GABRIEL"<<endl;
    }
    else{
      cout << "Case #" << q << ": "<<"RICHARD"<<endl;
    }
  }
  
  return 0;
}