#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int lastNotEq(const string& a, const string& b)
{
    assert(a.size() == b.size());
    for (int i = a.size(); i >= 0; i--)
        if (a[i] != b[i])
            return i;
    return -1;
}

int test()
{
    string pancakes;
    cin >> pancakes;

    string current(pancakes.size(), '+');
    int rotations = 0;
    while (current != pancakes)
    {
        int idx = lastNotEq(current, pancakes);
        transform(current.begin(), current.begin() + idx + 1, current.begin(), [](char x) { return x == '+' ? '-' : '+'; });
        reverse(current.begin(), current.begin() + idx + 1);
        rotations++;
    }

    return rotations;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": " << test() << endl;
    }
}
