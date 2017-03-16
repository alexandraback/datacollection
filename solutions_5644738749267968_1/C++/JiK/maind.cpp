/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some c++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including -lgmp and -lgmpxx in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <gmpxx.h>


int solveDWar(int N,   
	      std::vector<double> naomi,
	      std::vector<double> ken) {
  
  int res = 0;
  for(int i=0; i<N; i++) {
    if(naomi.front() > ken.front()) {
      //Cheat and score!
      //      std::cout << "Naomi plays " << naomi.front() << " Ken plays "
	//		<< ken.front() << " -- Naomi scores.\n";
      res++;
      naomi.erase(naomi.begin());
      ken.erase(ken.begin());
      continue;
    }

    assert(naomi.front() < ken.back());
      //      std::cout << "Naomi plays " << naomi.front() << " Ken plays "
	//		<< ken.back() << "\n";
      //Cheat
    naomi.erase(naomi.begin());
    ken.pop_back();
  }
  return res;
}


int solveWar(int N,   
	      std::vector<double> naomi,
	      std::vector<double> ken) {
  int res = 0;

  for(int i=0; i<N; i++) {
    if(naomi.back() > ken.back()) {
      //Naomi scores
      res++;
      naomi.pop_back();
      ken.erase(ken.begin());
      continue;
    }
    //Otherwise Naomi plays highest and ken plays smallest that wins?
    double lim = naomi.back();
    naomi.pop_back();
    //Binary search here? O(n^2) is fast enough, i think.
    for(auto it = ken.begin(); it != ken.end(); it++) {
      if((*it) > lim) {
	ken.erase(it);
	break;
      }
    }
  }

  return res;
}

std::pair<int,int> solve() {
  int N;
  std::cin >> N;
  std::vector<double> naomi;
  std::vector<double> ken;

  for(int i=0;i<N;i++) {
    double tmp;
    std::cin >> tmp;
    naomi.push_back(tmp);
  }
  for(int i=0;i<N;i++) {
    double tmp;
    std::cin >> tmp;
    ken.push_back(tmp);
  }
  
  std::sort(naomi.begin(), naomi.end()); 
  std::sort(ken.begin(), ken.end());

  /*
  std::cout << "Naomi: ";
  for(int i=0; i<N; i++) std::cout << naomi[i] << " ";
  std::cout << '\n';

  std::cout << "Ken: ";
  for(int i=0; i<N; i++) std::cout << ken[i] << " ";
  std::cout << '\n';
  */    

  int dwar = solveDWar(N, naomi, ken);
 

  int war = solveWar(N, naomi, ken);
  return std::pair<int,int>(dwar, war);

}

void pre_compute() {
  
}

int main() {
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    auto res = solve();
    std::cout << "Case #" << i << ": " << res.first << " " 
	      << res.second << "\n";
  }

  return 0;
}
