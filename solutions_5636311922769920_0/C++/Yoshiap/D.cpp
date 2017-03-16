#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

int T;
int K,C,S;

ifstream fin("D.in");
ofstream fout("D.out");

ll intpow(ll b,ll p) {
	ll ans = 1;
	for (int i = 0; i < p; i++) ans*=b;
  return ans;
}

int main() {
  fin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Working on Case #" << tt << "\n";
    fin >> K >> C >> S;
    if (C*S < K) {
    	fout << "Case #" << tt << ": " << "IMPOSSIBLE\n";
      continue;
    }
    ll ind = 0;
    ll curpow = 0;
    ll curans = 0;
    fout << "Case #" << tt << ":";
    while (ind < K) {
      curans += ind*intpow(K,curpow);
      //cout << curans << "\n"
      ind++;
      curpow++;
      if (curpow == C) {
        curans++;
        fout << " " << curans;
        curans = 0;
        curpow = 0;
      }
    }
    if (curpow != 0) {
      curans++;
      fout << " " << curans;
    }
    fout << "\n";
  }
  return 0;
}