#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<numeric>
using namespace std;

 


void  dfs(const vector<vector<int> > &f,const vector<long>& s, int sum, int k ,  vector<int>  res){

  //  cout<<"enter "<< sum<<" "<<k<<endl;
  if (sum==0){
    for (int i=res.size()-1;i>=0;i--) {
      cout<<res[i];
      if ( i) cout<<" ";
    }
    cout<<endl;
    return;
  }

  if ( f[k-1][sum] ){
    //    cout<< " go directly "<<endl;
    dfs(f,s,sum,k-1,res);
  }

  int i=k-1;
  {
    if ( sum>=s[i] && f[k-1][sum-s[i]] ){
      vector<int> res2=res;
      res2.push_back(s[i]);

      //      cout<<" tkae "<<s[i]<<" "<<sum<<" "<<k <<endl;

      dfs( f, s, sum-s[i], k-1,res2);

    }
  }

}


int main(){

  freopen("in.dat","r",stdin);
  int T,N; 
  cin>>T; 

  for (int iT=1;iT<=T;iT++){
    cout<<"Case #"<<iT<<":"<<endl;
 
    cin>>N;
    
    vector<long> s; 
    for(int i=0;i<N;i++) {
      long a; 
      cin>>a;
      s.push_back(a);
    }
    
    long sum= accumulate(s.begin(),s.end(),0);
    
    vector<vector<int> > f(N+2),r(N+2);

    for (int i=0;i<=N;i++) {
      f[i].resize(sum+10);
      r[i]=f[i];
    }

    f[0][0]=1;

    bool flag=false;
    for ( int i=1;i<=N;i++) {
      if (flag) break;
      int elt= s[i-1];
      for (int j=0;j<f[i-1].size();j++){
	if (f[i-1][j]) {
	  f[i][j]++;
	  f[i][j+ elt]+=f[i-1][j];
	}
      }

      for ( int j=0;j<f[i].size();j++) 
	if (f[i][j]>1) {
	  vector<int> res;
	  //	  cout<<" res "<<i<<" "<<j<<endl;
	  dfs( f, s,j, i, res);
	  flag=true;
	  break;
	}
    }



    if (!flag)  cout<<"Impossible"<<endl;


  }

  return 0 ;
}
