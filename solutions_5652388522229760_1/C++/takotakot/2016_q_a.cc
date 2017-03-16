#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<iterator>

struct solver_2016_q_a {
  std::string run(int N) {
    std::string insomnia = "INSOMNIA";
    std::stringstream ss;
    std::set<int> set_digit;
    long long num_checking, num;
    int d;

    if(N == 0) return insomnia;
    for(int i = 0; i < 10000000; ++i) {
      num_checking = i * N;
      num = num_checking;
      // std::cerr << num;
      while(num != 0) {
        d = num % 10;
        set_digit.insert(d);
        num /= 10;
      }
      if(set_digit.size() == 10) {
        ss << num_checking;
        return ss.str();
      }
    }

    return insomnia;
  }

};

int main(void) {
  solver_2016_q_a solver;

  int T, N;

  std::cin >> T;
  for(int i = 0; i < T; ++i) {
    std::cin >> N;
    std::cout << "Case #" << (i+1) << ": " << solver.run(N) << std::endl;
  }

  return 0;
}
