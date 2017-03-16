#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

void remove(int arr[], string word, int times) {
    for (char c: word)
        arr[c-'A'] -= times;
}

string test() {
    string s;
    cin >> s;
    int counts[26] = {};
    for (char c : s)
        counts[c-'A']++;

    int results[10] = {};
    results[0] = counts['Z'-'A'];
    remove(counts, "ZERO", results[0]);
    results[6] = counts['X'-'A'];
    remove(counts, "SIX", results[6]);
    results[2] = counts['W'-'A'];
    remove(counts, "TWO", results[2]);
    results[4] = counts['U'-'A'];
    remove(counts, "FOUR", results[4]);
    results[8] = counts['G'-'A'];
    remove(counts, "EIGHT", results[8]);
    results[3] = counts['R'-'A'];
    remove(counts, "THREE", results[3]);
    results[7] = counts['S'-'A'];
    remove(counts, "SEVEN", results[7]);
    results[5] = counts['V'-'A'];
    remove(counts, "FIVE", results[5]);
    results[9] = counts['I'-'A'];
    remove(counts, "NINE", results[9]);
    results[1] = counts['O'-'A'];
    remove(counts, "ONE", results[1]);
    string result;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < results[i]; j++)
            result += char(i + '0');
    return result;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": " << test() << endl;
    }
}
