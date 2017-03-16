#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <climits>
#include <stack>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <math.h>
#include <deque>

using namespace std;


int main() {
  int t, N;
  cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    int number;
    cin >> N;
    vector<int> result;
    map<int, int> mymap;
    for(int j = 0; j < 2*N-1; j++){
      for(int k = 0; k < N; k++){
          cin >> number;
          if(mymap.find(number) == mymap.end())
            mymap[number] = 1;
          else
            mymap[number]++;
      }
    }
    
    for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
      if(it->second%2 == 1)
        result.push_back(it->first);
    }
    sort (result.begin(), result.end());
    
    cout << "Case #" << i << ": ";
    for(int m = 0; m < result.size(); m++){
      cout << result[m] << " ";
    }
    cout << endl;
  }
  
  return 0;
}