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

const int V = 1000000;
int Distance[V + 1], Father[V + 1];

inline int64 Reverse(int64 x) {
    int64 y = 0;
    for (; x > 0; x /= 10)
        y = y * 10 + x % 10;
    return y;
}

void BFS(const int source) {
    memset(Distance, oo, sizeof(Distance));
    Distance[source] = 1;
    queue<int> q;
    for (q.push(source); !q.empty(); q.pop()) {
        int64 x = q.front();
        int64 y = Reverse(x);
        if (Distance[y] == oo) {
            Distance[y] = Distance[x] + 1;
            Father[y] = x;
            q.push(y);
        }
        if (x + 1 <= V && Distance[x + 1] == oo) {
            Distance[x + 1] = Distance[x] + 1;
            Father[x + 1] = x;
            q.push(x + 1);
        }
    }
}

int64 Solve(int64 n) {
    if (n <= V)
        return Distance[n];
    int digitCount = 1;
    int64 ten = 10;
    for (; ten <= n; ten *= 10, ++digitCount);
    int half = digitCount;
    for (ten = 1; half > 0; half -= 2, ten *= 10);
    if (n % ten == 0)
        return 1 + Solve(n - 1);
    int64 newN = n - n % ten + 1;
    int64 steps = n - newN;
    n = newN;
    if (Reverse(n) < n) {
        newN = Reverse(n);
        ++steps;
        n = newN;
    }
    half = digitCount / 2;
    for (ten = 1; half > 0; --half, ten *= 10);
    newN = n - n % ten;
    steps += n - newN;
    n = newN;
    newN = n - 1;
    ++steps;
    n = newN;
    return steps + Solve(n);
}

int main() {
    BFS(1);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int64 n;
        cin >> n;
        cout << "Case #" << t << ": " << Solve(n) << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
