#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>

using namespace std;

typedef long long ll;

int T, n, N;

vector<ll> D;
vector<int> H;
vector<ll> M;
vector<ll> tim;


int main(){
  cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cin>>n;
    D=vector<ll>(n,0);
    H=vector<int>(n,0);
    M=vector<ll>(n,0);
    N=0;
    for (int i=0; i<n; ++i){
      cin>>D[i]>>H[i]>>M[i];
      N+=H[i];
    }
    tim=vector<ll>(N,0);
    int co=0;
    for (int i=0; i<n; ++i)
      for (int j=0; j<H[i];++j){
	tim[co]=(360-D[i])*(M[i]+j);
	++co;
      }
    sort(tim.begin(), tim.end());
    ll ans=N;
    for (int k=0; k<N; ++k){
      ll ans2=0;
      for (int i=0; i<n; ++i)
	for (int j=0; j<H[i];++j){
	  ll q=(tim[k]+D[i]*(M[i]+j))/360/(M[i]+j);
	  if (q==0)
	    ans2+=1;
	  else
	    ans2+=q-1;
	}
      ans=min(ans, ans2);
    }


    cout<<"Case #"<<tc<<": "<<ans<<endl;
  }
  return 0;
}
