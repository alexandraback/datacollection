#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

// void solve() {
//   int T;
//   cin >> T;
//   for (int t = 0; t < T; t++) {
//     int D;
//     cin >> D;

//     std::vector<int> vv(D);    for (int i = 0; i < D; i++) { cin >> vv[i]; }
//     // sort( vv.begin(), vv.end() );

//     std::vector<int > hist(1001, int());
//     for (int i = 0; i < D; i++) { hist[vv[i]]++; }
    
//     int result = 0;
//     int result_candidate = 1000;
//     while (true) {
//       int highest = 0;
//       for (int i = 1000; i >= 1; i--) {
// 	if (hist[i] != 0) { highest = i; break; }
//       }
      
//       if (highest == 1) {
// 	result++;
// 	break;
//       }
      
//       int n = hist[highest];
//       result_candidate = min(result_candidate, result+highest);

//       hist[highest] = 0;
//       if (highest % 2 == 0) {
// 	hist[highest/2] += 2*n;
//       } else {
// 	hist[highest/2] += n;
// 	hist[highest/2+1] += n;
//       }
//       result += n;
//       continue; 
//     }

//     std::cout << "Case #" << (t+1) << ": " << min(result, result_candidate) << std::endl;
//   }
// }

std::map<std::tuple<int, int, int, int, int, int, int, int>, int > mm;

int solve_helper(std::vector<int>& vv) {
  cerr << "pop  ";
  for (int i = 1; i < 10; i++) {
    cerr << vv[i] << " "; 
  }
  cerr << endl;

  int cached_result = mm[make_tuple(vv[2], vv[3], vv[4], vv[5], vv[6], vv[7], vv[8], vv[9])];
  if (cached_result != 0) {
    return cached_result;
  } else {
    bool b = true;
    for (int i = 2; i <= 9; i++) {
      if (vv[i]!=0) b = false;
    }
    if (b) return 1;

    int result = 9;

    {
      std::vector<int > vvv2(10, int());
      for (int i = 1; i < 9; i++) {
	vvv2[i] = vv[i+1];
      }
      cerr << "push ";
      for (int i = 1; i < 10; i++) {
	cerr << vvv2[i] << " "; 
      }
      cerr << endl;
      result = min(result, solve_helper(vvv2)+1);
    }

    for (int i = 2; i < 10; i++) {
      if (vv[i] == 0) continue;

      for (int j = 1; j < i; j++) {
	std::vector<int > vvv2(vv);
	vvv2[i]--;

	vvv2[j] += 1;
	vvv2[i-j] += 1;
	
	cerr << "push ";
	for (int i = 1; i < 10; i++) {
	  cerr << vvv2[i] << " "; 
	}
	cerr << endl;
      
	result = min(result, solve_helper(vvv2)+1);
      }
      // if (i % 2 == 0) {
      // 	vvv2[i/2] += 2;
      // } else {
      // 	vvv2[i/2] += 1;
      // 	vvv2[i/2+1] += 1;
      // }
      
    }
    
    mm[make_tuple(vv[2], vv[3], vv[4], vv[5], vv[6], vv[7], vv[8], vv[9])] = result;
    return result;
  }
}

void solve() {
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    int D;
    cin >> D;

    cerr << "PROBLEM " << t << endl;

    std::vector<int> vv(D);    for (int i = 0; i < D; i++) { cin >> vv[i];   if (vv[i]<=0 || vv[i]>9) {cout << "invalid"; return;}}
   // sort( vv.begin(), vv.end() );
    std::vector<int > hist(10, int());
    for (int i = 0; i < D; i++) { hist[vv[i]]++; }
    
    int result = solve_helper(hist);
    std::cout << "Case #" << (t+1) << ": " << result << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
