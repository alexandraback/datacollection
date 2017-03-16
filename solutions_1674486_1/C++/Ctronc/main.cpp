
#include <bitset>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

typedef unsigned int uint;

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
    uint nbsummits;
    cin >> nbsummits;
    map<uint, vector<uint> > relations;

    for(uint j = 1; j <= nbsummits; j++){
      uint nbneigh;
      cin >> nbneigh;
      relations[j];
      for(uint k = 0; k < nbneigh; k++){
        uint val;
        cin >> val;
        relations[j].push_back(val);
      }
    }

    bool found = false;
    for(uint j = 1; j <= nbsummits; j++){
      vector<bool> passthrough(nbsummits+1, false);
      passthrough[j] = true;

      list<uint> rems;
      rems.pb(j);
      while(!rems.empty()){
        uint current = *rems.begin();
        rems.erase(rems.begin());
        assert(passthrough[current]);
        foreach(iter, relations[current]){
          if(passthrough[*iter]){
            found = true;
          }else{
            passthrough[*iter] = true;
            rems.push_back(*iter);
          }
        }
      }
    }

    cout << "Case #" << (i+1) << ": " << (found?"Yes":"No") << endl; 
  }

  assert(cin.good());
  return EXIT_SUCCESS;
}

