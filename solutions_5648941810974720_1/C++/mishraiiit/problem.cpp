#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

int countIn(string s, char c) {
  int ans = 0;
  for(auto x : s) {
    ans += (x == c);
  }
  return ans;
}

int C[26];
int G[26];

bool similar(vector<double> A, vector<double> B) {
  bool same = true;
  for(int i = 0; i < A.size(); i++) {

  }
  return false;
}

int main() {
    int t;
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
      string in;
      cin >> in;
      //char toUse[] = {'Z', 'X', 'V', 'F', 'W', 'H', 'R', 'G', 'O', 'S'};
      char toUse[] = {'X', 'F', 'G', 'H', 'V', 'N', 'O', 'R', 'S', 'T'};
      for(int i = 0; i < 26; i++) C[i] = 0;
      for(auto x : in) C[x - 'A']++;

      string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

      for(int i = 0; i < 10; i++) for(auto c : s[i]) G[c - 'A']++;

      vector<double> line(11,0);
      vector< vector<double> > A(10,line);

      for(int i = 0; i < 10; i++) {
          for(int j = 0; j < 10; j++) {
            A[i][j] = countIn(s[j], toUse[i]);
          }
          A[i][10] = C[toUse[i] - 'A'];
      }
      // Print input

      //cout << endl;
      //print(A);

      // Calculate solution
      vector<double> x(10);
      x = gauss(A);

      cout << "Case #" << ii << ": ";      
      for (int i=0; i<10; i++) {
          int count = (int) x[i];
          for(int j = 0; j < count; j++) {
            cout << i;
          }
      }
      cout << endl;
    }
}