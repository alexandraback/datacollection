
#include <bitset>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

typedef unsigned long uint;

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
    uint num;
    vector<uint> numbers;

    cin >> num;
    for(uint j = 0; j < num; j++){
      uint val;
      cin >> val;
      numbers.pb(val);
    }
    
    assert(numbers.size() == num);

    cout << "Case #" << (i+1) << ": " << endl;
    
    sort(all(numbers));
    set<pair<uint, vector<uint> > > values;
    values.insert(make_pair(0, vector<uint>()));
    foreach(to_add, numbers){
      foreach(iter, values){
        const vector<uint>& tomerge = iter->second;
        if(tomerge.empty() || tomerge[tomerge.size()-1] != *to_add){
          vector<uint> newval = tomerge;
          newval.pb(*to_add);
          pair<uint, vector<uint> > add;
          add = make_pair(iter->first+*to_add, newval);
          values.insert(add);
        }
      }
    }

    if(values.size() <= 1){
      cout << "Impossible" << endl;
    }else{
      set<pair<uint, vector<uint> > >::iterator iter1, iter2;
      iter1 = values.begin();
      iter2 = values.begin();
      iter2++;
      bool found = false;

      while(iter2 != values.end()){
        if(iter1->first == iter2->first){
          foreach(iter, iter1->second)
            cout << *iter << " ";
          cout << endl;
          foreach(iter, iter2->second)
            cout << *iter << " ";
          cout << endl;
          found = true;
          break;
        }
        iter1++; iter2++;
      }
      if(!found)
        cout << "Impossible" << endl;
    }
  }

  assert(cin.good());
  return EXIT_SUCCESS;
}

