/*GCJ R1C B*/
#include<iostream>
#include<string>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int x,y;
void main2(){
  string ans="";
  cin>>x>>y;
  if(x<0){
    for(int i=0;i<abs(x);i++)ans+="EW";
  }else{
    for(int i=0;i<abs(x);i++)ans+="WE";
  }
  if(y<0){
    for(int i=0;i<abs(y);i++)ans+="NS";
  }else{
    for(int i=0;i<abs(y);i++)ans+="SN";
  }
  cout<<ans<<endl;
}
int main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    printf("Case #%d: ",t);
    main2();
  }
}
