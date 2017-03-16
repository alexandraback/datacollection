#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    int E,R,N;
    cin>>E>>R>>N;
    map<int,int>m[10001];
    m[0][E]=0;
    for(int j=0;j<N;j++){
      int v;
      cin>>v;
      for(map<int,int>::iterator it=m[j].begin();it!=m[j].end();it++){
	int ce=min(E,R+it->first);
	for(int i=0;i<1000;i++){
	  int ne=min(ce,max(0,E-R*i));
	  m[j+1][ne]=max(m[j+1][ne],it->second+v*(ce-ne));
	}
	m[j+1][0]=max(m[j+1][0],it->second+v*ce);
      }
    }
    cout<<"Case #"<<i<<": "<<m[N][0]<<endl;
  }
}
