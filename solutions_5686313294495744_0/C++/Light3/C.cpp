#include<bits/stdc++.h>
using namespace std;
/* M*N bigraph max matching  */
int M, N;
bool BPG[1000][1000];
bool __bpm__(int u, bool seen[], int match[]){
  for(int v=0;v<N;v++){

    if(BPG[u][v]&&!seen[v]){
      seen[v]=true;
      if(match[v]<0||__bpm__(match[v],seen,match)){
	match[v]=u;
	return true;
      }
    }
  }
  return false;
}

int __max_BPM__(){
  int match[N];
  memset(match,-1,sizeof(match));

  int result=0;
  for(int u=0;u<M;u++){
    bool seen[N];
    memset(seen,0,sizeof(seen));

    if(__bpm__(u,seen,match))
      result++;
  }
  return result;
}

int main(){
  int T,n;
  string First, Second;
  vector<pair<string,string> > initial;
  map<string,int>F,S;
  int counter=0, counter2=0;
  scanf("%d",&T);

  int index=0;
  while(T){
    T--;
    initial.clear();
    S.clear();
    F.clear();
    counter=counter2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      cin>>First;
      cin>>Second;
      initial.push_back(make_pair(First,Second));
      if(S.find(Second)==S.end())S[Second]=counter++;
      if(F.find(First)==F.end())F[First]=counter2++;
    }
    
    sort(initial.begin(),initial.end());
    for(int i=0;i<counter2;i++)
      for(int j=0;j<counter;j++)
	BPG[i][j]=0;
    M=counter2;
    N=counter;
    
    for(int i=0;i<n;i++){
      BPG[F[initial[i].first]][S[initial[i].second]]=1;
    }
    index++;
    //cout<<initial.size()<<" "<<S.size()<<" "<<counter<<endl;
    printf("Case #%d: %d\n",index,n-M-N+__max_BPM__() );//(dp1.size()+dp2.size())+counter)             ) 
  }

}
