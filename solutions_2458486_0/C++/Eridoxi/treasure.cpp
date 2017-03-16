#include <cstdlib>
#include <climits>
#include <sstream>
#include <cstring>
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

typedef struct chest_ {
    bool sure;
    int type;
    int num_keys;
    int* keys;
} chest;

int N;
int rem_keys;
int keys[200];
chest chs[200];
bool done[200];
int ordering[200];


void add_keys(chest& c, int add) {
    rem_keys += add * c.num_keys;
    for (int i = 0; i < N; ++i) {
        keys[i] += add * c.keys[i];
    }
}

void open(chest& c) {
    --rem_keys;
    --keys[c.type];
    add_keys(c, 1);
}

void close(chest& c) {
    ++rem_keys;
    ++keys[c.type];
    add_keys(c, -1);
}


bool solve(int k) {
    if (k >= N) return true;
    if (rem_keys == 0) return false;
    bool tried[200];
    memset(tried, 0, 200*sizeof(bool));

    for (int i = 0; i < N; ++i) {
        chest& c = chs[i];
        if (done[i] || keys[c.type] == 0) continue;
        done[i] = true;
        open(c);
        if (solve(k+1)) {
            ordering[k] = i;
            return true;
        }
        close(c);
        done[i] = false;
        if (c.sure || keys[c.type] >= 2) return false;
    }
    return false;
}


int main() {
    int numcase = 0, K, tmp;
    for (int i = 0; i < 200; ++i) {
        chs[i].keys = new int[200];
    }

    freopen("D-small-attempt2.in", "r", stdin);
    freopen("D-small.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> K >> N;
        memset(keys, 0, 200*sizeof(int));
        memset(done, 0, 200*sizeof(bool));

        rem_keys = K;
        for  (int j = 0; j < K; ++j) {
            cin >> tmp;
            ++keys[tmp-1];
        }

        for  (int j = 0; j < N; ++j) {
            chest& c = chs[j];
            cin >> tmp;
            c.type = tmp - 1;
            cin >> c.num_keys;
            memset(c.keys, 0, 200*sizeof(int));
            for (int k = 0; k < c.num_keys; ++k) {
                cin >> tmp;
                ++c.keys[tmp-1];
            }
            c.sure = (c.keys[c.type] != 0);
        }

        cout << "Case #" << i + 1 << ":";
        if (!solve(0)) {
            cout << " IMPOSSIBLE" << endl;
        } else {
            for  (int j = 0; j < N; ++j) {
                cout << " " << ordering[j]+1;
            }
            cout << endl;
        }
    }

    return 0;
}
