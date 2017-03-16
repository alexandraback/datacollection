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

int N,T;

ifstream fin("A.in");
ofstream fout("A.out");

int main() {
  fin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Working on Case #" << tt << "\n";
    string input;
    fin >> input;
    string ans = "";
    for (int i = 0; i < input.length(); i++) {
    	string ans1 = ans+input[i];
    	string ans2 = "";
    	ans2+=input[i];
    	ans2+=ans;
    	if (ans1.compare(ans2) < 0) ans = ans2;
    	else ans = ans1;
    }
    fout << "Case #" << tt << ": " << ans << "\n";
  }
  return 0;
}