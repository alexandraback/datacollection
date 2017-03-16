#include <iostream>
#include <fstream>
#include <string>
#include <deque>

using namespace std;

const int kMaxN = 1005;

int main() {
  ifstream in;
  in.open("dataset.in");
  ofstream out;
  out.open("dataset.out");

  int T;
  in >> T;

  for (int i = 0; i < T; ++i) {
    string s;
    in >> s;
    int n = s.size();
    deque < char > dq;
    dq.push_front(s[0]);
    for (int j = 1; j < n; ++j)
        if (s[j] >= dq[0])
            dq.push_front(s[j]);
        else
            dq.push_back(s[j]);
    string ans;
    for (int j = 0; j < n; ++j)
        ans.push_back(dq[j]);
    out << "Case #" << (i + 1) << ": " << ans << "\n";
  }

  in.close();
  out.close();
  return 0;
}
