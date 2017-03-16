#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

int N, M;
vector< pair<int,ll> > box, toy;
bool flg[200];
ll maxv;

void dfs(int box_i, ll box_r, int toy_i, ll toy_r, ll num){
  //cerr << box_i << " " << box_r << " " << toy_i << "  " << toy_r << " " << num << endl;
  maxv = max(maxv, num);
  
  if(box_r == box[box_i].second){ box_i++; box_r=0; }
  if(box_i>=box.size()) return;

  if(toy_r == toy[toy_i].second){ toy_i++; toy_r=0; }
  if(toy_i>=toy.size()) return;
  
  if(box_i+1<box.size()) dfs(box_i+1, 0, toy_i, toy_r, num);
  
  {
    REP(i,toy_i, toy.size()){
      if(toy[i].first == box[box_i].first){
        ll new_toybox = min(box[box_i].second - box_r, toy[i].second - (i==toy_i?toy_r:0));        
        dfs(box_i, box_r + new_toybox, i, new_toybox + (i==toy_i?toy_r:0), num + new_toybox);
        break;
      }
    }
  }
}

void solve(){
  maxv = 0;

  dfs(0, 0, 0, 0, 0);
}


int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    box.clear();
    toy.clear();
    rep(i,200) flg[i] = false;
    
    cin >> N >> M;

    rep(i,N){
      ll num;
      int type;
      cin >> num >> type;
      flg[type] = true;
      if(box.size()>0 && box[box.size()-1].first == type){
        box[box.size()-1].second += num;
      }else{
        box.push_back(make_pair(type,num));
      }
    }
    rep(i,M){
      ll num;
      int type;
      cin >> num >> type;
      if(flg[type]==false) continue;
      if(toy.size()>0 && toy[toy.size()-1].first == type){
        toy[toy.size()-1].second += num;
      }else{
        toy.push_back(make_pair(type,num));
      }
    }
    solve();
    cout << "Case #" << t+1 << ": " << maxv << endl;
  }
  
  return 0;
}
