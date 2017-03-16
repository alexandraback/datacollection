#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<algorithm>
#include<cmath>


using namespace std;


typedef long long ll;

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int e, r, n; cin>>e>>r>>n; 
    vector<int> v(n,0);
    for (int i=0; i<n; ++i)
      cin>>v[i];
    vector<int> w(n,0);
    for (int i=0; i<n; ++i){
      int c=0;
      while(i+c+1<n && v[i+1+c]<v[i])
	++c;
      if (i+c+1==n)
	w[i]=-1;
      else
	w[i]=c+1;
    }
    ll ans=0;
    int ener=e;
    ll use, gain;

    for (int i=0; i<n; ++i){
      ener=min(ener+r, e);
      if (w[i]==-1)
	use=ener;
      else
	use=min(max(ener+r*w[i]-e, 0), ener);
      ener-=use;
      gain=v[i];
      ans+=use*gain;
    }





    cout<<"Case #"<<tc<<": "<<ans<<endl;;
  }
  return 0;
}
