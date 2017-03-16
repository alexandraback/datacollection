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
    int N;
    cin >> N;
    
    std::vector<double> v1(N, double());
    std::vector<double> v2(N, double());
    for (i = 0; i < N; i++) {
      cin >> v1[i];
    }
    for (i = 0; i < N; i++) {
      cin >> v2[i];
    }
    
    sort( v1.begin(), v1.end() );
    sort( v2.begin(), v2.end() );

    int dwar_num = 0;    
    {
      unsigned int i2 = 0;
      for (unsigned int i1 = 0; i1 < v1.size(); i1++) {
	if (v1[i1] > v2[i2])
	  i2++;
      }
      dwar_num = i2;
    }

    int war_num = 0;
    {
      unsigned int i1 = 0;
      for (unsigned int i2 = 0; i2 < v2.size(); i2++) {
	if (v2[i2] > v1[i1])
	  i1++;
      }
      war_num = v1.size() - i1;
    }
    
    std::cout << "Case #" << (t+1) << ": " << dwar_num << " " << war_num << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
