#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>

struct solver_2016_1_c_b {
  // use 0-origin

  solver_2016_1_c_b() {
    return;
  }

  std::string run(int B, int M) {
    std::stringstream ss;
    std::vector<std::string> utr(B);
    std::vector<long long> table(B);
    std::vector<int> use(B);
    char zero = '0', one = '1';

    // build rectanble with small triangle
    for(int i = 0; i < B-1 ; ++i) {
      for(int j = 0; j <= i; ++j) {
        utr[i] += zero;
      }
      for(int j = i+1; j < B-1; ++j) {
        utr[i] += one;
      }
      // std::cerr << utr[i] << std::endl;
    }
    for(int j = 0; j < B-1; ++j) {
      utr[B-1] += zero;
    }
    // std::cerr << utr[B-1] << std::endl;

    long long t = 1;
    table[0] = 1;
    std::cerr << 1 << "\t";
    for(int i = 1; i < B-1; ++i) {
      table[i] = t;
      std::cerr << t << "\t";
      t *= 2;
    }
    std::cerr << std::endl;

    long long remain = M;
    // begin with B-2
    use[B-1] = 0;
    for(int i = B-2; i >= 0; --i) {
      if(remain >= table[i]) {
        use[i] = 1;
        remain -= table[i];
      }else{
        use[i] = 0;
      }
    }
    if(remain == 0) {
      ss << "POSSIBLE";
      for(int i = 0; i < B; ++i) {
        ss << std::endl << utr[i] << (char)('0' + use[i]);
      }
    }else{
      ss << "IMPOSSIBLE";
    }
    return ss.str();
  }

};

int main(void) {
  solver_2016_1_c_b solver;

  int T, B, M;
  std::string S;

  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cin >> B >> M;
    std::cerr << B << " " << M << std::endl;
    // std::cerr << "Case #" << (i + 1) << ": " << solver.run(S) << std::endl;
    std::cout << "Case #" << (i + 1) << ": " << solver.run(B, M) << std::endl;
  }

  return 0;
}
