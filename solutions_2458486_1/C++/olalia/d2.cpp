#include<iostream>
#include<vector>
#include<queue>


using namespace std;



vector<vector<int> > e;


int N, K, nd;

vector<int> knippe;
vector<vector<int> > chest;
vector<int> keytype;
vector<int> done;

bool check(int nod){
  vector<int> done2=done;
  vector<int> knippe2=knippe;
  done2[nod]=true;
  for (int i=0; i<chest[nod].size(); ++i){
    knippe2[chest[nod][i]]++;
  }
  knippe2[keytype[nod]]--;
  queue<int> q;
  int nx=1;
  for (int i=0; i<N; ++i){
    if (done2[i])
      continue;
    if (knippe2[keytype[i]]>0){
      q.push(i);
      done2[i]=true;
      ++nx;
    }
  }
  
  while (q.size()>0){
    int noden=q.front();
    q.pop();
    for (int i=0; i<e[noden].size();++i){
      if (done2[e[noden][i]])
	continue;
      q.push(e[noden][i]);
      done2[e[noden][i]]=true;
      ++nx;
    }
  }
  return (nx+nd==N);
}


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cin>>K>>N;
    e=vector<vector<int> >(N, vector<int>());
    keytype=vector<int>(N, 0);
    knippe=vector<int>(200,0);
    chest=vector<vector<int> >(N,vector<int>());
    for (int i=0; i<K; ++i){
      int j; cin>>j;
      knippe[j-1]++;
    }
    nd=0;
    for (int i=0; i<N; ++i){
      int ti, ki; cin>>ti>>ki;
      keytype[i]=ti-1;
      for (int j=0; j<ki; ++j){
	int h; cin>>h;
	chest[i].push_back(h-1);
      }
    }
    for (int i=0; i<N; ++i)
      for (int j=0; j<N; ++j)
	for (int k=0; k<chest[i].size(); ++k)
	  if (chest[i][k]==keytype[j])
	    e[i].push_back(j);
    vector<int> ans;
    done=vector<int>(N,false);
    bool ja=true;
    
    while(nd<N && ja){
      int nd2=nd;
      
      for (int i=0; i<N; ++i){
	if (done[i]||knippe[keytype[i]]==0)
	  continue;
	if (check(i)){
	  
	  ans.push_back(i+1);
	  nd++;
	  for (int j=0; j<chest[i].size(); ++j)
	    knippe[chest[i][j]]++;
	  knippe[keytype[i]]--;
	  done[i]=true;
	  break;
	}
      }
      if (nd2==nd)
	ja=false;
    }
    cout<<"Case #"<<tc<<":";
    if (ja){
      for (int i=0; i<N; ++i)
	cout<<" "<<ans[i];
      cout<<endl;
    }
    else
      cout<<" IMPOSSIBLE"<<endl;
  }
  return 0;
}
      
  
