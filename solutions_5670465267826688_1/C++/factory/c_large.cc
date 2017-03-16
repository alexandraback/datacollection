#include <array>
#include <cstdint>
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

  const Element el_i = Element::From('i');
  const Element el_ij = el_i * Element::From('j');
  const Element el_ijk = el_ij * Element::From('k');

  string input;
  input.reserve(10000);
  for (int tt = 1; tt <= T; ++tt) {
    input.clear();

    int L = 0;
    int64_t X = 0;
    cin >> L >> X;

    cin >> input;

    static std::array<Element, 140100> accum;
    static std::array<int, 140100> last_i;
    static std::array<int, 140100> last_ij;
    last_i.fill(-1);
    last_ij.fill(-1);

    int last_i_pos = -1;
    int last_ij_pos = -1;

    accum[0] = Element::From(input[0]);
    if (accum[0].value == el_i.value) {
      last_i_pos = 0;
    } else if (accum[0].value == el_ij.value) {
      last_ij_pos = 0;
    }
    for (int i = 1; i < input.size(); ++i) {
      accum[i] = accum[i - 1] * Element::From(input[i]);
      last_i[i] = last_i_pos;
      last_ij[i] = last_ij_pos;
      if (accum[i].value == el_i.value) {
        last_i_pos = i;
      } else if (accum[i].value == el_ij.value) {
        last_ij_pos = i;
      }
    }

    int64_t ident_pattern = 4;
    Element square = accum[input.size() - 1] * accum[input.size() - 1];
    if (square.value == 1) {
      ident_pattern = 2;
    }
    const int64_t min_repeat = ident_pattern * 3 - 1;
    const int64_t repeat_count =
        (X < min_repeat ? X : ((X - min_repeat) % ident_pattern + min_repeat));

    const int64_t total_length = input.size() * repeat_count;
    for (int i = input.size(); i < total_length; ++i) {
      accum[i] = accum[i - 1] * Element::From(input[i % input.size()]);
      last_i[i] = last_i_pos;
      last_ij[i] = last_ij_pos;
      if (accum[i].value == el_i.value) {
        last_i_pos = i;
      } else if (accum[i].value == el_ij.value) {
        last_ij_pos = i;
      }
    }

    bool possible = false;
    if (total_length >= 3 &&
        el_ijk.value == accum[total_length - 1].value) {
      const int last = total_length - 1;

      const int prev_ij = last_ij[last];
      if (prev_ij != -1) {
        const int prev_i = last_i[prev_ij];
        if (prev_i != -1) {
          possible = true;
        }
      }
    }

    cout << "Case #" << tt << ": " << (possible ? "YES" : "NO") << "\n";
  }
  
  return 0;
}

