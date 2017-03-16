#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

long long best_solution;
string best_c;
string best_j;


void check_solution(string& c, string& j) {
  string::size_type sz = 0;   // alias of size_t
  string::size_type sz2 = 0;   // alias of size_t

  long long cc = stoll (c, &sz);
  long long jj = stoll (j, &sz2);

  long long res = abs(cc-jj);

  if (res < best_solution ||
      (res == best_solution && best_c > c) ||
      (res == best_solution && best_c == c && best_j > j)) {
    best_solution = res;
    best_c = c;
    best_j = j;
  }
}

void assign_lowest(string& s, int i) {
  for (int j=i+1; j<s.size(); j++) {
    if (s[j] == '?')
      s[j] = '0';
  }
}

void assign_biggest(string& s, int i) {
  for (int j=i+1; j<s.size(); j++) {
    if (s[j] == '?')
      s[j] = '9';
  }
}

void solve(string c, string j, int i) {
  if (c.size() == i) {
    //cout << "c converting: " << c << " and " << j << endl;
    check_solution(c, j);
  }

  if (c[i] != '?' && j[i] != '?') {
    if (c[i] == j[i]) {
      solve(c, j, i+1);
    } else if (c[i] > j[i]) {
      assign_lowest(c, i);
      assign_biggest(j, i);

  //cout << "a converting: " << c << " and " << j << endl;
      check_solution(c, j);
    } else {
      assign_lowest(j, i);
      assign_biggest(c, i);

  //cout << "b converting: " << c << " and " << j << endl;
      check_solution(c, j);
    }
  } else if (c[i] == '?' && j[i] != '?') {
    c[i] = j[i];
    solve(c, j, i+1);
    c[i] = char('0' + (int(j[i]-'0')+1) % 10);
    if (c[i] > j[i]) {
      string c2 = c;
      string j2 = j;
      assign_lowest(c2, i);
      assign_biggest(j2, i);
      check_solution(c2, j2);
    } else {
      string c2 = c;
      string j2 = j;
      assign_biggest(c2, i);
      assign_lowest(j2, i);
      check_solution(c2, j2);
    }
    c[i] = char('0' + (int(j[i]-'0')+9) % 10);

    if (c[i] > j[i]) {
      string c2 = c;
      string j2 = j;
      assign_lowest(c2, i);
      assign_biggest(j2, i);
      check_solution(c2, j2);
    } else {
      string c2 = c;
      string j2 = j;
      assign_biggest(c2, i);
      assign_lowest(j2, i);
      check_solution(c2, j2);
    }
  } else if (j[i] == '?' && c[i] != '?') {
    j[i] = c[i];
    solve(c, j, i+1);
    j[i] = char('0' + (int(c[i]-'0')+1) % 10);
    if (c[i] > j[i]) {
      string c2 = c;
      string j2 = j;
      assign_lowest(c2, i);
      assign_biggest(j2, i);
      check_solution(c2, j2);
    } else {
      string c2 = c;
      string j2 = j;
      assign_biggest(c2, i);
      assign_lowest(j2, i);
      check_solution(c2, j2);
    }
    j[i] = char('0' + (int(c[i]-'0')+9) % 10);
    if (c[i] > j[i]) {
      string c2 = c;
      string j2 = j;
      assign_lowest(c2, i);
      assign_biggest(j2, i);
      check_solution(c2, j2);
    } else {
      string c2 = c;
      string j2 = j;
      assign_biggest(c2, i);
      assign_lowest(j2, i);
      check_solution(c2, j2);
    }
  } else if (c[i] == '?' && j[i] == '?') {
    j[i] = '0';
    c[i] = '0';
    solve(c, j, i+1);

    string c2 = c;
    string j2 = j;

    j2[i] = '1';
    c2[i] = '0';
    assign_lowest(j2, i);
    assign_biggest(c2, i);
    check_solution(c2, j2);

    j[i] = '0';
    c[i] = '1';
    assign_lowest(c, i);
    assign_biggest(j, i);
    check_solution(c, j);
  }
}

int main() {
  int t;

  cin >> t;

  for (int i=0; i<t; i++) {
    string c, j;

    cin >> c >> j;

    best_solution = numeric_limits<long long>::max();

    solve(c, j, 0);

    cout << "Case #" << (i+1) << ": " << best_c << " " << best_j << endl;
  }

  return 0;
}
