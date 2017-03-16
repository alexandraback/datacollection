#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 

const int MAXKEY = 210;
const int MAXCHEST = 210;
bool usedMain[MAXCHEST];
vector<int> solve() {
  int K,N;
  cin>>K>>N;
  int calcKeys[MAXKEY];
  int keys[MAXKEY];
  REP(i,MAXKEY) {
    keys[i] = 0;
    calcKeys[i]= 0;
  }
  REP(i,K) {
    int p;
    cin>>p;
    p--;
    keys[p]++;
    calcKeys[p]++;
  }
  
  vector<vector<int> > chest;
  vector<int> openKey;
  for(int i=0; i<N; i++) {
    int p,q;
    cin>>p>>q;
    vector<int>tmp;

    p--;
    calcKeys[p]--;
    openKey.push_back(p);
    for(int j=0; j<q; j++) {
      int r; cin>>r; r--;
      tmp.push_back(r);
      calcKeys[r]++;
    }
    chest.push_back(tmp);
  }
  vector<int> noSolution;
  for(int i=0; i<MAXKEY; i++) 
    if(calcKeys[i]<0) 
      return noSolution;
  
  vector<int> ans;
  
  REP(i,MAXCHEST) usedMain[i] = false;
  
  REP(turn,N) {
    bool update = false;;
    REP(chestNum, N) if(!usedMain[chestNum]) if(keys[openKey[chestNum]]>0){
      usedMain[chestNum] = true;
      keys[openKey[chestNum]]--;
      for(int i=0; i<chest[chestNum].size(); i++) {
	keys[chest[chestNum][i]]++;
      }
      bool ok = true; 
      {
	bool usedQueue[MAXCHEST];
	bool usedKeys[MAXKEY];
	queue<int> qu;
	vector<int> graph[MAXKEY];
	REP(i,MAXKEY) {
	  usedKeys[i] = false;
	  usedQueue[i] = false;
	}
	REP(i,N) if(!usedMain[i]) {
	  //	  cout<<"node"<<i<<endl;
	  int s = openKey[i];
	  usedKeys[s] = true;
	  REP(j,chest[i].size()) {
	    int t = chest[i][j];
	    graph[s].push_back(t);
	    //	    cout<<"edge"<<s<<" "<<t<<endl;
	  }
	}
	REP(i,MAXKEY) if(keys[i]>0) {
	  qu.push(i);
	  usedQueue[i] = true;
	}
	while(!qu.empty()) {
	  int cur = qu.front(); qu.pop();
	  //	  cout<<"cur"<<cur<<endl;
	  //	  usedQueue[cur] = true;
	  for(int i=0; i<graph[cur].size(); i++) {
	    int next = graph[cur][i];
	    if(!usedQueue[next]) {
	      qu.push(next);
	      usedQueue[next] = true;
	    }
	  }
	}
	/*
	REP(i,N) cout<<turn<<" "<<i<<" "<<usedQueue[i]<<endl;
	REP(i,3) cout<<keys[i]<<endl;
	REP(i,3) cout<<usedQueue[i]<<" "<<usedKeys[i]<<endl;
	*/
	REP(i,MAXKEY) if(!usedQueue[i] && usedKeys[i] ) ok = false;
	
      }
      if(!ok) {
	usedMain[chestNum] = false;
	keys[openKey[chestNum]]++;
	for(int i=0; i<chest[chestNum].size(); i++) {
	  keys[chest[chestNum][i]]--;
	}
      }
      else {
	update = true;
	ans.push_back(chestNum+1);
	break;
      }
    }
    if(!update) return noSolution;
  }
  return ans;
  
}



int main() {
  int t;
  cin>>t;
  REP(i,t) {
    vector<int> ans = solve();
    if(ans.empty())
      cout<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
    else {
      cout<<"Case #"<<i+1<<":";
      REP(x, ans.size()) 
	cout<<" "<<ans[x];
      cout<<endl;
    }  
  }
  
  return 0;
}

