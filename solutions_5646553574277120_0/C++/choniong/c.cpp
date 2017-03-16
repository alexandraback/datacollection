#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

bool isok(vector<int> den, int maxp) {
    bool v[maxp+1];
    for (int i = 0; i <= maxp; ++i) {
        v[i] = false;
    }
    v[0] = true;
    for (int i = 0; i < den.size(); ++i) {
        for (int j = maxp; j >= 0; --j) {
            if (v[j] && j + den[i] <= maxp) {
                v[j + den[i]] = true;
            }   
        }
    }

    for (int i = 0; i <= maxp; ++i) {
        if (v[i] == false) {
            return false;
        }
    }
    return true;
}

bool isokbyadding(vector<int> den, int maxp, int adding) {
    if (adding == 0) {
        return isok(den, maxp);
    } else {
        for (int i = 1; i <= maxp; ++i) {
            bool exis = false;
            for (int j = 0; j < den.size(); ++j) {
                if (i == den[j]) {
                    exis = true;
                }
            }
            if (exis) {
                continue;
            }

            den.push_back(i);
            if (isokbyadding(den, maxp, adding - 1)) {
                return true;
            }
            den.pop_back();
        }
    }
    return false;
}

int main () {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int c, d, v;
        vector<int> den;

        cin >> c >> d >> v;
        for (int i = 0; i < d; ++i) {
            int tmp;
            cin >> tmp;
            den.push_back(tmp);
        }

        int adding = 0;

        while(!isokbyadding(den, v, adding)) {
            ++adding;
        }

        printf("Case #%d: %d\n", tt, adding);

    }

    return 0;
}
