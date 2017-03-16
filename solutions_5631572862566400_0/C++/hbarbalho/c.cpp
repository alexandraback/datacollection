#include<iostream>
using namespace std;

long long solve(long long ID, long long *sol, long long *vis, long long size, long long *bffs, long long N){
  if(size==N+1){
//    cout << endl;
    return 0;
  }
  if(size==0){
//    cout << " "<<ID;
    sol[0]=ID;
    vis[ID]=1;
    long long resp = solve(bffs[ID],sol,vis,size+1,bffs,N)+1;
    vis[ID]=0;
    return resp;
  }else{
//    cout << " "<<ID;
    sol[size]=ID;
    vis[ID]=1;
    long long resp=-N-1;
    if(vis[bffs[ID]]){
      if(sol[0]==bffs[ID]){
        if(size>1)
          resp=1;
        else{
          resp=1;
          for(long long i=1;i<=N;++i){
            if(!vis[i]){
              long long tmp = solve(i,sol,vis,size+1,bffs,N)+1;
              if(tmp>resp)resp=tmp;
            }
          }  
        }
//        cout << endl;
      }else if(sol[size-1]==bffs[ID]){
        resp=1;
        for(long long i=1;i<=N;++i){
          if(!vis[i]){
            long long tmp = solve(i,sol,vis,size+1,bffs,N)+1;
            if(tmp>resp)resp=tmp;
          }
        }
      }else {
        resp = -N-1;
//        cout << "X"<<endl;
      }
    }else{
      resp = solve(bffs[ID],sol,vis,size+1,bffs,N)+1;
    }
    vis[ID]=0;
    return resp;
  }
}

int main(){
  long long t,T,N,i,bf;
  long long bffs[1001];
  long long sol[1001];
  long long vis[1001];
  long long resp,tmp;
  cin >> T;
  for(t=1;t<=T;++t){
    cin >> N;
    for(i=1;i<=N;++i){
      vis[i]=0;
      cin >> bffs[i];
    }
    resp=-1;
    for(i=1;i<=N;++i){
      //if(!vis[i]){
        tmp = solve(i,sol,vis,0,bffs,N);
        if(tmp>resp)resp=tmp;
      //}
    }
    cout << "Case #"<<t<<": "<<resp<<endl;
  }
  return 0;
}
