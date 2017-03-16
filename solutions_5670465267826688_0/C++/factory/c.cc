#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

struct Element {
  enum Value : int {
    ONE = 1,
    I = 2,
    J = 3,
    K = 4
  };
  int value;

  static Element From(char c) {
    Element e;
    switch (c) {
      case 'i':
        e.value = I;
        break;
      case 'j':
        e.value = J;
        break;
      case 'k':
        e.value = K;
        break;
    }
    return e;
  }

  Element& operator*=(const Element& rhs) {
    static const int kMultTable[5][5] = {
      { 0, 0, 0, 0, 0 },
      { 0, ONE, I, J, K },
      { 0, I, -ONE, K, -J },
      { 0, J, -K, -ONE, I },
      { 0, K, J, -I, -ONE }
    };
    int mult_result = kMultTable[std::abs(value)][std::abs(rhs.value)];
    mult_result *= ((value * rhs.value < 0) ? -1 : 1);
    value = mult_result;
    return *this;
  }

  Element FindSecondOperand(const Element& first_operand) {
    static const int kOperandTable[5][5] = {
      { 0, 0, 0, 0, 0 },
      { 0, ONE, I, J, K },
      { 0, -I, ONE, -K, J },
      { 0, -J, K, ONE, -I },
      { 0, -K, -J, I, ONE }
    };
    Element e;
    e.value = kOperandTable[std::abs(first_operand.value)][std::abs(value)];
    e.value *= ((first_operand.value * value < 0) ? -1 : 1);
    return e;
  }
};

Element operator*(Element lhs, const Element& rhs) {
  return lhs *= rhs;
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;

  const Element ijk =
      Element::From('i') * Element::From('j') * Element::From('k');

  string data;
  data.reserve(10000);
  string input;
  input.reserve(10000);
  for (int tt = 1; tt <= T; ++tt) {
    data.clear();
    input.clear();

    int L = 0;
    int X = 0;
    cin >> L >> X;

    cin >> input;

    for (int i = 0; i < X; ++i) {
      data += input;
    }

    static std::array<Element, 10100> accum;
    accum[0] = Element::From(data[0]);
    for (int i = 1; i < data.size(); ++i) {
      accum[i] = accum[i - 1] * Element::From(data[i]);
    }

    bool possible = false;
    if (data.size() >= 3 &&
        ijk.value == accum[data.size() - 1].value) {
      const int last = data.size() - 1;
      for (int i = 1; i < last; ++i) {
        if (accum[last].FindSecondOperand(accum[i]).value == Element::K) {
          for (int j = 0; j < i; ++j) {
            if (accum[i].FindSecondOperand(accum[j]).value == Element::J &&
                accum[j].value == Element::I) {
              possible = true;
              break;
            }
          }
        }
      }
    }

    cout << "Case #" << tt << ": " << (possible ? "YES" : "NO") << "\n";
  }
  
  return 0;
}

