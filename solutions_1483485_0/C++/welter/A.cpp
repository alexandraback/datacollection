#include <iostream>
#include <cstdio>

using namespace std;

char dctable[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
                    'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main() {

    string input;
    int tests;

    scanf("%d\n", &tests);

    for (int i = 0; i < tests; ++i) {

        getline(cin, input);

        for (int j = 0; j < input.size(); ++j)
            if (input[j] >= 'a' && input[j] <= 'z')
                input[j] = dctable[input[j]-'a'];

        cout << "Case #" << i + 1 << ": " << input << '\n';
    }

    return 0;
}
