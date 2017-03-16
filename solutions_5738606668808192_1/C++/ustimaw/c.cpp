#include<iostream>
#include<string>

using namespace std;

int main(){
  int T,N,J;
  cin>>T>>N>>J;
  cout<<"Case #1:"<<endl;
  for(unsigned i=(1u<<N-1)+1;J;i+=2){
    int s=0;
    for(unsigned j=0,k=i;k;k>>=1,j++){
      if(k&1){
	s+=j%2-!(j%2);
      }
    }
    if(!s){
      string bin;
      for(auto j=i;j;j>>=1){
	bin+=char('0'+j%2);
      }
      cout<<string(bin.rbegin(),bin.rend())<<" 3 4 5 6 7 8 9 10 11"<<endl;
      J--;
    }
  }
}
