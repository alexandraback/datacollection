//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int K, N;
map<int, int> m;
vector<pair<int, vector<int> > > rooms;

int table[1<<20];
int get(int mask){
  
  if(mask == (1<<N)-1)
    return 0;
  if(table[mask] != -1)
    return table[mask];
  
  map<int, int> keys = m;
  for(int i = 0 ; i < N ; i++)
    if((mask>>i)&1){
      keys[rooms[i].first]--;
      for(int j = 0 ; j < rooms[i].second.size() ; j++){
        keys[rooms[i].second[j]]++;
      }
    }
  
  for(int i = 0 ; i < N ; i++){
    if(!((mask>>i)&1)){
      if(keys.find(rooms[i].first) != keys.end() && keys[rooms[i].first]){
        if(get(mask|(1<<i)) != N)
          return table[mask] = i;
      }
    }
  }
  
  return table[mask] = N;
}

int main() {
  
//    freopen("/Users/hamza/1.in", "rt", stdin);
  freopen("/Users/hamza/Downloads/D-small-attempt0.in", "rt", stdin);
  freopen("/Users/hamza/D-small-attempt0.out", "wt", stdout);
    int tt; cin >> tt;
  for(int t = 1 ; t <= tt; t++){
    cin >> K >> N;
    m.clear();
    rooms.clear();
    for(int i = 0 ; i < K ; i++){
      int x; cin >> x;
      m[x]++;
    }
    for(int i = 0 ; i < N ; i++){
      int x, n; cin >> x >> n;
      pair<int, vector<int> > v = make_pair(x, vector<int>());
      for(int j = 0 ; j < n ; j++){
        int y; cin >> y;
        v.second.push_back(y);
      }
      rooms.push_back(v);
    }
    
    int i;
    memset(table, -1, sizeof table);
    
    for(i = 0 ; i < N ; i++){
      if(m.count(rooms[i].first) && get(1<<i) != N)
        break;
    }
    
    cout << "Case #" << t << ":";
    if(i == N){
      cout << " IMPOSSIBLE" << endl;
      continue;
    }
    
    int mask = 1<<i;
    while(true){
      cout << " " << i+1;
      if(mask == (1<<N)-1)
        break;
      i = get(mask);
      mask |= (1<<i);
    }
    cout << endl;
  }
  
  return 0;
}
