#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int n; cin>>n;
    vector<double> u(n, 0), v(n,0);
    for (int i=0; i<n; ++i)
      cin>>u[i];
    for (int i=0; i<n; ++i)
      cin>>v[i];
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    int a=0;
    int j=0;
    for (int i=0; j<n; ++i){
      while(j<n && u[j]<v[i])
	++j;
      if (j<n){
	++a;
	++j;
      }
    }
    int b=0;
    j=0;
    for (int i=0; j<n; ++i){
      while(j<n && v[j]<u[i])
	++j;
      if (j<n){
	++b;
	++j;
      }
    }
    cout<<"Case #"<<tc<<": "<<a<<" "<<n-b<<endl;
  }
  return 0;
}
