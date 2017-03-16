#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Usage: a.out N J" << endl;
    return -1;
  }

  int N = atoi(argv[1]);
  int J = atoi(argv[2]);

  int count = 0;
  long value = 0;
  int dividers[11];
  bool fail;
  int residue;

  cout << "Case #1: " << endl;


  int UpperBound = 16;
  for (int i = 0; i < (1 << UpperBound); i++) {
    for (int b = 2; b <= 10; b++) {
      value = 0;
      value += 1;
      //value += (long)pow(b, N-1);

      for (int j = 0; j < UpperBound; j++) {
        value += (long)pow(b, j+1) * ((i & 1 << j) >> j);
      }

      fail = true;

      for (int d = 2; d < sqrt(value); d++) {
        residue = 1;
        for (int r = 1; r < N; r++) {
          residue = (residue * b) % d;
        }
        if ((value + residue) % d == 0) {
          dividers[b] = d;
          fail = false;
          break;
        }
      }
      if (fail) break;
    }

    if (fail) continue;

    count +=1;
    cout << "1";
    for (int j = 0; j < N - 2 - UpperBound; j++) {
      cout << "0";
    }
    for (int j = UpperBound-1; j >= 0; j--) {
      cout << ((i & (1 << j)) >> j);
    }
    cout <<"1";
    for (int b = 2; b <= 10; b++) {
      cout << " " << dividers[b];
    }
    cout << endl;
    if (count == J) break;
  }

  /*
  for (int i = 0; i < (1 << N - 2); i++) {
    for (int b = 2; b <= 10; b++) {
      value = 0;
      value += 1;
      value += (long)pow(b, N-1);

      for (int j = 0; j < N - 2; j++) {
        value += (long)pow(b, j+1) * ((i & 1 << j) >> j);
      }

      fail = true;

      for (int d = 2; d < sqrt(value); d++) {
        if (value % d == 0) {
          dividers[b] = d;
          fail = false;
          break;
        }
      }
      if (fail) break;
    }

    if (fail) continue;

    count +=1;
    cout << "1";
    for (int j = N-3; j >= 0; j--) {
      cout << ((i & (1 << j)) >> j);
    }
    cout <<"1";
    for (int b = 2; b <= 10; b++) {
      cout << " " << dividers[b];
    }
    cout << endl;
    if (count == J) break;
  }
  */
  return 0;
}
