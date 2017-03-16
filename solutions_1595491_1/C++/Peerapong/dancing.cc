#include <iostream>

#define MIN(x,y) (x < y) ? x : y;
int nmax[] = {0, 1, 1, 1, 2, 2, 2, 3, 
	     3, 3, 4, 4, 4, 5, 5, 5, 
	     6, 6, 6, 7, 7, 7, 8, 8, 
	     8, 9, 9, 9, 10, 10, 10};

int smax[] = {0, 1, 2, 2, 2, 3, 3, 3, 
	      4, 4, 4, 5, 5, 5, 6, 6, 
	      6, 7, 7, 7, 8, 8, 8, 9, 
	      9, 9, 10, 10, 10, 11, 11};


using namespace std;

int main(int argc, char **argv) {
  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    int N, S, p;
    int r1 = 0, r2 = 0;
    
    cin >> N >> S >> p;

    for (int j = 0; j < N; j++) {
      int t;

      cin >> t;
   
      if (nmax[t] >= p) {
	r1++;
      }
      else if (smax[t] >= p) {
	r2++;
      }
    }

    r2 = MIN(r2, S);
    int r = r1 + r2;

    cout << "Case #" << i << ": " << r << endl;
  }
}
