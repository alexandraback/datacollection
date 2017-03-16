#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  int T; cin >> T;

  ofstream ofs("output.txt");
  for (int i = 0; i < T; i++) {
    string s; cin >> s;
    int n; cin >> n;

    int len = s.length();
    string vowels = "aeiou";
    vector<int> vi;
    for (int j = 0; j < len; j++) {
      int flg = 0;
      for (int k = 0; k < 5; k++) {
	if (s[j] == vowels[k]) flg++;
      }
      if (flg) vi.push_back(0);
      else vi.push_back(1);
    }

    int t = 0;
    for (int j = len-1; j >= 0; j--) {
      if (vi[j]) t++;
      else t = 0;

      if (t >= n) vi[j] = 2;

      //      cout << t << endl;
    }

    /*    for (int j = 0; j < len; j++) cout << vi[j];
	  cout << endl;*/

    int sum = 0;
    int cnt = 0;
    for (int j = len-1; j >= 0; j--) {
      if (vi[j] == 2) {
	cnt = max(cnt, max(0, len-j-n+1));
      }
      sum += cnt;
    }

    cout << "Case #" << i+1 << ": " << sum << endl;
    ofs << "Case #" << i+1 << ": " << sum << endl;
  }
  return 0;
}
