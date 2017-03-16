#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

string num_to_str(uint64_t num) {
	ostringstream ss;
	ss << num;
	return ss.str();
}

bool is_pow_2(uint64_t Q) {
  if(Q == 1 || Q == 0) return true;
  else if(Q % 2 == 0) return is_pow_2(Q / 2);
  else return false;
}

string solve(uint64_t P, uint64_t Q) {
  if(!is_pow_2(Q)) return "impossible";
  int ans = 1;
  while(P < Q / 2) {
    Q /= 2;
    ans++;
  }
  return num_to_str(ans);
}


int main(void) 
{
	int TC;
	cin >> TC;
	for(int tc = 0; tc < TC; tc++) {
		uint64_t P, Q;
    char slash;
		cin >> P >> slash >> Q;
    cout << "Case #" << (tc + 1) << ": " << solve(P, Q) << endl;
	}
	return 0;
}
