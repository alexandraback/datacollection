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
      ss << "Case #" << i+1 << ": " << answers[i] << endl;
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
      cout << "==test " << test+1 << endl;
      int N;
      vector<int> A, B; // a: ‚P‚Â¯, b: 2‚Â¯ ‚É‚©‚©‚éš
      inputTest(&N, &A, &B);
      vector<bool> CompA, CompB;
      for(int i=0; i<N;i++){
        CompA.push_back(false);
        CompB.push_back(false);
      }

      bool isBad = false;
      int now = 0, step = 0;
      while(true){
        bool isFound = false;

        // 2-star search
        for(int i=0;i<N;i++){
          if(!CompB[i] && now>=B[i]){
            cout << "B[" << i << "]" << endl;
            isFound = true;
            CompB[i] = true;
            if(!CompA[1]){
              now += 2;
              CompA[i] = true;
            }else{
              bool hasDuplicate = false;
              for(int j=0;j<N;j++){
                // ‘¼‚Ì1-star‚ÉŠ„‚è“–‚Ä‚é
                if(CompA[j]){
                  now += 2;
                  CompA[j] = true;
                  hasDuplicate = true;
                  break;
                }
              }

              if(!hasDuplicate){
                now += 1;
              }
            }

            break;
          }
        }

        // 1-star search

        for(int i=0;i<N;i++){
          if(!CompA[i] && now>=A[i]){
            cout << "A[" << i << "]" << endl;
            isFound = true;
            CompA[i] = true;
            now += 1;

            break;
          }
        }

        // break
        if(!isFound){
          for(int i=0;i<N;i++){
            if(!CompB[i]) isBad = true;
          }
          break;
        }

        step++;
      } // end while

      if(!isBad){
        stringstream ans;
        ans << step;
        answers.push_back(ans.str());
      }else{
        answers.push_back("Too Bad");
        continue;
      }
    }
  }

private:
  void inputTest(int* N, vector<int>* a, vector<int>* b){
    if(!ifs.is_open()){
      cout << ifName << " is not found" << endl;
      assert(0);
    }
    ifs >> *N;
    for(int i=0;i<*N;i++){
      int tmp;
      ifs >> tmp;
      a->push_back(tmp);
      ifs >> tmp;
      b->push_back(tmp);
    }
  }

  std::ifstream ifs;
  const char* ifName; const char* ofName;
  int T;
  std::vector<string> answers;
};

std::ostream& operator<<(std::ostream& s, const Solver& sol){ return sol.dump(s); }

int main() {
  Solver s("data/B-small-attempt0.in", "data/B-small-attempt0.out");
  s.solve();
  s.output();

  cout << s;

  return 0;
}
