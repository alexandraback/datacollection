#include <bits/stdc++.h>
using namespace std;

int ntest;
int n,bff[2000],x;

bool vis[2000];
bool cf[2000];

vector<int> dfs(int x, vector<int> cur) {  
  if(vis[x]) return cur;
  vis[x] = true;    
  
  if( bff[bff[x] ] == x ){      
      return cur;
  }
  
  cur.push_back(x);
  
  return dfs(bff[x], cur);
}



void solve(int test) {
    memset(cf,0,sizeof cf);
    cout << "Case #" << test+1 << ": ";
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> x; x--;
      bff[i] = x;
    }
    int mxloop = 0;
    for(int i=0; i<n; i++){
      memset(vis,0,sizeof vis);
      vector<int> temp;
      //cout << "DFS " << i << endl;
      vector<int> seg = dfs(i,temp);
      if(  seg.size() && bff[seg[ seg.size()-1 ] ] == i  ) mxloop = max(mxloop, (int) seg.size() );
    }
    int cnt=0;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        if(bff[i] == j && bff[j] == i ){
          cf[i] = cf[j] = 1;
          cnt++;
        }
      }
    }
    if(cnt == 0) cout << mxloop << endl;
    else{      
      int res = cnt*2;
      for(int i=0; i<cnt*2; i++){        
  		int target = -1;
  		int maxSeg = 0;
        for(int j=0; j<n; j++){			
  			if(!cf[j]) {
  				vector<int> temp;
  				memset(vis,0,sizeof vis);
  				vector<int> segT = dfs(j,temp);
  				if( segT.size() > maxSeg && cf[ bff[ segT[segT.size()-1] ] ]  ){
  					maxSeg = segT.size();
  					target = j;
  				}
  			}		
      }
  		if(target!=-1){
  			memset(vis,0,sizeof vis);
  			vector<int> temp;
  			vector<int> segT = dfs(target,temp);
  			res += segT.size();
  			//cout <<  "End = " << bff[ segT[segT.size()-1] ] << endl;
  			cf[ bff[ segT[segT.size()-1] ] ] = false;
  		}
        }
      cout << max(mxloop,res) << endl;
    }
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    for(int test=0; test< ntest; test++) {
        solve(test);
    }
    return 0;
}

