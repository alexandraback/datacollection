#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){
  int T,R,N,M,K;
  cin>>T>>R>>N>>M>>K;
  cout<<"Case #1:"<<endl;
  while(R--){
    int n[12];
    int p[13]={};
    for(int i=0;i<M;i++){
      cin>>n[i];
      for(int j=0;j<10;j++){
	int m=n[i];
	while(m!=1){
	  int d=rand()/(RAND_MAX+1.)*(M-1)+2;
	  if(m%d==0){
	    p[d]++;
	    m/=d;
	  }
	}
      }
    }
    for(int i=0;i<N;i++){
      int x=max_element(p,p+13)-p;
      cout<<x;
      p[x]/=2;
    }
    cout<<endl;
  }
  return 0;
}
