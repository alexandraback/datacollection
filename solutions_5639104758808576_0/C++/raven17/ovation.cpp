//
//  ovation.cpp
//  
//
//  Created by John Nevard on 4/11/15.
//
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> VI;

int n_friends(const VI& d) {
    int hi = d.size();
    int sum = 0;
    int nf = 0;
    for (int i = 0; i < hi; ++i) {
        if (i <= sum)
            sum += d[i];
        else {
            nf += i - sum;
            sum = i + d[i];
        }
    }
    return nf;
}

int main() {
    int n_cases;
    cin >> n_cases;
    for (int c = 1; c <= n_cases; ++c) {
        int s_max;
        cin >> s_max;
        string sd;
        cin >> sd;
        VI d(s_max + 1);
        for (int i = 0; i < sd.size(); ++i)
            d[i] = sd[i] - '0';
        int y = n_friends(d);
        cout << "Case #" << c << ": " << y << '\n';
    }
    return 0;
}