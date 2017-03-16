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

ifstream fin("A.in");
ofstream fout("A.out");

int N,T;
bool seen[15];

int main() {
  fin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Working on Case #" << tt << "\n";
    for (int i = 0; i < 10; i++) seen[i] = false;
    fin >> N;
    int cnt = 0;
    int cur = 0;
    while (cnt < 100) {
      cur += N;
      int temp = cur;
      while (temp > 0) {
        seen[temp%10] = true;
        temp/=10;
      }
      int tempa = 0;
      for (int i = 0; i < 10; i++) if (seen[i]) tempa++;
      if (tempa == 10) break;
      cnt++;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) if (seen[i]) ans++;
    if (ans == 10) fout << "Case #" << tt << ": " << cur << "\n";
    else fout << "Case #" << tt << ": " << "INSOMNIA" << "\n";
  }
  return 0;
}