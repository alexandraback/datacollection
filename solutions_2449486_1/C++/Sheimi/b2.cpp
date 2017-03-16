#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

inline void print_result(int case_no, string& result) {
  cout << "Case #" << case_no << ": " << result << endl;
}

string result_yes = "YES";
string result_no = "NO";

bool test(int* lawn, int n, int m, int i, int j) {
  int index = n * i + j;
  bool result1 = true;
  bool result2 = true;
  for (int k = 0; k < n; k++ ) {
    int index2 = n * i + k;
    if (lawn[index] < lawn[index2]) {
      result1 = false;
      break;
    }
  }
  for (int k = 0; k < m; k++ ) {
    int index2 = n * k + j;
    if (lawn[index] < lawn[index2]) {
      result2 = false;
      break;
    }
  }
  return result1 || result2;
}

void run_case(int case_no, int n, int m) {
  int* lawn = new int[n * m];
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int index = n * i + j;
      cin >> lawn[index];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      bool result = test(lawn, n, m, i, j);
      if (!result) {
        print_result(case_no, result_no);
        delete[] lawn;
        return;
      }
    }
  }

        print_result(case_no, result_yes);
  delete[] lawn;
}

int main(int argc, char** argv) {
  int count;
  cin >> count;
  for (int i = 0; i < count; i++) {
    int n, m;
    cin >> m >> n;
    run_case(i + 1, n, m);
  }
  return 0;
}
