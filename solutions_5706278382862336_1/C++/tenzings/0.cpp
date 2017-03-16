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

uint64_t gcd(uint64_t P, uint64_t Q) {
  if(!Q) return P;
  else return gcd(Q, P % Q);
}

pair<uint64_t, uint64_t> reduce(uint64_t P, uint64_t Q) {
  uint64_t factor = gcd(P, Q);
  if(factor > 1) {
    return reduce(P / factor, Q / factor);
  } else {
    return make_pair(P, Q);
  }
}

int is_pow_2(uint64_t Q) {
  if(Q == 1 || Q == 0) return true;
  else if(Q % 2 == 0) return is_pow_2(Q / 2);
  else return false;
}

string solve(uint64_t P, uint64_t Q) {
  pair<uint64_t, uint64_t> reduced = reduce(P, Q);
  P = reduced.first;
  Q = reduced.second;
  if(!is_pow_2(Q)) return "impossible";
  int ans = 1;
  while(P < Q / 2) {
    Q /= 2;
    ans++;
  }
  if(ans > 40) return "impossible";
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
