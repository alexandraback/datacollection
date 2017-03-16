
#include <bitset>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <iostream>
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
    uint n;
    cin >> n;
    
    cout << "Case #" << (i+1) << ": ";

    vector<long double> points;
    for(uint j = 0; j < n; j++){
      uint val;
      cin >> val;
      points.pb(val);
    }
    assert(n == points.size());
    
    long double sumval = 0;
    for(uint j = 0; j < n; j++){
      sumval += points[j];
    }

    vector<long double> ret;
    for(uint j = 0; j < n; j++){
      long double toget;
      bool found = false;
      for(toget = 0.0; toget <= sumval+0.0000001; toget += 0.00001){
        long double currentreal = toget + points[j];
        long double totdis = 0.0;
        for(uint d = 0; d < points.size(); d++)
          if(d != j && points[d] <= currentreal)
            totdis += currentreal - points[d];

        if(fabs(totdis - (sumval - toget)) <= 0.000009 ||
            totdis > sumval - toget - 0.000009){
          found = true;
          break;
        }
      }
      assert(found);
      ret.pb((long double)toget / sumval);
    }

    foreach(iter, ret){
      cout << fixed << setprecision(7) << 100.0**iter << " "; 
    }

    cout << endl;
  }

  assert(cin.good());
  return EXIT_SUCCESS;
}

