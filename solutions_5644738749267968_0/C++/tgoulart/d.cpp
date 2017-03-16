#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int regular(deque <double> d1, deque <double> d2) {
    int points = 0;
    while (!d1.empty()) {
        if (d2.back() > d1.back()) {
            d2.pop_back();
        } else {
            d2.pop_front();
            ++points;
        }
        d1.pop_back();
    }
    return points;
}

int cheating2(deque <double> d1, deque <double> d2) {
    int N = d1.size();
    int points = 0;
    vector <bool> used(N, false);
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            if (!used[j] && d1[i] > d2[j]) {
                ++points;
                used[j] = true;
                break;
            }
        }
    }
    return points;
}

int cheating(deque <double> d1, deque <double> d2) {
//    return cheating2(d1, d2);
    int points = 0;
    while (!d1.empty()) {
        if (d1.front() < d2.front()) {
            d1.pop_front();
            d2.pop_back();
        } else {
            d1.pop_front();
            d2.pop_front();
            ++points;
        }
    }
    return points;
}

int main() {
	int T;
    scanf("%d", &T);

    for (int t=1; t <= T; ++t) {
        int N;
        cin >> N;

        deque <double> d1;
        deque <double> d2;
        vector <double> v(N);

        for (int i=0; i < N; ++i) {
            cin >> v[i];
            d1.push_back(v[i]);
        }
        for (int i=0; i < N; ++i) {
            cin >> v[i];
            d2.push_back(v[i]);
        }

        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());

        printf("Case #%d: %d %d\n", t, cheating(d1, d2), regular(d1, d2));
    }
	
	return 0;
}
