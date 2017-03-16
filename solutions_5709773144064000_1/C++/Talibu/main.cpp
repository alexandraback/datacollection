#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <sstream>

#define FOR4(TYPE, NAME, FROM, TO) for(TYPE NAME = FROM; NAME < TO; NAME++)
#define FOR3(NAME, FROM, TO) for(u64 NAME = FROM; NAME < TO; NAME++)
#define FOR2(NAME, TO) for(u64 NAME = 0; NAME < TO; NAME++)

typedef unsigned int u32;
typedef unsigned long long u64;

typedef std::tuple<u32, u32> TTuple;

template<typename T>
void HashCombine(std::size_t& aSeed, const T& aValue) {
  aSeed ^= std::hash<T>()(aValue) + 0x9e3779b9 + (aSeed << 6) + (aSeed >> 2);
}
namespace std {
  template<>
  struct hash<TTuple> {
    size_t operator()(const TTuple& aTuple) const {
      size_t hash = 0;
      HashCombine(hash, get<0>(aTuple));
      HashCombine(hash, get<1>(aTuple));
      return hash;
    }
  };
}

struct CProblem {
  double C,F,X;
};

struct CResult {
  double T;
};

double upperLimit = 1e100;
double solve(const int aF, const double aTaken, const CProblem& aProblem) {
  const double rate = 2+aProblem.F*aF;
  const double keepTime = aProblem.X/rate;
  const double nextBuyTime = aProblem.C/rate;

  if (aTaken+keepTime<upperLimit) {
    upperLimit = aTaken+keepTime;
  }
  if (aTaken+keepTime>upperLimit && aTaken+nextBuyTime>upperLimit) {
    return 1e100;
  }

  if (nextBuyTime < keepTime) {
    const double buyTime = nextBuyTime + solve(aF+1, aTaken+nextBuyTime, aProblem);
    return std::min(keepTime, buyTime);
  }
  return keepTime;
}

CResult Solve(CProblem aProblem) {
  CResult result;
  upperLimit = 1e100;
  result.T = solve(0, 0, aProblem);

  return result;
}


int main(int argc, char* argv[]) {
  //const std::string KFileName = "test.txt";
  //const std::string KFileName = "B-small-attempt0.in";
  const std::string KFileName = "B-large.in";

  std::ifstream ifs(KFileName);
  assert(ifs);

  u32 N;
  ifs >> N;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<N; i++) {
    CProblem problem;

    ifs >> problem.C >> problem.F >> problem.X;

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout.precision(15);
    std::cout << "Case #" << i+1 << ": ";
    std::cout << result.T << "\n";

    //std::cout << result.A << " " << result.B << "\n";
  }
}
