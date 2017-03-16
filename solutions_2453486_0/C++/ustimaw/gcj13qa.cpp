#include<iostream>
#include<string>

using namespace std;

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    string g[4];
    for(int j=0;j<4;j++){
      cin>>g[j];
    }
    cout<<"Case #"<<i<<": ";
    bool nc=false;
    for(int j=0;j<2;j++){
      char c="XO"[j];
      bool d[2]={};
      for(int k=0;k<4;k++){
	bool rc[2]={};
	for(int l=0;l<4;l++){
	  rc[0]|=g[k][l]!='T'&&g[k][l]!=c;
	  rc[1]|=g[l][k]!='T'&&g[l][k]!=c;
	  nc|=g[k][l]=='.';
	}
	if(!rc[0]||!rc[1]){
	  cout<<c<<" won"<<endl;
	  goto next;
	}
	d[0]|=g[k][k]!='T'&&g[k][k]!=c;
	d[1]|=g[k][3-k]!='T'&&g[k][3-k]!=c;
      }
      if(!d[0]||!d[1]){
	cout<<c<<" won"<<endl;
	goto next;
      }
    }
    cout<<(nc?"Game has not completed":"Draw")<<endl;
  next:
    ;
  }
  return 0;
}
