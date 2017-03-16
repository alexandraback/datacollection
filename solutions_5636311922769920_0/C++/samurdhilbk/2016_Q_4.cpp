#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){

  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    ll K,C,S;
    cin>>K>>C>>S;
    cout<<"Case #"<<i+1<<": ";
    for(ll j=0;j<S;j++) cout<<j*(ll)pow((double)K,(double)(C-1))+1L<<" ";
    cout<<endl;
  }
}