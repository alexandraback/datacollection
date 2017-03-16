#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

namespace codejam {

bool IsValidPattern(int **pattern, const int n, const int m) {
  std::vector<int> row_max(n);
  std::vector<int> col_max(m); 
  // Fill in the max information.
  for (int i = 0; i < n; i++) {
    row_max[i] = *std::max_element(pattern[i], pattern[i]+m);
  }

  for (int j = 0; j < m; j++) {
    int max_e = pattern[0][j];
    for (int i = 0; i < n; i++) {
      if (pattern[i][j] > max_e) max_e = pattern[i][j];
    }
    col_max[j] = max_e;
  }

  // Check the invariant
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (pattern[i][j] != row_max[i] && pattern[i][j] != col_max[j])
        return false;
    } // for j
  } // for i
  
  return true;
}

int **AllocateSpace(const int n, const int m) {
  int **space = new int *[n];
  for (int i = 0; i < n; i++) space[i] = new int[m];
  return space;
}

void ReleaseSpace(int **space, const int n) {
  for (int i = 0; i < n; i++) delete [] space[i];
  delete [] space;
  return;
}

void FillPattern(int **pattern, const int n, const int m, std::ifstream &ifs) {
  for (int i = 0; i < n; i++) {
    std::string tmp;
    std::getline(ifs, tmp);
    std::istringstream iss(tmp);
    for (int j = 0; j < m; j++) iss >> pattern[i][j];
  }   
  return;
}

void WriteOutput(int case_num, bool valid, std::ofstream &ofs) {
  std::string result = (valid ? "YES" : "NO");
  ofs << "Case #" << case_num << ": " << result << std::endl; 
  return;
}

} // codejam

int main(int argc, char *argv[]) {
  using namespace std;
  using namespace codejam;
  
  // Open file handlers, no error checking.
  ifstream ifs(argv[1], ifstream::in);
  ofstream ofs(argv[2]);
  // Read number of test cases.
  string case_count_str_;
  getline(ifs, case_count_str_); 
  const int case_count = atoi(case_count_str_.c_str());
  for (int i = 0; i < case_count; i++) {
    string dim_str;
    getline(ifs, dim_str);           // Read in dimension
    istringstream iss(dim_str);
    int n = 0;
    int m = 0;
    iss >> n >> m;                   // Parse dimension 
    int **pattern = AllocateSpace(n, m);  // Allocate space
    FillPattern(pattern, n, m, ifs);            // Read in pattern
    bool valid = IsValidPattern(pattern, n, m); // Determine if current pattern is possible
    ReleaseSpace(pattern, n);        // Release allocated space
    WriteOutput(i+1, valid, ofs);
  }
  
  ifs.close();
  ofs.flush();
  ofs.close(); 

  return 0;
}
