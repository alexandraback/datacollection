#include <iostream>

using namespace std;

bool matrix[50][50];

void clearMatrix(int B) {
  for(int i=0; i<B; i++) {
    for(int j=0; j<B; j++) {
      matrix[i][j] = false;
    }
  }
}

void printMatrix(int B) {
  for(int i=0; i<B; i++) {
    for(int j=0; j<B; j++) {
      if(matrix[i][j]) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
}

void addBridge(int i, int j) {
  matrix[i][j] = true;
}

int maxWays(int B) {
  if(B == 2) return 1;
  return 2<<(B-3);
}

int main() {
  clearMatrix(50);
  int T, B;
  unsigned long long M;
  cin >> T;
  for(int i=0; i<T; i++) {
    cin >> B >> M;

    cout << "Case #" << (i+1) << ": ";

    if(M > maxWays(B)) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    
    cout << "POSSIBLE" << endl;

    // for(int j=B-1; M>0; j--) {
    //   addBridge(0, j);
    //   if(j == B-1) M--;
    //   else {
    //     for(int k=B-1; k>j; k--) {
    //       addBridge(j, k);
    //       M--;

    //       if(M == 0) break;
    //     }
    //   }
    // }

    for(int j=1; j<B-1; j++) {
      for(int k=j+1; k<B; k++) {
        matrix[j][k] = true;
      }
    }

    if(M == maxWays(B)) {
      for(int j = 1; j<B; j++) matrix[0][j] = true;
    } else {
      int pos = B-2;
      while(M>0) {
        if(M%2 == 1) {
          matrix[0][pos] = true;
        }
        pos--;
        M /= 2;
      }
    }

    printMatrix(B);
    clearMatrix(B);
  }
  return 0;
}