#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ULL unsigned long long

string deb_int(ULL a, int d=64) {
  int i;
  string res=string(d,'0');
  for(i=0;i<d;i++)
    if ((1ULL<<i)&(a)) res[d-i-1]='1';
  return res;
}

void solve(int ind) {
    // input
    ULL A, B, K;
    cin >> A >> B >> K;

    // small - just try all pairs
    int np = 0;
    for (int i = 0; i < A; ++i)
    for (int j = 0; j < B; ++j) {
        if ((i & j) < K) {
            ++np;
        }
    }

    // output
    cout << "Case #" << ind << ": " << np << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}