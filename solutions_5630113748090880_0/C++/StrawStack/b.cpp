#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void pv(vector<int> v){
  for(int i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

int main(){

  int T;
  cin >> T;
  for(int t=1; t<=T; t++){

    int N;
    cin >> N;
    vector<int> v(2501, 0);
    for(int i=0; i<2*N-1; i++){
      for(int j=0; j<N; j++){
        int t;
        cin >> t;
        v[t] += 1;
      }
    }

    vector<int> ans;
    for(int i=0; i<v.size(); i++){
      if( v[i] % 2 != 0 ){
        ans.push_back( i );
      }
    }

    sort(ans.begin(), ans.end());

    cout << "Case #" << t << ": ";
    pv(ans);
  }

  return 0;
}
/*
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3

*/
