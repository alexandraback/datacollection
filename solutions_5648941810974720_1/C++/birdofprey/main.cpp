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
};

Problem::Problem() {

}

Problem::~Problem() {

}

void Problem::Solve() {
  std::vector<int> count(30);
  std::string str; *input >> str;
  for (char c: str) ++count[c-'A'];

  std::vector<int> digits;

  for (int i = 0; i < count['Z'-'A']; ++i) {
    digits.push_back(0);
    --count['E'-'A'];
    --count['R'-'A'];
    --count['O'-'A'];
  }

  for (int i = 0; i < count['W'-'A']; ++i) {
    digits.push_back(2);
    --count['T'-'A'];
    --count['O'-'A'];
  }

  for (int i = 0; i < count['U'-'A']; ++i) {
    digits.push_back(4);
    --count['F'-'A'];
    --count['R'-'A'];
    --count['O'-'A'];
  }

  for (int i = 0; i < count['X'-'A']; ++i) {
    digits.push_back(6);
    --count['S'-'A'];
    --count['I'-'A'];
  }

  for (int i = 0; i < count['O'-'A']; ++i) {
    digits.push_back(1);
    --count['E'-'A'];
    --count['N'-'A'];
  }

  for (int i = 0; i < count['F'-'A']; ++i) {
    digits.push_back(5);
    --count['E'-'A'];
    --count['V'-'A'];
    --count['I'-'A'];
  }

  for (int i = 0; i < count['V'-'A']; ++i) {
    digits.push_back(7);
    count['E'-'A'] -= 2;
    --count['S'-'A'];
    --count['N'-'A'];
  }

  for (int i = 0; i < count['R'-'A']; ++i) {
    digits.push_back(3);

  }

  for (int i = 0; i < count['N'-'A']; i+=2) {
    digits.push_back(9);
    --count['I'-'A'];
    --count['E'-'A'];
  }

  for (int i = 0; i < count['I'-'A']; ++i) {
    digits.push_back(8);

  }

  std::sort(digits.begin(), digits.end());

  for (int i: digits) {
    *output << char('0' + i);
  }
  *output << '\n';

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
