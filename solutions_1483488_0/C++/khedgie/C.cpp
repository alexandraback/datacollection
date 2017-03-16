#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

typedef std::vector<int> Number;

void fill_number(Number& n, int a) {
    while (a > 0) {
        n.push_back(a % 10);
        a /= 10;
    }
    std::reverse(n.begin(), n.end());
}

void next_number(Number& n) {
    for (std::size_t pos = n.size() - 1; true; --pos) {
        if (++(n[pos]) != 10) {
            return;
        } else {
            n[pos] = 0;
        }
    }
}

void print_number(const Number& n) {
    std::copy(n.begin(), n.end(), std::ostream_iterator<int>(std::cout));
}

int read_number(const Number& n) {
    int a = 0;
    for (Number::const_iterator i = n.begin(); i != n.end(); ++i) {
        a = 10*a + *i;
    }
    return a;
}

int main() {
    int T;
    std::cin >> T;
    for (int x = 1; x <= T; ++x) {
        int A, B;
        std::cin >> A >> B;
        Number b, n;
        fill_number(b, B);
        fill_number(n, A);
        int digits = n.size();
        int count = 0;
        std::set<std::pair<int, int> > s;
        for (int numleft = B - A; numleft > 0; --numleft, next_number(n)) {
            Number m = n;
            for (int i = 1; i < digits; ++i) {
                std::rotate(m.begin(), m.end() - 1, m.end());
                if (std::lexicographical_compare(n.begin(), n.end(),
                                                 m.begin(), m.end())
                    && !std::lexicographical_compare(b.begin(), b.end(),
                                                     m.begin(), m.end())) {
                    // check
                    int a, b;
                    a = read_number(n);
                    b = read_number(m);
                    std::pair<int, int> pr(a, b);
                    if (s.find(pr) == s.end()) {
                        ++count;
                        s.insert(pr);
                    }
                }
            }
        }
        std::cout << "Case #" << x << ": " << count << '\n';
    }
    return 0;
}
