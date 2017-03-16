#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T, N, J;

string calc (int val) {
    string ret = "11";
    for (int i = 0; i < (N-4)/2; i++) {
        if (val % 2 == 1)
            ret += "11";
        else
            ret += "00";
        val /= 2;
    }
    ret += "11";
    return ret;
}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {

        cin >> N >> J;

        printf("Case #%d:\n", t + 1);

        for (int i = 0; i < J; i++) {
            cout << calc(i) << " 3 4 5 6 7 8 9 10 11\n";
        }


    }
}