#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tokenizer.hpp>

using namespace std;

class Solver {
public:
  Solver(const char* in, const char* out) : ifs(in), ifName(in), ofName(out) {
    if(!ifs.is_open()){
      std::cout << ifName << " is not found" << std::endl;
      assert(0);
    }
    ifs >> T;
  }
  ~Solver(){ ifs.close(); }

  std::ostream& dump(std::ostream& s) const{
    stringstream ss;
    for (int i=0;i<T;i++) {
      ss << "Case #" << i+1 << ": ";
      ss << setprecision(6);
      ss << setiosflags(ios::fixed);
      ss << answers[i] << endl;
      ss << setprecision(6);
    }
    s << ss.str();
    return s;
  }
  void output() const {
    std::ofstream ofs(ofName);

    dump(ofs);
  }

  void solve(){
    for(int test=0;test<T;test++){
      cout << "test: " << test+1 << endl;
      int A, B;
      vector<double> p;
      inputTest(&A, &B, &p);
      double min = B+2;
      for(int i=0;i<A;i++){
        double notMistaked = 1;
        for(int j=0;j<A-i;j++){
          notMistaked *= p[j];
        }
        double expected = notMistaked * (2*i-A+B+1) + (1-notMistaked) * (2*i-A+2*B+2);
        if(min>expected) min = expected;
      }

      double ans = min;
      answers.push_back(ans);
    }
  }

private:
  bool inputTest(int* A, int* B, vector<double>* p){
    if(!ifs.is_open()){
      cout << ifName << " is not found" << endl;
      assert(0);
    }
        ifs >> *A >> *B;
        for(int i=0;i<*A;i++){
          double tmp;
          ifs >> tmp;
          p->push_back(tmp);
        }
    return true;
  }

  std::ifstream ifs;
  const char* ifName; const char* ofName;
  int T;
  std::vector<double> answers;
};

std::ostream& operator<<(std::ostream& s, const Solver& sol){ return sol.dump(s); }

int main() {
  Solver s("data/A-large.in", "data/A-large.out");
  s.solve();
  s.output();

  return 0;
}
