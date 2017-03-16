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
  std::vector<double> N,K;
};

struct CResult {
  int Y,Z;
};

int Ken(const std::vector<double>& aW, const double aTold) {
  std::vector<std::tuple<double, int>> weights;
  for (int i=0; i<(int)aW.size(); i++) {
    weights.push_back(std::make_tuple(aW[i], i));
  }
  std::sort(weights.begin(), weights.end());
  for (int i=0; i<(int)weights.size(); i++) {
    if (std::get<0>(weights[i])>aTold)
      return std::get<1>(weights[i]);
  }
  return std::get<1>(weights[0]);
}

int BF(const std::vector<double>& aN, const std::vector<double>& aK) {
  if (aN.size()==0) {
    return 0;
  }
  int maxPoints = 0;
  /*for (int i=0; i<(int)aN.size(); i++)*/ {
    int i = 0;
    const double nWeight = aN[i];
    const int j = Ken(aK, nWeight);
    const double kWeight = aK[j];
    const int point = (nWeight>kWeight);
    std::vector<double> aNN = aN;
    std::vector<double> aKN = aK;
    aNN.erase(aNN.begin()+i);
    aKN.erase(aKN.begin()+j);
    const int nPoint = BF(aNN, aKN);
    maxPoints = std::max(maxPoints, point+nPoint);
  }
  return maxPoints;
}

void verify(const double aNW1, const double aNW2, const double aKW1, const double aKW2) {
  assert((aNW1>aKW1) == (aNW2>aKW2));
}

int BFB(const std::vector<double>& aN, const std::vector<double>& aK) {
  int maxPoints = 0;
  if (aN.size()==0) {
    return 0;
  }
  {
    int i = 0;
    const double nWeight = aN[i];
    for (int j=0; j<(int)aK.size(); j+=std::max(1, (int)aK.size()-1)) {
      if (j==0 || aK[j]>nWeight) {
        const double kWeight = aK[j];
        const int point = (nWeight>kWeight);
        std::vector<double> aNN = aN;
        std::vector<double> aKN = aK;
        aNN.erase(aNN.begin()+i);
        aKN.erase(aKN.begin()+j);
        const int nPoint = BFB(aNN, aKN);
        maxPoints = std::max(maxPoints, point+nPoint);
      }
    }
  }
  return maxPoints;
}

CResult Solve(CProblem aProblem) {
  std::vector<double> KP = aProblem.K;
  std::sort(KP.begin(), KP.end());
  std::vector<double> KN = aProblem.N;
  std::sort(KN.begin(), KN.end());
  int Y = BFB(KN, KP);
  int Z = BF(KN, KP);
  return {Y, Z};
}


int main(int argc, char* argv[]) {
  const std::string KFileName = "D-small-attempt0.in";
  //const std::string KFileName = "B-small-practice.in";
  //const std::string KFileName = "B-large-practice.in";

  std::ifstream ifs(KFileName);
  assert(ifs);

  u32 N;
  ifs >> N;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<N; i++) {
    CProblem problem;

    int T;
    double W;
    ifs >> T;
    for (int i=0; i<T; i++) {
      ifs >> W;
      problem.N.push_back(W);
    }
    for (int i=0; i<T; i++) {
      ifs >> W;
      problem.K.push_back(W);
    }

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout << "Case #" << i+1 << ": ";
    std::cout << result.Y << " " << result.Z << "\n";

    //std::cout << result.A << " " << result.B << "\n";
  }
}
