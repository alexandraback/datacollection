#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>

typedef std::pair<int, int> t_pair;

struct solver_2016_1_c_c {
  int J, P, S, K;
  std::map<t_pair, int> cjp, cps, cjs;

  solver_2016_1_c_c() {
    return;
  }

  std::string run(int J_, int P_, int S_, int K_) {
    std::stringstream ss, tss;
    long long cnt = 0;
    t_pair jp, ps, js;
    cjp.clear();
    cps.clear();
    cjs.clear();

    // std::vector<std::stringstream> sss;

    J = J_;
    P = P_;
    S = S_;
    K = K_;

    // use 1 origin
    int res = 0;
    for(int s = 1; s <= S; ++s) {
      for(int p = 1; p <= P; ++p) {
        ps = t_pair(p, s);
        for(int j = 1; j <= J; ++j) {
          tss.clear();
          js = t_pair(j, s);
          jp = t_pair(j, p);
          res = add(jp, js, ps);
          if(res) {
            cnt += res;
            tss << std::endl << j << ' ' << p << ' ' << s;
          }
        }
      }
    }
    ss << cnt << tss.str();

    return ss.str();
  }

  int add(t_pair jp, t_pair js, t_pair ps) {
    if(cjp[jp] < K && cjs[js] < K && cps[ps] < K) {
      ++cjp[jp];
      ++cjs[js];
      ++cps[ps];
      return 1;
    }
    return 0;
  }

};

int main(void) {
  solver_2016_1_c_c solver;

  int T;
  int J, P, S, K;

  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cin >> J >> P >> S >> K;
    std::cerr << J<< P<< S << K << std::endl;
    // std::cerr << "Case #" << (i + 1) << ": " << solver.run(S) << std::endl;
    std::cout << "Case #" << (i + 1) << ": " << solver.run(J, P, S, K) << std::endl;
  }

  return 0;
}
