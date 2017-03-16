#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <math.h>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>


using namespace std;

typedef struct _pos {
    double time;
    double pos;
} pos;

double solve(pos* car, int N, double a, double D) {
    double start_time = 0;
    double pos;

    for (int i = 0; i < N; ++i) {
        double time = car[i].time - start_time;
        if (car[i].pos >= D) {
            time = (car[i].pos - car[i-1].pos) / (car[i].time - car[i-1].time);
            time = (D-car[i-1].pos) / time;
            time += car[i-1].time;
            time -= start_time;
            car[i].pos = D;
            car[i].time = time;
        }
        pos = 0.5 * a * time * time;
        if (pos <= car[i].pos) {
            if (car[i].pos >= D) break;
            continue;
        }
        time = sqrt(car[i].pos / (0.5 * a));
        start_time = car[i].time - time;
        if (car[i].pos >= D) break;
    }
    
    return start_time + sqrt(D / (0.5 * a));
}


int main() {
    int numcase, N, A;
    double D;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);

    cout.unsetf(ios::floatfield);
    cout.precision(12);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> D >> N >> A;
        pos car[N];
        double acc[A];
        for  (int j = 0; j < N; ++j) {
            cin >> car[j].time;
            cin >> car[j].pos;
        }
        for  (int j = 0; j < A; ++j) {
            cin >> acc[j];
        }
        cout << "Case #" << i + 1 << ":" << endl;
        for  (int j = 0; j < A; ++j) {
            cout << solve(car, N, acc[j], D) << endl;
        }
    }

    return 0;
}
