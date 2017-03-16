/*
ID: ahri1
PROG: C
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }

int conn[50][50];

vector<string> zip;
vector<vector<int> > G;
int N;
string best="";

string calc(vector<int> &sol) {
  string ret="";
  for(int i=0;i<N;++i){
    ret+=zip[sol[i]];
  }
  return ret;
}

void dfs(int x, vector<int> &way, vector<int> &original_way) {  
  // cout << "SZ: " << sz(way) << endl;
  if (sz(way)==0) {    
    string temp=calc(original_way);
    // cout << temp << endl;
    if (best=="" || temp < best) best=temp;
  } else {        
      while (sz(way) &&  conn[x][way.back()]) {
        // cout << x << " -> " << way.back() << endl;
        int next=way.back();
        way.pop_back();
        dfs(next, way, original_way);    
      }
  }
}

bool cmp(int a, int b) {
  return zip[a]<zip[b];
}


void solve(){
  int M;
  cin >> N >> M;
  int start=0;
  zip.resize(N);
  G.clear();
  G.resize(N);
  for(int i=0;i<N;++i){
    cin >> zip[i];
    if (zip[i]<zip[start]) start=i;
  }
  
  memset(conn, 0, sizeof(conn));
  for(int i=0;i<M;++i){
    int x, y;
    cin >> x >> y;
    G[x-1].push_back(y-1);
    G[y-1].push_back(x-1);
    conn[x-1][y-1]=conn[y-1][x-1]=1;
  }
  vector<int> way;
  for(int i=0;i<N;++i){
    sort(G[i].begin(), G[i].end(), cmp);
    way.push_back(i);
  }
  best="";
  do {
    // cout << "--"  << v_2_s(way) << endl;
    vector<int> temp_way=way;
    reverse(temp_way.begin(), temp_way.end());
    int x = temp_way.back();
    temp_way.pop_back();
    dfs(x, temp_way, way);
  } while (next_permutation(way.begin(), way.end()));  

  cout << best << endl;


}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
