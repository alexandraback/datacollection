#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll Da,Ha,Ma;
ll Db,Hb,Mb;
#define eps (1e-10)

ll solve(){
  if(Ma==Mb)return 0;
  if(Ma>Mb){
    swap(Da,Db);
    swap(Ha,Hb);
    swap(Ma,Mb);
  }
  double va=360.0/Ma;
  double vb=360.0/Mb;
  double xa=360.0-Da;
  double xb=360.0-Db;

  double t=xa/va;
  // cout<<xa<<' '<<va<<' ';
  //  cout<<t<<endl;
  
  xb-=vb*t;
  if(xb<eps)return 0;
  
  
  
  double t2=xb/vb; 
  ll cnt = t2 / va*360.0;

  return min(Ha*cnt,Hb);
  
}

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>n;
    cin>>Da>>Ha>>Ma;
    cin>>Db>>Hb>>Mb;
    cout<<"Case #"<<tc<<": "<<solve()<<endl;
  }
  return 0;
}
