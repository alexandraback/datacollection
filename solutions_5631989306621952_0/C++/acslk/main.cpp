#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <bits/stl_set.h>

using namespace std;
int T;

string calc (int val) {

}

int main () {

    cin >> T;

    for (int t = 0; t < T; t++) {
        string line;
        cin >> line;

        string out = "";
        for (int i = 0; i < line.size(); i++) {
            if (line[i] >= out[0]) {
                out = line[i] + out;
            } else {
                out = out + line[i];
            }
        }

        cout << "Case #" << t+1 << ": " << out << "\n";
    }
}