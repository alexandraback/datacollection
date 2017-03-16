#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <string.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int lawn[101][101];
int n, m, a;

bool check(int grass, int xp, int yp){
  bool up, down, left, right;
  up = down = left = right = false;
  for(int i = 0; i < 4; ++i){
    int x = xp;
    int y = yp;
    while(x > 0 && x < n + 1 && y > 0 && y < m + 1){
      x += dx[i];
      y += dy[i];
      //cout<<x<<" "<<y<<endl;
      if(lawn[x][y] > grass)break;
    }
    if(x == 0)up = true;
    if(x == n + 1)down = true;
    if(y == 0)left = true;
    if(y == m + 1)right = true;
    //if(xp == 2 && yp == 3)cout<<grass<<" "<<up<<" "<<down<<" "<<left<<" "<<right<<endl;
  }
  if(up == true && down == true)return true;
  if(left == true && right == true)return true;
  return false;
}

int main(){
  int T;
  cin>>T;
  for(int times = 0; times < T; ++times){
    cin>>n>>m;
    memset(lawn, 0, sizeof(lawn));
    map<int,int> mp;
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
	cin>>a;
	lawn[i][j] = a;
	if(mp.find(a) == mp.end())mp[a]++;
      }
    }
    vector<int> v;
    map<int,int>::iterator it;
    for(it = mp.begin(); it!=mp.end(); ++it){
      v.push_back((*it).first);
    }
    sort(v.begin(), v.end());
    bool ok = true;
    for(int len = 0; len < v.size(); ++len){
      int grass = v[len];
      for(int i = 1; i <= n; ++i){
	for(int j = 1; j <= m; ++j){
	  if(lawn[i][j] == grass){
	    if(!check(grass,i,j))ok=false;
	  }
	}
      }
      if(!ok)break;
    }
    if(ok)cout<<"Case #"<<times + 1<<": "<<"YES"<<endl;
    else cout<<"Case #"<<times + 1<<": "<<"NO"<<endl;
  }
  return 0;
}
