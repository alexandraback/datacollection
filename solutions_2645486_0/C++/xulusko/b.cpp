#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, E, R, N, V;
vector<int> VV;

int get_max(int index, int energy){
  if (index >= N)
    return 0;
  int res = 0;
  for(int i = 0; i <= energy; i++){
    res = max(res, i*VV[index]+get_max(index+1, min(E, energy-i+R)));
  }
  return res;
}

int main(){ 
  cin >> T;
  for (int i = 1; i <= T; i++){
    cin >> E >> R >> N;
    VV.resize(0);
    VV.resize(N);
    for (int j = 0; j < N; j++)
      cin >> VV[j];
    cout << "Case #" << i << ": " << get_max(0, E) << endl;
  }
}
