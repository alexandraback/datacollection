#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
int ten[]={1,10,100,1000,10000,100000,1000000,10000000};
int ct(int n){
  int res=0;
  while(n){
    res++;
    n/=10;
  }
  return res;
}
int main(int argc, const char *argv[])
{
  int T,A,B;
  cin>>T;
  for(int tm=1;tm<=T;tm++){
    cin>>A>>B;
    int res=0;
    for(int i=A;i<=B;i++){
      int n=ct(i),t=i;
      set<int> vis;
      for(int j=1;j<n;j++){
        int b=t%10;
        t=t/10+b*ten[n-1];
        if(b && t>i && t<=B && vis.find(t)==vis.end()){
          res++;
          vis.insert(t);
        }
      }
    }
    printf("Case #%d: %d\n",tm,res);
  }
  return 0;
}
