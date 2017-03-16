#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

const int oo = 0x3f3f3f3f;

const int V = 1000001;
int Distance[V];

inline int Reverse(int x) {
    int y = 0;
    for (; x > 0; x /= 10)
        y = y * 10 + x % 10;
    return y;
}

void BFS(const int source) {
    memset(Distance, oo, sizeof(Distance));
    Distance[source] = 1;
    queue<int> q;
    for (q.push(source); !q.empty(); q.pop()) {
        int x = q.front();
        if (Distance[x + 1] == oo) {
            Distance[x + 1] = Distance[x] + 1;
            q.push(x + 1);
        }
        int y = Reverse(x);
        if (Distance[y] == oo) {
            Distance[y] = Distance[x] + 1;
            q.push(y);
        }
    }
}

int main() {
    BFS(1);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << Distance[n] << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
