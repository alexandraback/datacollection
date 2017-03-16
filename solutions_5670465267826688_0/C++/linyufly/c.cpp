#include <algorithm>
#include <iostream>

using namespace std;

typedef long long Int64;

const int maxl = 100000;

// 1 i j k
const int unsigned_mul[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}};

const int sign[4][4] = {
    {1, 1, 1, 1},
    {1, -1, 1, -1},
    {1, -1, -1, 1},
    {1, 1, -1, -1}};

struct Quaternion {
  int sign_, value_;

  Quaternion() {
    sign_ = 1;
    value_ = 0;
  }

  Quaternion(int sign, int value) : sign_(sign), value_(value) {}

  Quaternion(const Quaternion &other) {
    sign_ = other.sign_;
    value_ = other.value_;
  }

  Quaternion multiply(const Quaternion &other) {
    int new_sign = sign_ * other.sign_ * sign[value_][other.value_];
    int new_value = unsigned_mul[value_][other.value_];
    return Quaternion(new_sign, new_value);
  }
};

char str[maxl];
int l;
Int64 x;

int get_value(char ch) {
  switch (ch) {
    case 'i': return 1;
    case 'j': return 2;
    case 'k': return 3;
  }
  return -1;
}

int encode(int sign, int value) {
  return sign < 0 ? value + 4 : value;
}

void decode(int code, int *sign, int *value) {
  if (code < 4) {
    *sign = 1;
    *value = code;
  } else {
    *sign = -1;
    *value = code - 4;
  }
}

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";

    cin >> l >> x >> str;

    Quaternion unit;
    for (int i = 0; i < l; i++) {
      Quaternion curr(1, get_value(str[i]));
      unit = unit.multiply(curr);
    }

    // cout << "unit: " << unit.sign_ << " " << unit.value_ << " ";

    int rep = 1;
    Quaternion tot(unit);
    for (; tot.sign_ != 1 || tot.value_ != 0; rep++) {
      tot = tot.multiply(unit);
    }

    int remain = x % rep;

    // cout << "rep = " << rep << " remain = " << remain << " ";

    tot = Quaternion();
    for (int i = 0; i < remain; i++) {
      tot = tot.multiply(unit);
    }

    if (tot.sign_ != -1 || tot.value_ != 0) {
      cout << "NO" << endl;
      continue;
    }

    int compressed = (min(x / rep, 2LL) * rep + remain) * l;

    // cout << "compressed: " << compressed << " ";

    int ptr = 0;
    tot = Quaternion();
    for (; ptr < compressed; ptr++) {
      Quaternion curr(1, get_value(str[ptr % l]));
      tot = tot.multiply(curr);
      if (tot.sign_ == 1 && tot.value_ == 1) {
        break;
      }
    }
    if (ptr >= compressed) {
      cout << "NO" << endl;
      continue;
    }

    tot = Quaternion();
    for (ptr++; ptr < compressed; ptr++) {
      Quaternion curr(1, get_value(str[ptr % l]));
      tot = tot.multiply(curr);
      if (tot.sign_ == 1 && tot.value_ == 2) {
        break;
      }
    }
    if (ptr >= compressed) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}

