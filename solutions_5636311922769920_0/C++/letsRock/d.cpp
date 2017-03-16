#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


int main(){

  int T;
  cin >> T;
  for(int i=0; i< T; i++){
    int K, C, S;
    cin >> K >> C >> S;

    if(K == 1){
      cout << "Case #" << (i + 1) << ": 1" << endl;
      continue;
    }

    if(C == 1){
      if(S == K){
	cout << "Case #" << (i+1) << ":";
	for(int j=0; j< K; j++){
	  cout << " " << (j+1);
	}
	cout << endl;
      }
      else{
	cout << "Case #" << (i+1) << ": IMPOSSIBLE" << endl;
      }
      continue;
    }

    int top = ceil((double)K/2.0);
    if(S < top){
      cout << "Case #" << (i+1) << ": IMPOSSIBLE" << endl;
    }
    else{
      cout << "Case #" << (i+1) << ":";
      for(int j=0; j<top; j++){
	if(K*2*j + 2*(j + 1) > K*K){
	  cout << " " << K*K;
	}
	else{
	  cout << " " << (K*2*j + 2*(j + 1));
	}
      }
      cout << endl;
    }
    
  }

}
