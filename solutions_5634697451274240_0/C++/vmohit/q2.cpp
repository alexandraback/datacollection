#include <iostream>
using namespace std;

int main(){

int Te;
cin>>Te;

for(int te=0;te<Te;te++){
  string s;
  cin>>s;
  int n=s.size();
  char tmp='-';
  int i=n-1,ans=0;
  while(i>=0){
    if(s[i]==tmp){
      while(s[i]==tmp){
        i--;
        if(i<0)break;
      }
      if(tmp=='-')tmp='+';
      else{tmp='-';}
      ans++;
    }
    else{
      i--;
    }
  }
  cout<<"Case #"<<te+1<<": "<<ans<<endl;

}
return 0;

}
