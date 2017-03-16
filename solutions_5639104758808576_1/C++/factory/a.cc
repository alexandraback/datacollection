#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int s_max = 0;
    string data;
    cin >> s_max >> data;

    int clapping_people = 0;
    int answer = 0;
    for (int i = 0; i < data.size(); ++i) {
      if (data[i] == '0') {
        continue;
      }
      if (clapping_people < i) {
        answer += i - clapping_people;
        clapping_people = i;
      }
      clapping_people += (data[i] - '0');
    }

    cout << "Case #" << tt << ": " << answer << "\n";
  }
  
  return 0;
}

