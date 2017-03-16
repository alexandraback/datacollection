#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <string>

namespace codejam {

// Check if a number is fair, in other words, a palindrome.
bool IsFair(const int num) {
  int reverse = 0;
  int original = *const_cast<int*>(&num);
  while (original) {
    reverse = reverse*10 +  original%10;
    original /= 10;
  }
  return reverse == num;
}
  
int CountFairSquare(const int a, const int b) {
  int count = 0;
  const int start = sqrt(a);
  const int end = sqrt(b) + 1;  
  
  for (int num = start; num <= end; num++) {
    if (IsFair(num)) {
      int num_square = num * num;
      if (num_square >= a && num_square <= b) {
        if (IsFair(num_square)) count++;  // if a fair and square
      } // if a valid
    } // if a candidate fair num
  } // for all [sqrt(a), sqrt(b)]
   
  return count;
}

void ReadTestCase(int &a, int &b, std::ifstream &ifs) {
  std::string case_str;
  std::getline(ifs, case_str);           // Read in range A and B
  std::istringstream iss(case_str);
  iss >> a >> b;                    // Parse A and B
  return; 
}

void WriteOutput(const int case_num, const int count, std::ofstream &ofs) {
  ofs << "Case #" << case_num << ": " << count << std::endl;
  return;
}

} // namespace codejame

int main(int argc, char *argv[]) {
  using namespace std;
  using namespace codejam;

  if (argc < 3) { return -1; } 
  // Open file handlers, no error checking.
  ifstream ifs(argv[1], ifstream::in);
  ofstream ofs(argv[2]);
  // Read number of test cases.
  string case_count_str_;
  getline(ifs, case_count_str_); 
  const int case_count = atoi(case_count_str_.c_str());
  
  for (int i = 0; i < case_count; i++) {
    int a = 0;
    int b = 0;
    ReadTestCase(a, b, ifs);
    WriteOutput(i+1, CountFairSquare(a, b), ofs);
  } 
  
  ifs.close();
  ofs.flush();
  ofs.close();
  return 0;
}
