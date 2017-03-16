//*****************************************************************************
//  CodePro 1.0 - Programming contests library.
//
//  (c) Dr. Sergey Pogodin, 2015
//      Contact: dr.pogodin@gmail.com


//*****************************************************************************
//  Tuning of the template's behaviour.
//
//  Switching of the i/o binding between files (input.txt and output.txt in the
//  program starting folder) and standart streams. Just comment/uncomment
//  necessary assigments of the <input_binding> and <output_binding> params.

enum IOBinding { File, StdStream };

static const IOBinding InputBinding = File;
//static const IOBinding InputBinding = StdStream;

static const IOBinding OutputBinding = File;
//static const IOBinding OutputBinding = StdStream;

//  Basic handling of the input and output by main function.

enum IOHandlingFlag {
  MultipleTestCases = 0x1,
  PrintCaseNumberInCodeJamStyle = 0x2
};

static const int IOHandlingFlags =
    MultipleTestCases|PrintCaseNumberInCodeJamStyle;


//*****************************************************************************
//  Set of the most common includes, declarations and definitions necessary all
//  around. Keep this section in sync with "global.h".

#include <cmath>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cstring>

#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef std::vector <int> IVec;
typedef std::unordered_set <int> ISet;


//*****************************************************************************
//  Implementation of the problem solution.

std::istream *input = &std::cin;
std::ostream *output = &std::cout;

class Problem {
public:
  Problem();
  ~Problem();
  void solve();

private:

  static int pack2(int a, int b)        { return 10 * a + b; }
  static int pack3(int a, int b, int c) { return 100 * a + 10 * b + c; }

  int J_, P_, S_, K_;
  std::unordered_map <int, int> jp_, ps_, js_;
  IVec list_;
};

Problem::Problem()
{
  *input >> J_ >> P_ >> S_ >> K_;
}

Problem::~Problem() {

}

void Problem::solve() {
  for (int j = 0; j < J_; ++j) {
    for (int p = 0; p < P_; ++p) {
      for (int s = 0; s < S_; ++s) {
        if ((js_[pack2(j,s)] < K_) &&
            (ps_[pack2(p,s)] < K_) &&
            (jp_[pack2(j,p)] < K_)) {
          ++js_[pack2(j,s)];
          ++ps_[pack2(p,s)];
          ++jp_[pack2(j,p)];
          list_.push_back(pack3(j,p,s));
        }
      }
    }
  }
  *output << list_.size() << '\n';
  for (int x: list_) {
    *output << 1 + x/100 << ' ' << 1 + (x/10)%10 << ' ' << 1 + x%10 << '\n';
  }
}


//*****************************************************************************
//  Setup of <input> and <output> binding to input.txt and output.txt files if
//  necessary.

void InitIOStreams() {
  std::ios_base::sync_with_stdio(false);
  if (InputBinding == File) input = new std::ifstream("input.txt");
  if (OutputBinding == File) output = new std::ofstream("output.txt");
}

void DeinitIOStreams() {
  if (InputBinding == File) delete input;
  if (OutputBinding == File) delete output;
}


//*****************************************************************************
//  Start-up of the solution.

int main(int argc, char *argv[]) {
  (void) argc;
  (void) argv;
  InitIOStreams();
  int num_test_cases = 1;
  if (IOHandlingFlags & MultipleTestCases) *input >> num_test_cases;
  for(int t = 1; t <= num_test_cases; ++t) {
    if (IOHandlingFlags & PrintCaseNumberInCodeJamStyle)
      *output << "Case #" << t << ": ";
    Problem p; p.solve();
  }
  DeinitIOStreams();
  return 0;
}
