#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int i, j;
  
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    double C, F, X;
    cin >> C >> F >> X;
    
    double time_consumed = 0;
    double cookies = 0;
    double cookie_per_sec = 2.0;
    
    while (true) {
      double next_time = C / cookie_per_sec;
      time_consumed += next_time;
      cookies += C;
      
      double rest = X - cookies;
      
      if (rest / cookie_per_sec > 
	  X    / (cookie_per_sec + F)) {
	cookies = 0;
	cookie_per_sec += F;
      } else {
	time_consumed += rest / cookie_per_sec;
	break;
      }
    }

    std::cout << "Case #" << (t+1) << ": " << std::fixed << std::setprecision(7) << time_consumed << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
