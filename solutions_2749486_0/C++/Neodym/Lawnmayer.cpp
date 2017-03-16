#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

  ifstream f("input.txt");
  ofstream of("output.txt");

  void Solve(){

  long tecx=0;
  long tecy=0;

  long X,Y;

  f>>X>>Y;

  if(X>0)while(tecx!=X)of<<"WE",tecx++;
  if(X<0)while(tecx!=X)of<<"EW",tecx--;


  if(Y>0)while(tecy!=Y)of<<"SN",tecy++;
  if(Y<0)while(tecy!=Y)of<<"NS",tecy--;


  }





int main(){

  long T;

  f>>T;

  for(long i=1;i<=T;++i){
  of<<"Case #"<<i<<": ";Solve();of<<"\n";
  }


return 0;
}
