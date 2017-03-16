
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


bool valid(vector<int> &P, vector<string> &C) {
  char prev = ' ';
  char T[256] = {0};

  for(int i = 0; i < P.size(); i++) {
    for(int j = 0; j < C[P[i]].length(); j++)
      if(C[P[i]][j] != prev) {
        if(T[C[P[i]][j]]) return false;
        T[prev] = 1;
        prev = C[P[i]][j];
      }

  }


  return true;

}

int main() {
	int T;	
	cin >> T;

  for(int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];

    vector<int> P(N);
    for(int i = 0; i < N; i++) P[i] = i;

    int nb = 0;
    while(true) {
    if(valid(P, C)) nb++;
    if(!next_permutation(P.begin(), P.end())) break;
    }
    
    cout << "Case #" << t << ": " << nb << endl;



  }


}
