
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

// struct person {
//   int total;
//   int baseScore;
// };

int main(){
  int T;
  cin >> T;
  int N,S,P;
  vector< int > V;
  for(int i = 1; i <= T; i++){
    cout << "Case #" << i << ": ";
    V.clear();
    cin >> N >> S >> P;
    int total,base;
    for(int j = 0; j < N; j++){
      cin >> total;
      V.push_back( total );
    }
    sort( ALL(V) , greater<int>() );
    
    int ans = 0;
    int s = 0;
    for(int j = 0; j < N; j++){
      total = V[j];
      base = total/3;
      if( total % 3 == 0){
	if( base >= P)
	  ans++;
	else if ( s < S && base - 1 >= 0 && base + 1 >= P){
	  ans++;
	  s++;
	}  

      } else if ( total % 3 == 1 ){
	if( base + 1 >= P)
	  ans++;
      } else {
	if( base+1 >= P)
	  ans++;
	else if ( s < S && base >= 0 && base + 2 >= P){
	  ans++;
	  s++;
	}  

      }

    }
    
    cout << ans << endl;
    
  }

  return 0;
}
