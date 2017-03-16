#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

long long K[17];
long long pow10k[17];

long long arr[1000001];

void Precalc() {
  for(int i = 0; i <= 1000000; ++i)
    arr[i] = 1e9;
  arr[1] = 1;
  for(int i = 1; i < 1000000; ++i) {
    arr[i+1] = std::min(arr[i] + 1, arr[i+1]);
    std::string s = std::to_string(i);
    std::reverse(s.begin(), s.end());
    int r = std::stoi(s);
    arr[r] = std::min(arr[r], arr[i] + 1);
  }
}

long long Revert(long long v, int l) {
  long long ret = 0;
  for(int i = 0; i < l; ++i) {
    ret += pow10k[l-1-i] * ((v / pow10k[i]) % 10);
  }
  return ret;
}
void Run(int testcase) {
  std::string ns;
  cin >> ns;
 // long long N = std::stoll(ns);
  int n = ns.size();
  int upperLen = n/2;
  int lowerLen = (n + 1)/2;
  long long base = K[n-1];
  
  long long upper = 0;
  long long lower = 0;
  for(int i = 0; i < upperLen; ++i)
    upper += (ns[ i] - '0') * pow10k[i];
  for(int i = 0; i < lowerLen; ++i)
    lower += (ns[n - 1 - i] - '0') * pow10k[i];
  
  
  long long cost = base;
  if(upper == 1)
    cost += lower;
  else if(lower == 0) {
    auto orig = upper;
    upper = Revert(Revert(upper, upperLen) -1, upperLen);
    cost += pow10k[lowerLen] + upper  - 1+ ((orig ==pow10k[upperLen - 1] + 1) ? 0 : 1);

  } else
    cost += lower + upper;
  cout << "Case #" << testcase << ": " << cost << "\n";
}


void CalcK() {
  K[0] = 0;
  K[1] = 10;
  pow10k[0] = 1;
  pow10k[1] = 10;
  for(int i = 2; i < 17; ++i) {
    pow10k[i] = 10 * pow10k[i-1];
    K[i] = K[i-1] + (pow10k[i/2] - 1) + (pow10k[(i+1)/2] - 1) + 1;
  //  std::cout << "K" << i << " : " << K[i] << "\n";
  }
}
int main() {
  CalcK();
  Precalc();
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i)
    Run(i);
}