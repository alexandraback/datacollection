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

ifstream fin("B.in");
ofstream fout("B.out");

int T;
string input;

int main() {
  fin >> T;
  for (int tt = 1; tt <= T; tt++) {
    fin >> input;
    input += "+";
    int ans = 0;
    for (int i = 0; i < input.length()-1; i++) {
    	if (input[i] != input[i+1]) ans++;
    }
    fout << "Case #" << tt << ": " << ans << "\n";
  }
  return 0;
}