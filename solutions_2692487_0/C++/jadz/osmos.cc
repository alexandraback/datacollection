#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE	100

using namespace std;

int main () {
  int T, armin, N, number_of_operations, current_operations, dist;
  vector<int> motes;
  vector<int> operations;
  
  cin >> T;
  
  for (int t = 0; t < T; ++t) {
    cin >> armin >> N;
    motes.resize(N);
    operations.resize(N);
    
    for (int i = 0; i < N; ++i) {
      cin >> motes[i];
    }
    sort(motes.begin(), motes.end());
    
    for (int i = 0; i < N; ++i) {
      operations[i] = 0;
    }
    
    for (int i = 0; i < N; ++i) {
      
      if (armin > motes[i]) {
	armin += motes[i];
      } else {
	
	current_operations = 0;
	while (armin <= motes[i] && current_operations < (N - i)) {
	  ++current_operations;
	  armin += (armin - 1);
	}
	
	if (current_operations < (N - i)) {
	  operations[i] = current_operations;
	  armin += motes[i];
	} else {
	  operations[i] = (N - i);
	  break;
	}
	
      }
      
      if (armin > MAX_SIZE) {
	break;
      }
    
    }

    number_of_operations = 0;
    current_operations = 0;
    dist = 0;
    for (int i = N - 1; i >= 0; --i) {
      ++dist;
      current_operations += operations[i];
      if (current_operations > dist) {
	number_of_operations += dist;
	current_operations = 0;
	dist = 0;
      }
    }
    number_of_operations += current_operations;
    
    cout << "Case #" << t + 1 << ": " << number_of_operations << endl;
  }
  
}