#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "B"

int main() {
    freopen(PROBLEM ".in", "rt", stdin);
    freopen(PROBLEM ".out", "wt", stdout);

    int T;
    scanf("%d\n", &T);

    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        int x, y;
        cin >> x >> y;
		
        if (x > 0) {
        	for (int i = 0; i < x; i++) {
        		cout << "WE";
        	}
        }
        else {
        	for (int i = 0; i < -x; i++) {
        		cout << "EW";
        	}
        }

        if (y > 0) {
        	for (int i = 0; i < y; i++) {
        		cout << "SN";
        	}
        }
        else {
        	for (int i = 0; i < -y; i++) {
        		cout << "NS";
        	}
        }

        printf("\n");
    }

    return 0;
}
