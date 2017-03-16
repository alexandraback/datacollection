#include <sstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static const int INF = 1<<28, MAX_N = 10000001;

void pushq(int x, int d, vector<int>& dist, queue<int>& q)
{
    if (x < MAX_N && dist[x] > d) {
        q.push(x);
        dist[x] = d;
    }
}

int revnum(int n)
{
    ostringstream out;
    out << n;
    string tmp = out.str();
    reverse(tmp.begin(), tmp.end());

    int ret = 0;
    for (char c : tmp)
        ret = 10 * ret + c - '0';
    return ret;
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    vector<int> dist(MAX_N, -1);

    for (int t = 1;t <= T; t++) {
        int N;
        cin >> N;

        for (int d = 1;d < MAX_N; ++d)
            dist[d] = INF;

        queue<int> q;
        pushq(1, 1, dist, q);

        while (dist[N] >= INF) {
            int x = q.front();
            q.pop();

            pushq(x + 1, dist[x] + 1, dist, q);
            pushq(revnum(x), dist[x] + 1, dist, q);
        }

        cout << "Case #" << t << ": " << dist[N] << endl;
    }

    return 0;
}
