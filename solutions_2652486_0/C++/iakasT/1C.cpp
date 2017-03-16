#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int N = 3;
const int M = 5;
void print(vector<int> & a){
  for(int i=0;i<a.size();i++){
    cout << a[i] <<" " ;
  }
  cout << endl;
}

map<int,vector<vector<int> > > Map;
vector<vector<int> > all;
void fun(int n,int m,int cur,vector<int> ar){
  if (cur == n){
    sort(ar.begin(),ar.end());
    all.push_back(ar);
    return;
  }
  for(int i=2;i <= m;i++){
    ar[cur] = i;
    fun(n,m,cur+1,ar);
  }
}

int main(){
  vector<int> ar(N);
  fun(N,M,0,ar);
  sort(all.begin(),all.end());
  all.erase(unique(all.begin(),all.end()),all.end());
  for(int i=0;i<all.size();i++){
    //print(all[i]);
    for(int j=0;j<(1<<N);j++){
      int val = 1;
      for(int k=0;k<N;k++){
	if ((1<<k)&j){
	  val *= all[i][k];
	}
      }
      Map[val].push_back(all[i]);
    }
  }
  map<int,vector<vector<int> > >::iterator itr = Map.begin();
  while(itr != Map.end()){
    sort((*itr).second.begin(), (*itr).second.end());
    (*itr).second.erase(unique((*itr).second.begin(),(*itr).second.end()),(*itr).second.end());
    itr++;
  }

  int te;
  cin>>te;
  cout <<"Case #1:" << endl;
  int r,m,n,K;
  cin>>r>>m>>n>>K;
  while(r--){
    vector<int> in(K);
    vector<vector<vector<int> > > fit(K);
    for(int i = 0;i < K;i++){
      cin>>in[i];
      fit[i] = Map[in[i]];
      /*
      cout <<"possible: " << in[i] << endl;
      for(int j=0;j<fit[i].size();j++){
	print(fit[i][j]);
     }
      */
    }

    vector<vector<int> > ans = fit[0];
    for(int i=1;i < K;i++){
      vector<vector<int> > next;
      for(int j=0;j<ans.size();j++){
	vector<int> cur = ans[j];
	for(int k=0;k<fit[i].size();k++){
	  if (cur == fit[i][k]){
	    next.push_back(cur);
	    break;
	  }
	}
      }
      ans = next;
    }
    for(int i=0;i<ans[0].size();i++){
      cout << ans[0][i];
    }
    cout << endl;
  }
  return 0;
}
