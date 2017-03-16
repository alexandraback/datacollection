#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <string>

namespace codejam {

// Check if a number is fair, in other words, a palindrome.
bool IsFair(const long long num) {
  long long reverse = 0;
  long long original = *const_cast<long long*>(&num);
  while (original) {
    reverse = reverse*10 +  original%10;
    original /= 10;
  }
  return reverse == num;
}

int ComputeNumLen(long long num) {
  int len = 0;
  while (num) {
    len++;
    num /= 10;
  }
  return len;
}

long long ConstructOddFairNum(long long first) {
  long long fair_num = first;
  first /= 10;  // len - 1
  while (first) {
    fair_num = fair_num * 10 + (first % 10); 
    first /= 10;
  }
  return fair_num;
}

long long ConstructEvenFairNum(long long first) {
  long long fair_num = first;
  while (first) {
    fair_num = fair_num * 10 + (first % 10); 
    first /= 10;
  }
  return fair_num;
}

long long GetBaseNum(int len) {
  long long base = 1;
  while (--len) base *= 10; 
  return base;
}

long long CountFairSquare(const long long a, const long long b) {
  long long count = 0;
  const long long start = sqrt(a);
  const long long end = sqrt(b) + 1; 
  
  const int start_len = ComputeNumLen(start);
  const int end_len = ComputeNumLen(end);
  for (int len = start_len; len <= end_len; len++) {
   if (len % 2) {
      // odd
      int first_len  = ((len / 2) + 1);
      long long base_num = GetBaseNum(first_len);
      const long long upper_limit = base_num * 10;
      for (long long first = base_num; first < upper_limit; first++) {
        long long num = ConstructOddFairNum(first);
        long long num_square = num * num;
        if (num_square >= a && num_square <= b) {
          if (IsFair(num_square)) count++;  // if a fair and square
        } // if a valid
      } // for all first half numbers for current length
    } else {
      // even
      int first_len  = (len / 2);
      long long base_num = GetBaseNum(first_len);
      const long long upper_limit = base_num * 10;
      for (long long first = base_num; first < upper_limit; first++) {
        long long num = ConstructEvenFairNum(first);
        long long num_square = num * num;
        if (num_square >= a && num_square <= b) {
          if (IsFair(num_square)) count++;  // if a fair and square
        } // if a valid
      } // for all first half numbers for current length
    }
  } // for all [len(sqrt(a)), len(sqrt(b))]
   
  return count;
}

void ReadTestCase(long long &a, long long &b, std::ifstream &ifs) {
  std::string case_str;
  std::getline(ifs, case_str);           // Read in range A and B
  std::istringstream iss(case_str);
  iss >> a >> b;                    // Parse A and B
  return; 
}

void WriteOutput(const int case_num, const long long count, std::ofstream &ofs) {
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
  
  // #pragma omp parallel for 
  for (int i = 0; i < case_count; i++) {
    long long a = 0;
    long long b = 0;
    ReadTestCase(a, b, ifs);
    WriteOutput(i+1, CountFairSquare(a, b), ofs);
  } 
  
  ifs.close();
  ofs.flush();
  ofs.close();
  
  return 0;
}
