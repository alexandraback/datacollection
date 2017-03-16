
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;	
	cin >> T;
 	for(int t = 1; t <= T; t++) {
    int A, N;
    cin >> A >> N;
    vector<int> M(N);
    for(int i = 0; i < N; i++) cin >> M[i];
    sort(M.rbegin(), M.rend());
    int best = M.size();
    int nb_add = 0;
    while(M.size() > 0) {
      while(M.size() > 0 && M.back() < A) {A += M.back(); M.pop_back();}
      if(nb_add + M.size() < best) best = nb_add + M.size();
      if(A == 1) break;
      M.push_back(A-1);
      nb_add++;
    }
		cout << "Case #" << t << ": " << best << endl;
	}


}
