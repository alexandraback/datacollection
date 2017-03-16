#include <iostream>

using namespace std;



int main() {
  int T;
  cin >> T;

  for(int i = 0 ; i < T; i++) {
    int N;
    cin >> N;
    int all[2600];
    for(int j=0; j <2600; j++) {
      all[j]=0;
    }
    for(int j=0; j<2*N-1; j++) {
      for(int k=0; k<N;k++) {
	int x;
	cin >>x;
	all[x]++;
      }
    }
    cout << "Case #" << (i+1) << ":";
    for(int j=0; j<2600; j++) {
      if (all[j]%2 == 1)
	cout << " " << j;
    }
    cout << endl;
  }
  return 0;
}
	
