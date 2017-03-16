#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

bool checkPalindrom (int n) {
  char buf[25];
  string s(ltoa(n, buf, 10));
  return s == string(s.rbegin(), s.rend());
}

typedef vector <int> Number;

Number makeNumber (int x) {
  if (x == 0) return Number(1, 0);

  Number number;
  while (x) {
    number.push_back(x % 10);
    x /= 10;
  }
  return number;
}

Number makeNumber (const string& s) {
  Number number(s.size());
  for (int i = 0; i < s.size(); ++i) {
    number[i] = s[(int)s.size() - 1 - i] - '0';
  }
  return number;
}

bool NumberLess (const Number& lhs, const Number& rhs) {
  if (lhs.size() < rhs.size()) return true;
  if (lhs.size() > rhs.size()) return false;
  for (int i = (int)lhs.size() - 1; i >= 0; --i) {
    if (lhs[i] < rhs[i]) return true;
    if (lhs[i] > rhs[i]) return false;
  }
  return false;
}

Number operator + (Number a, const Number& b) {
	for (int i = 0; i < b.size(); ++i) {
		if(i < a.size()) {
			a[i] += b[i];
		} else {
			a.push_back(b[i]);
		}
	}
	for (int i = 0; i < (int)(a.size() - 1); ++i) {
		if (a[i] > 9) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	if (a.size() && a[a.size() - 1] > 9) {
		a.push_back(a[a.size() - 1] / 10);
		a[a.size() - 2] %= 10;
	}
	return a;
}

Number operator * (Number a, int n) {
	for (int i = 0; i < a.size(); ++i) {
		a[i] *= n;
	}
	for (int i = 0; i < (int)(a.size() - 1); ++i) {
		while (a[i] > 9) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	while (a.size() && a[a.size() - 1] > 9) {
			a.push_back(a[a.size() - 1] / 10);
			a[a.size() - 2] %= 10;
	}
	return a;
}

Number operator * (Number a, const Number& b) {
	vector <int> res;
	for (int i = 0; i < b.size(); ++i) {
		res = res + a * b[i];
		a = a * 10;
	}
	return res;
}

Number getSquare (const Number& number) {
  return number * number;
}

vector <Number> generateWithTwoAtStart (int len) {
  vector <Number> numbers(1, makeNumber(22));

  while (true) {
    Number next = numbers.back();
    if (next.size() & 1) {
      int pos = (next.size() >> 1);
      next[pos] = 1;
      numbers.push_back(next);
      next[pos] = 0;
    }
    next.pop_back();
    next.push_back(0);
    next.push_back(2);
    if (next.size() > len) break;
    numbers.push_back(next);
  }

  return numbers;
}

Number generate1partDpart1 (const Number& part, int D) {
  Number result(part.size() * 2 + 3);
  result[0] = result.back() = 1;
  result[result.size() >> 1] = D;
  for (int i = 0; i < part.size(); ++i) {
    result[1 + i] = result[(int)result.size() - 2 - i] = part[i];
  }
  return result;
}

Number generate1partpart1 (const Number& part) {
  Number result(part.size() * 2 + 2);
  result[0] = result.back() = 1;
  for (int i = 0; i < part.size(); ++i) {
    result[1 + i] = result[(int)result.size() - 2 - i] = part[i];
  }
  return result;
}

vector <Number> generateWithTwoAtMiddle (int len) {
  vector <Number> numbers(1, makeNumber(121));
  numbers.push_back(makeNumber(10201));
  numbers.push_back(makeNumber(11211));

  for (int l = 2; 2 * l + 3 < len; ++l) {
    Number part(l);
    
    for (int i = 0; i < part.size(); ++i) {
      part[i] = 0;
    }
    numbers.push_back(generate1partDpart1(part, 2));

    for (int pos1 = 0; pos1 < part.size(); ++pos1) {
      part[pos1] = 1;
      numbers.push_back(generate1partDpart1(part, 2));
      part[pos1] = 0;
    }
  }

  return numbers;
}

vector <Number> generateBin (int len) {
  vector <Number> numbers(1, makeNumber(11));
  numbers.push_back(makeNumber(101));
  numbers.push_back(makeNumber(111));

  for (int l = 1; 2 * l + 3 < len; ++l) {
    Number part(l);
    
    for (int i = 0; i < part.size(); ++i) {
      part[i] = 0;
    }
    numbers.push_back(generate1partpart1(part));
    numbers.push_back(generate1partDpart1(part, 0));
    numbers.push_back(generate1partDpart1(part, 1));

    for (int pos1 = 0; pos1 < part.size(); ++pos1) {
      part[pos1] = 1;
      numbers.push_back(generate1partpart1(part));
      numbers.push_back(generate1partDpart1(part, 0));
      numbers.push_back(generate1partDpart1(part, 1));
      part[pos1] = 0;
    }

    if (l > 1) {
      for (int pos1 = 0; pos1 < part.size(); ++pos1) {
        for (int pos2 = pos1 + 1; pos2 < part.size(); ++pos2) {
          part[pos1] = part[pos2] = 1;
          numbers.push_back(generate1partpart1(part));
          numbers.push_back(generate1partDpart1(part, 0));
          numbers.push_back(generate1partDpart1(part, 1));
          part[pos1] = part[pos2] = 0;
        }
      }
    }

    if (l > 2) {
      for (int pos1 = 0; pos1 < part.size(); ++pos1) {
        for (int pos2 = pos1 + 1; pos2 < part.size(); ++pos2) {
          for (int pos3 = pos2 + 1; pos3 < part.size(); ++pos3) {
            part[pos1] = part[pos2] = part[pos3] = 1;
            numbers.push_back(generate1partpart1(part));
            numbers.push_back(generate1partDpart1(part, 0));
            numbers.push_back(generate1partDpart1(part, 1));
            part[pos1] = part[pos2] = part[pos3] = 0;
          }
        }
      }
    }
  }

  return numbers;
}


void pushNumbers (vector <Number>& numbers, const vector <Number>& to_add) {
  for (int i = 0; i < to_add.size(); ++i) {
    numbers.push_back(to_add[i]);
  }
}

vector <Number> fair_squares;

void precalc () {
  vector <Number> fair;
  fair.push_back(makeNumber(0));
  fair.push_back(makeNumber(1));
  fair.push_back(makeNumber(2));
  fair.push_back(makeNumber(3));
  
  int len = 56;
  pushNumbers(fair, generateBin(len));
  pushNumbers(fair, generateWithTwoAtMiddle(len));
  pushNumbers(fair, generateWithTwoAtStart(len));

  cerr << fair.size() << endl;

  sort(fair.begin(), fair.end(), NumberLess);

  cerr << fair.back().size() << endl;

  fair_squares.resize(fair.size());
  for (int i = 0; i < fair_squares.size(); ++i) {
    fair_squares[i] = getSquare(fair[i]);
  }

  cerr << fair_squares.back().size() << endl;
}

void solve () {
  string a, b;
  cin >> a >> b;
  Number A = makeNumber(a), B = makeNumber(b);

  int ans = 0;
  for (int i = 0; i < fair_squares.size(); ++i) {
    Number fair_square = fair_squares[i];
    if (NumberLess(B, fair_square)) break;
    if (!NumberLess(fair_square, A)) ++ans;
  }
  cout << ans << endl;
}

int main() {
	freopen("C-large-1.in","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    solve();
	}
	return 0;
}
