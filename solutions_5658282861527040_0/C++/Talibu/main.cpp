#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

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
  u64 A, B, K;
};

struct CResult {
  u64 S;
};

std::string tobin(u64 aN) {
  std::string S;
  for (int i = 0; i < 32; ++i) {
    S += (aN&1) ? "1" : "0";
    aN = aN>>1;
  }
  std::reverse(S.begin(), S.end());
  return S;
}
u64 BF(const CProblem aProblem) {
  u64 rtn = 0;

  struct two {
    u64 a,b,c;
  };
  std::vector<two> SOL;

  for (u64 a=0; a<aProblem.A; a++) {
    for (u64 b=0; b<aProblem.B; b++) {
      if ((a&b)<aProblem.K) {
        rtn++;
        //if (a>=aProblem.K && b>=aProblem.K)
          //SOL.push_back({a,b,a&b});
          //std::cout << tobin(a) << " " << tobin(b) << " " << tobin(a&b) << " " << a << " " << b << " " << (a&b) << "\n";
      }
    }
  }
//  std::sort(SOL.begin(), SOL.end(), [](const two& a, const two& b){return std::tie(a.c,a.a,a.b)<std::tie(b.c,b.a,b.b);});
//  for (const auto& s : SOL)
//    std::cout << tobin(s.a) << " " << tobin(s.b) << " " << tobin(s.c) << " " << s.a << " " << s.b << " " << s.c << "\n";
  return rtn;
}

CResult Solve(CProblem aProblem) {
  CResult rtn;
  //std::cout << "=============\n";
  rtn.S = BF(aProblem);
  return rtn;
}


int main(int argc, char* argv[]) {
  //const std::string KFileName = "test.txt";
  const std::string KFileName = "B-small-attempt0.in";
  //const std::string KFileName = "B-large-practice.in";

  std::ifstream ifs(KFileName);
  assert(ifs);


  u32 T;
  ifs >> T;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<T; i++) {
    CProblem problem;
    ifs >> problem.A >> problem.B >> problem.K;

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout << "Case #" << i+1 << ": ";
    std::cout << result.S << "\n";
  }
}
