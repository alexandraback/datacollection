//*****************************************************************************
// CodePro 1.0.1 - Programming contests library.
// (C) 2015-2016, Bird of Prey Studio
//     Dr. Sergey Pogodin < dr.pogodin@gmail.com >

enum IOBinding { File, StdStream };

static const IOBinding InputBinding = File;
//static const IOBinding InputBinding = StdStream;

static const IOBinding OutputBinding = File;
//static const IOBinding OutputBinding = StdStream;

enum IOHandlingFlag {
  MultipleTestCases = 0x1,
  PrintCaseNumberInCodeJamStyle = 0x2
};

static const int IOHandlingFlags =
    MultipleTestCases | PrintCaseNumberInCodeJamStyle;

#include <cmath>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cstring>
#include <string>
#include <iomanip>

#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef std::vector <int> IVec;
typedef std::unordered_set <int> ISet;

std::istream *input = &std::cin;
std::ostream *output = &std::cout;

//*****************************************************************************

class Problem {
public:
  Problem();
  ~Problem();
  void Solve();

private:

  void SolveA(int i, int a);
  void SolveB(int i, int a, int b);

  int a_, b_, diff_ { INT_MAX };
  std::string A_, B_;
};

Problem::Problem()
{

}

Problem::~Problem() {

}

void Problem::Solve() {
  *input >> A_ >> B_;
  SolveA(0, 0);
  *output << std::setfill('0') << std::setw(A_.size()) << a_ << ' '
          << std::setfill('0') << std::setw(A_.size()) << b_ << '\n';
}

void Problem::SolveA(int i, int a) {
  if (i == A_.size()) SolveB(0, a, 0);
  else if (A_[i] != '?') {
    a = 10 * a + A_[i] - '0';
    SolveA(i+1, a);
  } else {
    for (int j = 0; j < 10; ++j) {
      int x = 10 * a + j;
      SolveA(i+1, x);
    }
  }
}

void Problem::SolveB(int i, int a, int b) {
  if (i == B_.size()) {
    int diff = abs(a-b);
    if (diff_ > diff) {
      a_ = a; b_ = b; diff_ = diff;
    } else if (diff_ == diff) {
      if (a_ > a) {
        a_ = a; b_ = b; diff_ = diff;
      } else if ((a_ == a) && (b_ > b)) {
        a_ = a; b_ = b; diff_ = diff;
      }
    }
  } else if (B_[i] != '?') {
    b = 10 * b + B_[i] - '0';
    SolveB(i+1, a, b);
  } else {
    for (int j = 0; j < 10; ++j) {
      int x = 10 * b + j;
      SolveB(i+1, a, x);
    }
  }
}

//*****************************************************************************

void InitIOStreams() {
  std::ios_base::sync_with_stdio(false);
  if (InputBinding == File) input = new std::ifstream("input.txt");
  if (OutputBinding == File) output = new std::ofstream("output.txt");
}

void DeinitIOStreams() {
  if (InputBinding == File) delete input;
  if (OutputBinding == File) delete output;
}

int main(int argc, char *argv[]) {
  (void) argc;
  (void) argv;
  InitIOStreams();
  int num_test_cases = 1;
  if (IOHandlingFlags & MultipleTestCases) *input >> num_test_cases;
  for(int t = 1; t <= num_test_cases; ++t) {
    if (IOHandlingFlags & PrintCaseNumberInCodeJamStyle)
      *output << "Case #" << t << ": ";
    Problem *p = new Problem;
    p->Solve(); delete p;
  }
  DeinitIOStreams();
  return 0;
}
