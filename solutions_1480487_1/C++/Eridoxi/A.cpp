#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

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


void solve(int N, double sum, double * score, double * unsorted) {
    sort(score, score+N);
    double f[N];
    double reste = 1;
    for (int i = 0; i < N-1; ++i) {
        double tmp = (-score[i] + score[i+1]) / sum;
        if ((i+1)*tmp > reste) {
            f[i] = reste / (double)(i+1);
            reste = 0;
        } else {
            reste -= (i+1)*tmp;
            f[i] = tmp;
        }
    }
    f[N-1] = reste / (double)N;
    for (int i = N-2; i >= 0; --i) {
        f[i] += f[i+1];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (score[j] == unsorted[i]) {
                cout << f[j] * 100 <<" ";
                break;
            }
        }
    }
}


int main() {
    int numcase, N;
    double tmp, sum, min1, min2;

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    cout.unsetf(ios::floatfield);
    cout.precision(12);
    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N;
        double score[N];
        double sorted[N];
        cout << "Case #" << i + 1 << ": ";
        sum = 0;
        for (int j = 0; j < N; ++j) {
            cin >> tmp;
            sum += tmp;
            score[j] = tmp;
            sorted[j] = tmp;
        }
        solve(N, sum, sorted, score);
        cout << endl;
    }

    return 0;
}
