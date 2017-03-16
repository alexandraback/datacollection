#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int N,E;

bool g[50][50];
vector<vector<int>> vic;
vector<pair<int,int>> vp;

bool done[50];


bool check(stack<int> curstack, int count){
  bool cp[50];
  copy(begin(done),end(done),begin(cp));  
  while(!curstack.empty()){
    int el=curstack.top();
    //cout<<"INTO "<<el<<" "<<count<<endl;
    curstack.pop();
    for(int v:vic[el]){
      if(!cp[v]){
	curstack.push(v);
	cp[v]=true;
	count++;
      }
    }
  }
  return count==N;
}

void solve(){
  cin>>N>>E;
  vp.clear();
  vp.resize(N);
  vic.clear();
  vic.resize(N);
  fill(done,done+50,false);

  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      g[i][j]=false;
  for(int i=0;i<N;i++){
    int v;    
    cin>>v;
    vp[i]=make_pair(v,i);
  }
  for(int i=0;i<E;i++){
    int f,t;
    cin>>f>>t;
    f--;
    t--;
    g[f][t]=true;
    g[t][f]=true;
    vic[f].push_back(t);
    vic[t].push_back(f);
  }
  sort(vp.begin(),vp.end());
  cout<<vp[0].first;
  stack<int> curstack;
  curstack.push(vp[0].second);
  done[vp[0].second]=true;
  for(int i=1;i<N;i++){
    int target;
    for(target=0;target<N;target++)
      if(!done[vp[target].second]){
	int t=vp[target].second;
	stack<int> curcopy=curstack;
	//cout<<"TEST"<<t<<" "<<curcopy.top()<<endl;
	while(true){
	  while(!curcopy.empty() && !g[curcopy.top()][t]){
	    curcopy.pop();
	  }
	  if(curcopy.empty())
	    break;
	  //	  cout<<"TESTINTERNO"<<t<<endl;
	  curcopy.push(t);
	  done[t]=true;
	  if(check(curcopy,i+1)){
	    break;
	  }else{
	    done[t]=false;
	    curcopy.pop();
	    curcopy.pop();
	  }
	}
	if(!curcopy.empty()){
	  //      	  cout<<"CORRECT"<<t<<endl;
	  curstack=curcopy;
	  break;
	}
      }
    //    cout<<"["<<target<<"]";
     cout<<vp[target].first;
  }

}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
    cout<<endl;
  }
}
