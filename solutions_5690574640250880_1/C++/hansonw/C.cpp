#include <iostream>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int R, C, M; cin >> R >> C >> M;
    printf("Case #%d:\n", t);

    bool ok = false;
    int R1 = R;
    for (int fill = 0; fill <= max(0, R1-2) && M >= 0 && !ok; fill++, M -= C, R--) { 
      if (M == 0) {
        for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
        for (int i = 0; i < R; i++, cout << endl)
          for (int j = 0; j < C; j++)
            if (i+j == 0) cout << 'c';
            else cout << '.';
        ok = true;
      } else if (R*C == M+1) {
        for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
        for (int i = 0; i < R; i++, cout << endl)
          for (int j = 0; j < C; j++)
            if (i+j == 0) cout << 'c';
            else cout << '*';
        ok = true;
      } else if (R == 1) {
        for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
        for (int i = 0; i < C; i++) {
          if (i < M) cout << '*';
          else if (i == C-1) cout << 'c';
          else cout << '.';
        }
        cout << endl;
        ok = true;
      } else if (C == 1) {
        for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
        for (int i = 0; i < R; i++) {
          if (i < M) cout << '*';
          else if (i == R-1) cout << 'c';
          else cout << '.';
          cout << endl;
        }
        ok = true;
      } else if (R > 2 && (M < C-1 || M == C)) {
        for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
        cout << string(M, '*') << string(C-M, '.') << endl;
        for (int i = 0; i < R-1; i++) {
          string s = string(C, '.');
          if (i == R-2) s[0] = 'c';
          cout << s << endl;
        }
        ok = true;
      } else {
        // last 2 rows must be equal.
        for (int rows = R-2; rows >= 0; rows--) {
          for (int lr = 0; lr <= C-2; lr++) {
            int minx = lr * rows, maxx = C * rows;
            int rem = M-2*lr;
            if (minx <= rem && rem <= maxx) {
              int trows = rows + (lr ? 2 : 0);
              if (trows+1 == R) continue;
              if (rows > 0) {
                int sz = rem / rows;
                if (sz == C-1 || sz+1 == C-1) continue;
                for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
                for (int i = 0; i < rows; i++, cout << endl) {
                  int j = 0;
                  for (j = 0; j < (i < rem%rows ? sz+1 : sz); j++) {
                    cout << '*';
                  }
                  for (; j < C; j++) {
                    cout << '.';
                  }
                }
              } else {
                for (int i = 0; i < fill; i++) cout << string(C, '*') << endl;
              }
              for (int i = 0; i < 2; i++, cout << endl)
                for (int j = 0; j < C; j++)
                  cout << (i+rows == R-1 && j == C-1 ? 'c' : (j < lr ? '*' : '.'));
              for (int i = 0; i < R-rows-2; i++) {
                string s(C, '.');
                if (i == R-rows-3) {
                  s[0] = 'c';
                }
                cout << s << endl;
              }
              ok = true;
              goto done;
            }
          }
        }
      }
    }
  done:;
    if (!ok) cout << "Impossible" << endl;
  }
}
