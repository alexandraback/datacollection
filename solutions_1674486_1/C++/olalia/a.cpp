#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>




using namespace std;

vector<vector<int> > M;

int main(){
  int T; cin>>T;
  int m;
  for (int tc=1;tc<=T;tc++){
    int N; cin>>N;
    M=vector<vector<int> >(N,vector<int>());
    for (int i=0;i<N;i++){
      cin>>m;
      M[i]=vector<int>(m,0);
      for (int j=0;j<m;++j){
	cin>>M[i][j];
	M[i][j]--;
      }
    }
    bool ja=true;
    for (int i=0;i<N && ja;i++){
      queue<int> q=queue<int>();
      vector<bool> B=vector<bool>(N,true);
      q.push(i);
      
      while (q.size()!=0 && ja){
	int k=q.front();
	q.pop();
	for (int j=0;j<M[k].size();++j){
	  if (!B[M[k][j]]){
	    ja=false;
	    break;
	  }
	  if (B[M[k][j]]){
	    q.push(M[k][j]);
	    B[M[k][j]]=false;
	  }
	}
      }
    }
	

    cout<<"Case #"<<tc<<": ";
    if (ja)
      cout<<"No";
    else
      cout<<"Yes";
    cout<<endl;
  }


  return 0;
}
