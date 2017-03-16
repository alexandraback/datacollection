#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

long num_pairs(int x, int limit) {
  stringstream ss;
  ss << x;
  string show_x = ss.str();
  int length_x = show_x.length();

  string perms [length_x];

  for(int i = 0; i < length_x; i++) {
    perms[i] = show_x.substr(i, length_x - 1) + show_x.substr(0, i);
  }

  string nubbed [length_x];
  set<string> nubbed_set;
  for(int i = 0; i < length_x; i++) {
    nubbed_set.insert(perms[i]);
  }

  int answer = 0;

  set<string>::iterator it;
  for(it = nubbed_set.begin(); it != nubbed_set.end(); it++) {
    int read_y;
    istringstream(*it) >> read_y;
    if(read_y > x && read_y <= limit) {
      answer++;
    }
  }

  return answer;
}
long solve(int a, int b) {
  long sum = 0;
  for(int i = a; i <= b; i++) {
    sum += num_pairs(i, b);
  }
  return sum;
}

int main() {
  int cases;
  cin >> cases;
  for(int case_number = 1; case_number <= cases; case_number++) {
    int a, b;
    cin >> a >> b;
    long answer = solve(a, b);
    cout << "Case #" << case_number << ": " << answer << endl;
  }
}
