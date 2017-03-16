#include <iostream>
#include <string>

using namespace std;

enum valueT { ONE, I, J, K };
struct quaternion {
  quaternion(valueT val = ONE, bool neg = false) : val(val), neg(neg) {}
  valueT val;
  bool neg;

  quaternion operator*(const quaternion& b) {
    quaternion a = *this;
    quaternion ans;
    ans.neg = a.neg ^ b.neg;
    if (a.val == ONE) {
      ans.val = b.val;
    } else if (b.val == ONE) {
      ans.val = a.val;
    } else if (a.val == b.val) {
      ans.val = ONE;
      ans.neg = !ans.neg;
    } else if (a.val == I && b.val == J) {
      ans.val = K;
    } else if (a.val == J && b.val == K) {
      ans.val = I;
    } else if (a.val == K && b.val == I) {
      ans.val = J;
    } else if (a.val == J && b.val == I) {
      ans.val = K;
      ans.neg = !ans.neg;
    } else if (a.val == K && b.val == J) {
      ans.val = I;
      ans.neg = !ans.neg;
    } else if (a.val == I && b.val == K) {
      ans.val = J;
      ans.neg = !ans.neg;
    }
    return ans;
  }

};

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int length; cin >> length;
    long long reps; cin >> reps;
    string ss; cin >> ss;

    if (reps > 12) reps = (reps % 4) + 12;

    string s;
    for (int i = 0; i < reps; ++i) {
      s = s.append(ss);
    }

    int found = 0;
    // i = i
    // ij = k
    // ijk = -1
    quaternion prod;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == 'i') {
        prod = prod * quaternion(I);
      }
      if (s[i] == 'j') {
        prod = prod * quaternion(J);
      }
      if (s[i] == 'k') {
        prod = prod * quaternion(K);
      }
      if (prod.val == I && !prod.neg && found == 0) found++;
      if (prod.val == K && !prod.neg && found == 1) found++;
    }
    cout << "Case #" << test << ": " <<
      ((found == 2 && prod.val == ONE && prod.neg) ? "YES" : "NO") << endl;
  }
  return 0;
}