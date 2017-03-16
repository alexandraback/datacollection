#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    vector<int> v(1000, 0);
    int n, a; cin>>n;
    for (int i=0; i<n; ++i){
      cin>>a; v[a-1]++;
    }
    vector<int> u=vector<int>(),N=vector<int>();
    for (int i=999; i>-1; --i){
      if (v[i]){
	u.push_back(i+1);
	N.push_back(v[i]);
      }
    }
    int ans=u[0];
    for (int i=1; i<u[0]; ++i){
      int hei=0;
      for (int j=0; j<u.size(); ++j)
	hei+=N[j]*((u[j]-1)/i);
      ans=min(ans, hei+i);
    }
    cout<<"Case #"<<tc<<": "<<ans<<endl;
  }
  return 0;
}
