#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>





using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> wi;





using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    ll b, m; cin>>b>>m;
    if (m>(1<<(b-2))){
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    cout<<"POSSIBLE\n";
    vector<vector<int> > u(b,vector<int>(b,0));
    if (m==(1<<(b-2))){
      for (int i=0; i<b; ++i){
	for (int j=0; j<b; ++j){
	  cout<<(j>i);
	}
	cout<<endl;
      }
      continue;
    }
    for (int i=0; i<b-1; ++i){
      u[0][i]=!!(m&(1<<(b-2-i)));
    }
    for (int i=0; i<b; ++i){
      if (u[0][i]){
	for (int j=i; j<b; ++j)
	  for (int k=j+1; k<b; ++k)
	    u[j][k]=1;
	break;
      }
    }
    for (int i=0; i<b; ++i){
      for (int j=0; j<b; ++j)
	cout<<u[i][j];
      cout<<endl;
    }




  }



  return 0;
}
