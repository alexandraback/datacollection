// Pijus Navickas <pijus.navickas@gmail.com>

#include <iostream>
#include <string>
#include <unordered_map>

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ullong;

using namespace std;


uint simplify(string input) {
    uint length = 0;
    char last = '\0';

    for (uint i = 0; i < input.length(); ++i) {
        if (last != input[i]) {
            ++length;
            last = input[i];
        }
    }
    if (last == '+') {
        --length;
    }
    return length;
}

void doTestCase(uint number) {
    string line;
    cin >> line;

    // Theory:
    // By each step, your goal is to merge one group into another.
    // It either happens by flipping the whole thing or flipping the first group.
    // In either case each group results in 1 step.
    uint result = simplify(line);

    cout << "Case #" << number << ": " << result << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    uint t;
    cin >> t;

    for (uint i = 0; i != t; ++i) {
        doTestCase(i + 1);
    }

    return 0;
}
