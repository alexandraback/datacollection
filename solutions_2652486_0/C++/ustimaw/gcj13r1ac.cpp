#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int> > v;

void mkv(vector<int> c,int N,int M){
  if(N==0){
    v.push_back(c);
  }else{
    for(int i=2;i<=M;i++){
      vector<int> n=c;
      n.push_back(i);
      mkv(n,N-1,M);
    }
  }
}

int main(){
  int T,R,N,M,K;
  cin>>T>>R>>N>>M>>K;
  cout<<"Case #1:"<<endl;
  mkv(vector<int>(),N,M);
  while(R--){
    int p[12];
    for(int i=0;i<K;i++){
      cin>>p[i];
    }
    vector<vector<int> > pv(v.size(),vector<int>(N));
    for(int j=0;j<10000;j++){
      int b=rand()/(RAND_MAX+1.)*(1<<N);
      for(int k=0;k<v.size();k++){
	int cp=1;
	for(int l=0;l<N;l++){
	  if(b>>l&1){
	    cp*=v[k][l];
	  }
	}
	for(int i=0;i<N;i++){
	  pv[k][i]+=p[i]==cp;
	}
      }
    }
    int x=0;
    for(int i=0;i<pv.size();i++){
      if(*min_element(pv[i].begin(),pv[i].end())>*min_element(pv[x].begin(),pv[x].end())){
      x=i;
      }
    }
    for(int i=0;i<N;i++){
      cout<<v[x][i];
    }
    cout<<endl;
  }
  return 0;
}
    
