
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


double C[10000];


int main() {
  int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
    int N, X, Y;
    cin >> N >> X >> Y;
    if(X < 0) X = -X;
    for(int k = 0; k < X+Y; k+=2) N -= 2*k+1;
    double p;

    if(N < 0) p = 0.;
    else if(N > X+2*Y) p = 1.;
    else if(X == 0) p = 0.;
    else {      
      memset(C, 0, sizeof(C));
      C[0] = 1.;
      for(int n = 1; n <= N; n++) {
        for(int a = N; a >= 1; a--) 
          C[a] = 0.5*(C[a]+C[a-1]);
        C[0] = 0.5*C[0];        
      }
      p = 0.;
      for(int i = 0; i <= N; i++) if(i > Y || (N-i>X+Y && N-X-Y > Y)) p += C[i];

//      for(int i = 0; i <= N; i++) cerr << C[N][i] << " ";
//      cerr << endl;
    }
		cout << "Case #" << t << ": " << p << endl;
  }
}


