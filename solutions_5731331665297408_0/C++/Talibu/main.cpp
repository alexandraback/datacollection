#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stack>

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
  std::vector<int> postal;
  std::vector<std::vector<int>> edge;
};

struct CResult {
  std::vector<int> S;
};

bool tryout(std::vector<int> aPerm, std::vector<std::vector<int>> edges) {
  std::stack<int> pos;
  std::vector<int> outb(aPerm.size());
  outb[aPerm[0]] = 1;
  pos.push(aPerm[0]);
  int ppos = 0;

  while (!pos.empty()) {
   // std::cout << pos.top() << "\n";
    if (ppos<(int)aPerm.size()-1 && edges[pos.top()][aPerm[ppos+1]] && outb[aPerm[ppos+1]]==0) {
      edges[pos.top()][aPerm[ppos+1]] = 0;
      pos.push(aPerm[ppos+1]);
      outb[aPerm[ppos+1]] = 1;
      ppos++;
    }
    else {
      int mpos = pos.top();
      pos.pop();
      if (!pos.empty())
        edges[mpos][pos.top()] = 0;
    }
  }

  for (int i=0; i<(int)outb.size(); i++)
    if (outb[i]==0)
      return 0;

  return 1;
}

CResult Solve(CProblem aProblem) {
  CResult rtn;

  std::vector<int> perm(aProblem.postal.size());
  std::iota(perm.begin(), perm.end(), 0);

  std::vector<int> target(aProblem.postal.size(), 99999);

 do {

    std::vector<int> tperm(aProblem.postal.size());
    for (uint i=0; i<aProblem.postal.size(); i++)
      tperm[i] = aProblem.postal[perm[i]];
    if (tperm < target) {
      auto edges = aProblem.edge;
      if (tryout(perm, edges))
        target = tperm;
    }
  } while (std::next_permutation(perm.begin(), perm.end()));

  rtn.S = target;
  return rtn;
}


int main(int argc, char* argv[]) {
  //const std::string KFileName = "test.txt";
  const std::string KFileName = "C-small-attempt0.in";
  //const std::string KFileName = "B-large-practice.in";

  std::ifstream ifs(KFileName);
  assert(ifs);


  u32 T;
  ifs >> T;
  std::string D;
  std::getline(ifs, D);

  for (u32 i=0; i<T; i++) {
    CProblem problem;
   
    int N, M;
    ifs >> N >> M;
    problem.edge = std::vector<std::vector<int>>(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
      int post;
      ifs >> post;
      problem.postal.push_back(post);
    }
    for (int i = 0; i < M; ++i) {
      int s, t;
      ifs >> s >> t;
      problem.edge[s-1][t-1] = 1;
      problem.edge[t-1][s-1] = -1;
    }

    std::cerr << "Solving Problem " << i << "\n";
    const CResult result = Solve(problem);
    std::cout << "Case #" << i+1 << ": ";
    for (const auto s : result.S)
      std::cout << s;
    std::cout << "\n";
  }
}
