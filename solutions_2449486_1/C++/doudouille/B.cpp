
#include <iostream>
#include <vector>
using namespace std;


bool possible(const vector< vector<int> > &L) {
  int N = L.size();
  int M = L[0].size();
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {

      for(int k = 0; k < N; k++) 
        if(L[k][j] < L[i][j])
          for(int l = 0; l < M; l++) 
            if(L[k][l] > L[k][j]) return false;

      for(int k = 0; k < M; k++) 
        if(L[i][k] < L[i][j])
          for(int l = 0; l < N; l++) 
            if(L[l][k] > L[i][k]) return false;
    }
  return true;
}


int main() {
	long long T;

	cin >> T;
	for(int t = 1; t <= T; t++) {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > L(N, vector<int>(M));
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
        cin >> L[i][j];
		cout << "Case #" << t << ": " << (possible(L)?"YES":"NO") << endl;

	}


}
