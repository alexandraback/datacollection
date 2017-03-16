#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;

int R, C, W;


int main(){
  int ntest = 0;
  cin >> ntest;
  
  for(int test = 1; test <= ntest; ++test){
    cin >> R >> C >> W;

    int rem = C, moves = 0;
    
    if(R == 1){  
      while(rem >= 2 * W){
	rem -= W;
	++moves;
      }
      if(rem - W != 0) ++moves;
      moves += W;
    }
    
    
    cout << "Case #" << test << ": ";

    cout << moves;

    cout << "\n";
  }

  return 0;
}
