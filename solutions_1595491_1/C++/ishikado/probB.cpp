#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int m,s,p;
    cin>>m>>s>>p;
    int res=0;
    int up1=0;
    int dn1=0;
    for(int j=0;j<m;j++){
      int num;
      cin>>num;
      if(num<=1){
	if(p<=num)res++;
      }
      else if(num%3==2){
	if(num/3+2==p)up1++;
	else if(num/3+2>p)res++;
      }
      else if(num%3==0){
	if(num/3+1==p)up1++;
	else if(num/3+1>p)res++;
      }
      else{
	if(num/3+1>=p)res++;
      }
    }
    cout<<"Case #"<<i+1<<": "<<res+min(up1,s)<<endl;
  }
  
  
  return 0;
}
