#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

vector<int> edges[1111];

int depth(int x,int p){
  int ans=0;
  for(auto e:edges[x]){
    if(e==p)continue;
    ans=max(ans,depth(e,p));
  }
  return ans+1;
}

int main(){
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
      edges[i].clear();
    }
    int F[1111];
    for(int i=0;i<N;i++){
      cin>>F[i];
      F[i]--;
      edges[F[i]].push_back(i);
    }
    int mxl=0;
    for(int i=0;i<N;i++){
      bool u[1111]={};
      int c;
      int l=0;
      for(c=i;!u[c];c=F[c]){
	u[c]=true;
	l++;
      }
      if(c==i){
	mxl=max(mxl,l);
      }
    }
    vector<int> v;
    bool u[1111]={};
    for(int i=0;i<N;i++){
      if(u[i])continue;
      if(F[F[i]]==i){
	v.push_back(depth(i,F[i])+depth(F[i],i));
	u[F[i]]=true;
      }
    }
    bitset<1024> dp;
    dp[0]=true;
    for(auto e:v){
      dp|=dp<<e;
    }
    for(int i=N;;i--){
      if(dp[i]){
	mxl=max(mxl,i);
	break;
      }
    }
    cout<<"Case #"<<t<<": "<<mxl<<endl;
  }
}

