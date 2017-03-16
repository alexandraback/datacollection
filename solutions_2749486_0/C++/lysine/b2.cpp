#include <iostream>
#include <algorithm>
#include <cmath>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int cs,x,y,cx,cy;

int main(){
  cin>>cs;
  rep(ii,cs){
    cin>>x>>y;cx=0;cy=0;
    cout<<"Case #"<<ii+1<<": ";
    while(cx!=x){
      if(cx>x){cout<<"EW";cx--;}
      else {cout<<"WE";cx++;}
    }
    while(cy!=y){
      if(cy>y){cout<<"NS";cy--;}
      else {cout<<"SN";cy++;}
    }
    cout<<endl;
  }



}
