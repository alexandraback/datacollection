#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> Decompose(const int num) {
  vector<int> dec;

  int sv = num;
  while (sv > 0) {
    dec.emplace_back(sv % 10);
    sv /= 10;
  }

  vector<int> svd = dec;
  for (int idx = 0; idx < dec.size(); ++idx) {
    dec[idx] = svd[dec.size() - idx - 1];
  }

  return dec;
}

int Build(const vector<int>& dec, const int start) {
  int val = 0;
  for (int idx = start; idx < dec.size(); ++idx) {
    val *= 10;
    val += dec[idx];
  }
  for (int idx = 0; idx < start; ++idx) {
    val *= 10;
    val += dec[idx];
  }
  return val;
}

namespace std {

template<>
struct hash<pair<int, int>> {
  size_t operator()(const pair<int, int>& p) const {
    return hash<int>()(p.first) ^ hash<int>()(p.second);
  }
};
}

int main() {
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; ++c) {
    cout << "Case #" << (c + 1) << ": ";

    unordered_set<pair<int, int>> found;

    int A, B;
    cin >> A >> B;

    const vector<int> dec_A = Decompose(A);
    const vector<int> dec_B = Decompose(B);
    for (int num = A; num <= B; ++num) {
      vector<int> dec_num = Decompose(num);

      for (int idx = 1; idx < dec_num.size(); ++idx) {
        const int build = Build(dec_num, idx);
        if (build <= num ||
            build < A ||
            build > B) {
          continue;
        }

        found.insert(make_pair(num, build));
      }
    }

    cout << found.size() << endl;
  }

}
