#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <complex>
#include <limits>
#include <list>
#include <stack>
#include <numeric>
#include <queue>
#include <algorithm>
#include <functional>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;


vector<string> getLineFields(istream& stream) {
    string line;
    getline(stream, line);
    stringstream str;
    str << line;
    vector<string> fields;
    string temp;
    while(str>>temp)
    {
        fields.push_back(temp);
    }
    return fields;
}


int main() {
    int T;
    cin >> T;
    for (int k = 0; k < T; ++k) {
        long long r, t;
        cin >> r >> t;
        long long le = 1;
        long long ri = t;
        while (le < ri) {
            long long m = le + (ri - le) / 2 + 1;
            if ((2 * r + 2 * m - 1) <= 1.0L * t / m) {
                le = m;
            }
            else {
                ri = m - 1;
            }
        }
        cout << "Case #" << k + 1 << ": " << le << endl;

    }
}
