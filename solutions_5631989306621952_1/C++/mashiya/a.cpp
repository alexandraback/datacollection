#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int j = 0; j < n;j++) {
    string in;
    string out;
    cin >>in;
    out.push_back(in[0]);
    for(int i = 1; i < in.size(); i++) {
      if (in[i] >= out[0]) {
        out.insert(0, 1, in[i]);
      } else {
        out.push_back(in[i]);
      }
    }
    cout << "Case #" << j+1 << ": " << out << endl;
  }
  return 0;
}
