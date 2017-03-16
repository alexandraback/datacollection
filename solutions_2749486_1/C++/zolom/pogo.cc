#include <iostream>
#include <string>
#include <set>
#include <stdio.h>
#include <cmath>

using namespace std;

int debug =0;

set<int> subsetwithsum(int n, int sum){
  if(debug) cout<<"sum "<<sum<<endl;
  int acc = 0;
  set<int> ret;
  for(int k=n; k>=1; k--){
    if(acc+k<=sum){
      ret.insert(k);
      acc+=k;
    }
  }
  if(debug) {
    for(set<int>::iterator i=ret.begin(); i!=ret.end(); i++){
    cout<<*i<<" ";
  }
  cout<<endl;
  }
  return ret;
}

int main(int argc, char**argv){
  int T;
  cin>>T;
  for(int i=1; i<=T; i++){
    cout<<"Case #"<<i<<": ";
    int X, Y;
    cin>>X>>Y;
    int xneg=0, yneg=0;
    if(X<0) xneg=1;
    if(Y<0) yneg=1;
    X = abs(X);
    Y = abs(Y);
    int k=0;
    if(debug) cout<<"X"<<X<<"Y"<<Y<<endl;
    while(k*(k+1)/2<(X+Y))
      k++;
    while( (k*(k+1)/2-(X+Y) )%2)
      k++;
    if(debug) cout<<"k"<<k<<endl;
    set<int> negate = subsetwithsum(k, ( (k*(k+1))/2-(X+Y) )/2);
    if(debug) cout<<"here\n";
    set<int> inY = subsetwithsum(k, Y+( (k*(k+1))/2-(X+Y) )/2);
    for(int l=1; l<=k; l++){
      if(inY.find(l)!=inY.end()&&negate.find(l)==negate.end()){
	cout<<(yneg?"S":"N");
      }
      else if(inY.find(l)==inY.end()&&negate.find(l)==negate.end()){
	cout<<(xneg?"W":"E");
      }
      else if(inY.find(l)!=inY.end()&&negate.find(l)!=negate.end()){
	cout<<(xneg?"E":"W");
      }
      else if(inY.find(l)==inY.end()&&negate.find(l)!=negate.end()){
	cout<<(yneg?"N":"S");
      }
    }
    cout<<endl;
  }
}
