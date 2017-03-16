#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int valid_trains(const vector<string> &car_sets, vector<bool> &used, set<char> &enclosed, char last, int depth) {
  int valid = 0;
  int N = car_sets.size();
  if (depth == N) {
    return 1;
//     cerr << "bottom" << endl;
  }
  for (int i = 0; i < N; ++i) {
    if (not used[i]) {
//       cerr << "Testing " << car_sets[i] << endl;
      int initial = (last == car_sets[i][0]? 1 : 0);
      bool wrong = false;
      for (int j = initial; j < car_sets[i].size() and not wrong; ++j) {
	if (not enclosed.insert(car_sets[i][j]).second) {
	  for (int k = initial; k < j; ++k) {
	    enclosed.erase(car_sets[i][k]);
	  }
	  wrong = true;
	}
      }
      if (wrong) continue;
      used[i] = true;
//       cerr << "added" << endl;
      valid += valid_trains(car_sets, used, enclosed, car_sets[i][car_sets[i].size() - 1], depth + 1);
      used[i] = false;
      for (int j = initial; j < car_sets[i].size(); ++j) {
	enclosed.erase(car_sets[i][j]);
      }
    }
  }
  return valid;
}

string compact(const string &s) {
  string res;
  char ant = '\0';
  for (int i = 0; i < s.size(); ++i) {
    if (ant != s[i]) res += s[i];
    ant = s[i];
  }
  return res;
}

int main () {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cout << "Case #" << cas << ": ";
    int N;
    cin >> N;
    vector<string> car_sets(N);
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      car_sets[i] = compact(s);
//       cerr << car_sets[i] << endl;
    }
    vector<bool> used(N, false);
    set<char> encl;
    cout << valid_trains(car_sets, used, encl, '\0', 0) << endl;
  }
}