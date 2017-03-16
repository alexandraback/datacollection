#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

int T, n, N;

vector<ld> D;
vector<int> H;
vector<ld> M;


int main(){
  cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cin>>n;
    D=vector<ld>(n,0);
    H=vector<int>(n,0);
    M=vector<ld>(n,0);
    N=0;
    for (int i=0; i<n; ++i){
      cin>>D[i]>>H[i]>>M[i];
      N+=H[i];
    }
    cout<<"Case #"<<tc<<": ";
    if (N<2){
      cout<<0<<endl;
      continue;
    }
    int co=0;
    vector<vector<ld> > e(N, vector<ld>(2,0));
    for (int i=0; i<n; ++i){
      for (int j=0; j<H[i]; ++j){
	e[co][0]=(360.0-D[i])*(M[i]+j)/360.0;
	e[co][1]=(720.0-D[i])*(M[i]+j)/360.0;
	++co;
      }
    }
    // for (int i=0; i<N; ++i){
    //   for (int j=0; j<2; ++j)
    // 	cout<<e[i][j]<<" ";
    //   cout<<endl;
    // }
    ld eps=.0001;
    if (e[1][1]<e[0][0] ||  abs(e[1][1]-e[0][0])<eps || e[0][1]<=e[1][0] || abs(e[0][1]-e[1][0])<eps)
      cout<<1<<endl;
    else
      cout<<0<<endl;
    //cout<<e[1][1]<<" "<<e[0][0]<<" "<<e[0][1]<<" "<<e[1][0]<<endl;
      
  }
  return 0;
}
