#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (1<<26)
#define MAX 1000001
int d[MAX];


ll rv(ll x){
  stringstream ss,s2;
  ss<<x;
  string a;
  ss>>a;
  reverse(a.begin(),a.end());
  s2<<a;
  ll res;
  s2>>res;
  return res;
}



int main(){
  for(int i=0;i<MAX;i++)d[i]=INF;
  queue<ll> Q;
  Q.push(1);
  d[1]=1;
  while(!Q.empty()){
    ll p=Q.front();Q.pop();
    ll q=rv(p);

    if(q<MAX&&d[q]==INF){
      d[q]=d[p]+1;
      Q.push(q);
    }
    q=p+1;
    if(q<MAX&&d[q]==INF){
      d[q]=d[p]+1;
      Q.push(q);
    }
  }



  
  int Tc;
  ll x;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>x;
    cout<<"Case #"<<tc<<": "<<d[x]<<endl;
  }
}
