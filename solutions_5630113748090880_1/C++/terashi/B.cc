#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int N;

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    cin >> N;
    map<int, int> cnt;
    for (int i = 0; i < 2*N-1; ++i) {
      for (int j = 0; j < N; ++j) {
	int v;
	cin >> v;
	++cnt[v];
      }
    }
    cout << "Case #" << iii+1 << ":";
    for (const auto& p : cnt) {
      if (p.second % 2 == 1)
	cout << " " << p.first;
    }
    cout << endl;
  }
}
