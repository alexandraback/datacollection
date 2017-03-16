#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    int N,M;
    cin>>N>>M;
    int g[100][100];
    for(int j=0;j<N;j++){
      for(int k=0;k<M;k++){
	cin>>g[j][k];
      }
    }
    bool no=false;
    for(int j=0;j<N;j++){
      for(int k=0;k<M;k++){
	bool f[2]={};
	for(int l=0;l<100;l++){
	  f[0]|=l<N&&g[j][k]<g[l][k];
	  f[1]|=l<M&&g[j][k]<g[j][l];
	}
	no|=f[0]&&f[1];
      }
    }
    cout<<"Case #"<<i<<": "<<(no?"NO":"YES")<<endl;
  }
  return 0;
}
