#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

#define FILENAME "C-small-attempt4.in"

vector <pair<string, string> > data;

vector <pair<string, string> > abs_not_fake;

bool could (const vector<pair<string, string> >& not_fake, const pair<string, string>& element) {
  bool one = false, two = false;
  for (int i = 0; i < not_fake.size(); ++i) {
    if (element.first == not_fake[i].first) one = true;
    if (element.second == not_fake[i].second) two = true;
  }
  return one && two;
}

bool unique (const vector<pair<string, string> >& input, int pos) {
  bool one = false, two = false;
  for (int i = 0; i < input.size(); ++i) {
    if (i != pos) {
      if (input[i].first == input[pos].first) one = true;
      if (input[i].second == input[pos].second) two = true;
    }
  }
  return one == false || two == false;
}

const int INF = -1000000007;

int ok (int bit_number) {

  vector<bool> mask(data.size());
  for (int i = 0; i < data.size(); ++i) {
    mask[data.size() - i - 1] = bit_number % 2;
    bit_number /= 2;
  }

  vector <pair<string, string> > fake, not_fake = abs_not_fake;
  for (int i = 0; i < data.size(); ++i) {
    if (mask[i]) {
      fake.push_back(data[i]);
    }
    else {
      not_fake.push_back(data[i]);
    }
  }
  vector<bool> added(fake.size(), false);
  for (int j = 0; j < fake.size(); ++j) {
    for (int i = 0; i < fake.size(); ++i) {
      if (added[i] == false && could(not_fake, fake[i])) {
        added[i] = true;
        not_fake.push_back(fake[i]);
        break;
      }
    }
  }
  bool flag = true;
  for (int i = 0; i < fake.size(); ++i) {
    if (added[i] == false)
      flag = false;
  }
  return (flag == true ? fake.size() : INF);
}



int solve(int test_number) {
  int n;
  cin >> n;
  data.clear();
  abs_not_fake.clear();
  vector <pair<string, string> > temp(n);
  for (int i = 0; i < n; ++i) {
    cin >> temp[i].first >> temp[i].second;
  }
  for (int i = 0 ; i < n; ++i) {
    if (unique(temp, i)) {
      abs_not_fake.push_back(temp[i]);
    }
    else {
      data.push_back(temp[i]);
    }
  }
  /*for (int i = 0; i < abs_not_fake.size(); ++i) {
    cout << abs_not_fake[i].first << " " << abs_not_fake[i].second << endl;
  }*/
  int top = (1 << data.size());
  int ans = 0;
  for (int i = 0; i < top; ++i) {
    ans = max(ans, ok(i));
  }
  return ans;
}

int main() {
  freopen(FILENAME, "r", stdin); freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int ans = solve(i);
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}