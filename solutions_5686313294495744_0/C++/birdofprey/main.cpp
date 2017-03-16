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

Problem::Problem()
{

}

Problem::~Problem() {

}

void Problem::Solve() {
  int N; *input >> N;
  typedef std::pair<std::string,std::string> SSPair;
  std::vector<SSPair> list;
  std::unordered_map<std::string,int> cA, cB;
  for (int n = 0; n < N; ++n) {
    std::string a, b; *input >> a >> b;
    list.push_back({a,b});
    ++cA[a]; ++cB[b];
  }
  int res = 0;
  for (SSPair &p: list) {
    if ((cA[p.first] > 1) && (cB[p.second] > 1)) ++res;
  }
  *output << res << '\n';
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
