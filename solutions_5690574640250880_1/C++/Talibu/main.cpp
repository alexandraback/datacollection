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
  int R, C, M;
};

struct CMS {
  std::vector<std::vector<char>> F;
  CMS(const int aR, const int aC) {
    F = std::vector<std::vector<char>>(aC, std::vector<char>(aR, '.'));
  }
  int Rows() const { return F[0].size(); }
  int Cols() const { return F.size(); }
};

void fill(CMS& aMS, const int aR, const int aC) {
  if (aMS.F[aC][aR] != '.') {
    if (aMS.F[aC][aR] != 'c') {
      return;
    }
  }
  int M = 0;
  for (int dr=-1; dr<=1; dr++) {
    for(int dc=-1; dc<=1; dc++) {
      if (aR+dr>=0 && aR+dr<aMS.Rows() && aC+dc>=0 && aC+dc<aMS.Cols()) {
        if (aMS.F[aC+dc][aR+dr] == '*') {
          M++;
        }
      }
    }
  }
  aMS.F[aC][aR] = M;
  if (M==0) {
    for (int dr=-1; dr<=1; dr++) {
      for(int dc=-1; dc<=1; dc++) {
        if (aR+dr>=0 && aR+dr<aMS.Rows() && aC+dc>=0 && aC+dc<aMS.Cols()) {
          fill(aMS, aR+dr, aC+dc);
        }
      }
    }
  }
}

bool verify(CMS aMS) {
  for (int r=0; r<aMS.Rows(); r++) {
    for (int c=0; c<aMS.Cols(); c++) {
      if (aMS.F[c][r]=='c') {
        fill(aMS, r, c);
      }
    }
  }
  for (int r=0; r<aMS.Rows(); r++) {
    for (int c=0; c<aMS.Cols(); c++) {
      if (aMS.F[c][r]=='.') {
        return false;
      }
    }
  }
  return true;
}



struct CResult {
  bool impossible;
  bool rotated;
  CMS R;
};

void OneM(CMS& aMS) {
  for (int r=0; r<aMS.Rows(); r++) {
    for (int c=0; c<aMS.Cols(); c++) {
      aMS.F[c][r] = '*';
    }
  }
  aMS.F.back().back()='c';
}

void OneCol(const int aM, CMS& aMS) {
  assert(aMS.Cols()==1);
  for (int r=0; r<aM; r++) {
    aMS.F[0][r] = '*';
  }
  aMS.F[0].back() = 'c';
}

bool TwoCol(const int aM, CMS& aMS) {
  assert(aMS.Cols()==2);
  if (aM%2 || aMS.Cols()*aMS.Rows()-aM==2) {
    return false;
  }
  for (int r=0; r<aM/2; r++) {
    aMS.F[0][r] = '*';
    aMS.F[1][r] = '*';
  }
  aMS.F[0].back() = 'c';
  return true;
}


void EasySolve(const int aM, CMS& aMS) {
  aMS.F.back().back() = 'c';
  int D = aM;
  for (int r=0; r<aMS.Rows(); r++) {
    for (int c=0; c<aMS.Cols(); c++) {
       if (D) {
         if (D==1 && c==aMS.Cols()-2) {
           aMS.F[0][r+1] = '*';
           return;
         }
         aMS.F[c][r] = '*';
         D--;
       }
    }
  }
}

bool HardSolve(const int aM, CMS& aMS) {
  const int D = aMS.Rows()*aMS.Cols()-aM;
  for (int r=0; r<aMS.Rows(); r++) {
    for (int c=0; c<aMS.Cols(); c++) {
      aMS.F[c][r] = '*';
    }
  }
  if ((D<8 && D%2) || D==2) {
    return 0;
  }

  const int H = D/3+(!!(D%3));
  for (int r=0; r<H; r++) {
    for (int c=0; c<3; c++) {
      aMS.F[c][r] = '.';
    }
  }
  aMS.F[0][0] = 'c';
  if (H>3) {
    if (H*3-D>0) {
      aMS.F[2][H-1] = '*';
    }
    if (H*3-D>1) {
      aMS.F[2][H-2] = '*';
    }
  }
  if (D==8) {
    aMS.F[2][2] = '*';
  }
  if (D==4) {
    aMS.F[2][0] = '*';
    aMS.F[2][1] = '*';
  }

  return 1;

}

CResult Solve(CProblem aProblem) {
  bool rotate = 0;
  if (aProblem.R < aProblem.C) {
    rotate = 1;
    std::swap(aProblem.R, aProblem.C);
  }

  CMS cms(aProblem.R, aProblem.C);
  if (aProblem.M==aProblem.R*aProblem.C-1) {
    OneM(cms);
    return {false, rotate, cms};
  }
  if (aProblem.C==1) {
    OneCol(aProblem.M, cms);
    return {false, rotate, cms};
  }
  if (aProblem.C==2) {
    if (TwoCol(aProblem.M, cms)==0) {
      return {true, rotate, cms};
    }
    else {
      return {false, rotate, cms};
    }
  }
  const int D = aProblem.R*aProblem.C-aProblem.M;
  if (D>=aProblem.C*3) {
    EasySolve(aProblem.M, cms);
    return {0, rotate, cms};
  }
  else {
    if (HardSolve(aProblem.M, cms)) {
      return {0, rotate, cms};
    }
    else {
      return {1, rotate, cms};
    }
  }


  return {1, 0, cms};
}


int main(int argc, char* argv[]) {
  //const std::string KFileName = "test.txt";
  //const std::string KFileName = "C-small-attempt3.in";
  const std::string KFileName = "C-large.in";

  std::ifstream ifs(KFileName);
  assert(ifs);

  u32 N;
  ifs >> N;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<N; i++) {
    CProblem problem;

    ifs >> problem.R >> problem.C >> problem.M;

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout << "Case #" << i+1 << ": \n";
    if (result.impossible) {
      std::cout << "Impossible\n";
    }
    else {
      if (result.rotated==1) {
        for (int c=0; c<result.R.Cols(); c++) {
          for (int r=0; r<result.R.Rows(); r++) {
             std::cout << result.R.F[c][r];
          }
          std::cout << "\n";
        }
      }
      else {
        for (int r=0; r<(int)result.R.Rows(); r++) {
          for (int c=0; c<(int)result.R.Cols(); c++) {
             std::cout << result.R.F[c][r];
          }
          std::cout << "\n";
        }
      }
      assert(verify(result.R));
    }

    //std::cout << result.A << " " << result.B << "\n";
  }
}
