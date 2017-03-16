#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int K,N;
int a[200];
int Ti[200];
vector<int> k[20];
bool p[1<<20];

bool dfs(int n,int b,const multiset<int> &v){
  if(p[b]++){
    return false;
  }else if(n==N){
    for(int i=0;i<n;i++){
      cout<<' '<<a[i];
    }
    cout<<endl;
    return true;
  }else{
    for(int i=0;i<N;i++){
      if(!(b>>i&1)&&v.count(Ti[i])){
	a[n]=i+1;
	multiset<int> nv=v;
	nv.insert(k[i].begin(),k[i].end());
	nv.erase(nv.find(Ti[i]));
	if(dfs(n+1,b|1<<i,nv)){
	  return true;
	}
      }
    }
    return false;
  }
}

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    fill(p,p+(1<<20),false);
    cin>>K>>N;
    multiset<int> s;
    while(K--){
      int k;
      cin>>k;
      s.insert(k);
    }
    for(int j=0;j<N;j++){
      int Ki;
      cin>>Ti[j]>>Ki;
      k[j].resize(Ki);
      while(Ki--){
	cin>>k[j][Ki];
      }
    }
    cout<<"Case #"<<i<<":";
    if(!dfs(0,0,s)){
      cout<<" IMPOSSIBLE"<<endl;
    }
  }
  return 0;
}
