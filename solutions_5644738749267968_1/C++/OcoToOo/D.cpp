#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>
#include <fstream>

using namespace std;

typedef long long ll;

#define LARGE

#ifndef LARGE
    ifstream in("D-small-attempt0.in");
    ofstream out("D-small-attempt0.out");
#else
    ifstream in("D-large.in");
    ofstream out("D-large.out");
#endif

int DeceitfulWar(int size, vector<double> naomi, vector<double> ken) {
    sort(naomi.rbegin(), naomi.rend());
    sort(ken.rbegin(), ken.rend());
    int ret = 0;
    for (int i = 0; i < size; i++) {
        if (ken[i] < naomi[i]) {
            ret++;
        } else {
            double n = naomi[size - 1];
            naomi.insert(naomi.begin() + i, n);
            naomi.erase(naomi.begin() + size);
        }
    }
    return ret;
}

int War(int size, vector<double> naomi, vector<double> ken) {
    sort(naomi.begin(), naomi.end());
    sort(ken.begin(), ken.end());
    int ret = 0;
    for (int i = 0; i < size; i++) {
        vector<double>::iterator itr = upper_bound(ken.begin(), ken.end(), naomi[i]);
        if (itr == ken.end()) {
            ret++;
        } else {
            ken.erase(itr);
        }
    }
    return ret;
}

int main() {
    int T; in >> T;
    for (int t = 0; t < T; t++) {
        int size; in >> size;
        vector<double> naomi(size);
        for (int i = 0; i < size; i++) {
            in >> naomi[i];
        }
        vector<double> ken(size);
        for (int i = 0; i < size; i++) {
            in >> ken[i];
        }
        out << "Case #" << t + 1 << ": " << DeceitfulWar(size, naomi, ken) << " " << War(size, naomi, ken) << endl;
    }
    return 0;
}
