#include <iostream>
using namespace std;

int i, j, r, c, t, T, R, C, M, E;

int main(){ 
  cin >> T;
  while (++t<=T) {
    cin >> R >> C >> M;
    cout << "Case #" << t << ":" << endl;
    //cout << R << " " << C << " " << M << endl;
    if (R > 1 && C > 1) {
      E = R*C - M;
      if (E == 2 || E == 3 || E == 5 || E == 7 || 
        (R == 2 || C == 2) && E % 2 == 1 && E > 1)
        cout << "Impossible" << endl;
      else {
        r = c = 1;
        while (r * c < E) {
          if (r <= c && r < R) r++;
          else c++;
        }
        for (i=0; i<R; i++) {
          for (j=0; j<C; j++) {
            char ch = '*';
            if (i == R-1 && j == C-1)
              ch = 'c';
            else if (i >= R-r && j >= C-c && (j >= C-2 || E > (R-i-1)*c + (C-j-1)))
                ch = '.', E--;
            cout << ch;
          }
          cout << endl;
        }
      }
    } else if (R == 1) {
      for (i=0; i<M; i++) cout << "*";
      for (; i<C-1; i++) cout << ".";
      cout << "c" << endl;
    } else if (C == 1) {
      for (i=0; i<M; i++) cout << "*" << endl;
      for (; i<R-1; i++) cout << "." << endl;
      cout << "c" << endl;
    }
  }
}

