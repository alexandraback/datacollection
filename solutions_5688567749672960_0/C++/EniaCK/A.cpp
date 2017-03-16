#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define abs(x) (((x)>0)?(x):(-x))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))
using namespace std;
int T;
int n, m[1000100];
queue<int> Q;

int reverse(int d)
{
    int res = 0;
    while (d) {
        res *= 10;
        res += d % 10;
        d   /= 10;
    }
    return res;
}

void bfs()
{
    m[1] = 1;
    Q.push(1);
    int next, now;
    while (!Q.empty()) {
        now = Q.front();
        next = now + 1;
        if (next <= 1000000){
            if (!m[next] || m[next] > m[now] + 1) {
                m[next] = m[now] + 1;
                Q.push(next);
            }
        }

        next = reverse(now);
        if (next <= 1000000){
            if (!m[next] || m[next] > m[now] + 1) {
                m[next] = m[now] + 1;
                Q.push(next);
            }
        }
        Q.pop();
    }
}

int main()
{
    bfs();
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        cout << "Case #" << Case << ": ";
        cin >> n;
        cout << m[n] << endl;
    }
    return 0;
}
