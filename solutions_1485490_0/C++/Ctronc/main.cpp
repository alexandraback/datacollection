
#include <bitset>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

typedef unsigned long long uint;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define foreach(i,c) for(decltype((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(x,c) ((c).find(x) != (c).end()) 
#define cpresent(x,c) (std::find(all(c),x) != (c).end()) 
#define mapget(x,c,d) (present(x,c)?(c).find(x)->second:d)
#define cmapget(x,c,d) (cpresent(x,c)?(c).find(x)->second:d)
#define iter(x) decltype((x).begin())

int main()
{
  uint T;
  cin >> T;

  for(uint i = 0; i < T; i++){
    
    uint N, M;
    cin >> N >> M;
    
    vector<pair<uint,uint> > toys, boxes;
    uint num, type;
    for(uint i = 1; i <= N; i++){
      cin >> num >> type;
      toys.pb(make_pair(num, type));
    }
    for(uint i = 1; i <= M; i++){
      cin >> num >> type;
      boxes.pb(make_pair(num, type));
    }
    
    vector<uint> tottoys(N+1, 0);
    foreach(iter, boxes){
      uint numboxes, typeboxes;
      numboxes = iter->first;
      typeboxes = iter->second;

      for(uint i = 0; i < tottoys.size()-1; i++){
        uint found = 0;
        for(uint j = i; j < tottoys.size()-1; j++){
          if(typeboxes == toys[j].second){
            found = min(numboxes, found+toys[j].first);
          }
          tottoys[j+1] = max(tottoys[j+1], tottoys[i] + found);
        }
      }
    }
    
    cout << "Case #" << (i+1) << ": " << tottoys[N] << endl; 
  }

  assert(cin.good());
  return EXIT_SUCCESS;
}

