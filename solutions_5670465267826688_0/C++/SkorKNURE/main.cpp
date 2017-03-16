#include <iostream>
#include <vector>

using namespace std;

//#define NAME "my"
#define NAME "C-small-attempt1"
//#define NAME "C-large"

// [1, i, j, k] => [1, 2, 3, 4]
const int table[4][4] = {
  {1, 2, 3, 4},
  {2, -1, 4, -3},
  {3, -4, -1, 2},
  {4, 3, -2, -1}
};

int n;
int64_t X;
string s;
vector<int> v;
vector<int> row;

int mul(int a, int b) {
  if (a < -4 || a > 4 || a == 0) throw 1;
  if (b < -4 || b > 4 || b == 0) throw 1;
  int sign = 1;
  if (a < 0) {
    sign = -sign;
    a = -a;
  }
  if (b < 0) {
    sign = -sign;
    b = -b;
  }
  return sign * table[a - 1][b - 1];
}

int pow(int val, int64_t p) {
  p %= 4;
  int ret = 1;
  for (int i = 0; i < p; i++) {
    ret = mul(ret, val);
  }
  return ret;
}

bool canSplit() {
  int groupVal = 1;
  for (int val : v) {
    groupVal = mul(groupVal, val);
  }
  if (pow(groupVal, X) != -1) return false;
  int segments = min(10LL, X);
  row.clear();
  row.reserve(segments * n);
  for (int i = 0; i < segments; i++) {
    row.insert(row.end(), v.begin(), v.end());
  }
  int val = 1;
  int minLeft = -1;
  for (size_t i = 0; i < row.size(); i++) {
    val = mul(val, row[i]);
    if (val == 2) {
      minLeft = i + 1;
      break;
    }
  }
  if (minLeft == -1) return false;
  val = 1;
  int minRight = -1;
  for (int i = row.size() - 1; i >= 0; i--) {
    val = mul(row[i], val);
    if (val == 4) {
      minRight = row.size() - i;
      break;
    }
  }
  if (minRight == -1) return false;
  int64_t total = n * X;
  return minLeft + minRight < total;
}

void solveCase(int tc) {
  cin >> n >> X >> s;
  v.resize(n);
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == 'i') v[i] = 2;
    else if (s[i] == 'j') v[i] = 3;
    else if (s[i] == 'k') v[i] = 4;
    else throw 1;
  }
  string answer = canSplit() ? "YES" : "NO";
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
}

void initialize() {
}

int main() {
  freopen(NAME".in", "rt", stdin);
  freopen(NAME".out", "wt", stdout);
  int T;
  cin >> T;
  initialize();
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  return 0;
}
