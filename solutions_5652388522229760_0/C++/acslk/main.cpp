#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T;
int m, n;

int calc() {
    set<int> d = set<int>();
    int sum = 0;
    while (sum < n * 101) {
        sum += n;
        int temp = sum;
        while (temp > 0) {
            d.insert(temp % 10);
            temp /= 10;
        }
        if (d.size() == 10)
            return sum;
    }
    return -1;
}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> n;

        int c = calc();
        if (c == -1)
            printf("Case #%d: INSOMNIA\n", t + 1);
        else
            printf("Case #%d: %d\n", t + 1, c);
    }
}