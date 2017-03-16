# include <iostream>
# include <cstring>
# include <queue>
using namespace std;

const int maxn = 10000;
const int maxe = 20;
int R, N, E;
int v[maxn + 1];
int need[maxn + 1];
int used[maxn + 1];

struct compare {
    bool operator()(int a, int b) {
        return v[a] < v[b];
    }
};

typedef long long int lli;

bool marked[maxn + 1];

int get_left(int node) {
    while(node >= 0) {
        if (marked[node]) {
            break;
        }

        node--;
    }

    return node;
}

int get_right(int node) {
    while(node < N) {
        if (marked[node]) {
            break;
        }

        node++;
    }

    return (node == N) ? -1 : node;
}

int main() {
    int t, tt, i;
    lli ans = 0LL;

    cin >> t;
    for (tt = 0; tt < t; tt++) {
        priority_queue < int, vector < int >, compare > pq;
        memset(marked, false, sizeof marked);

        cin >> E >> R >> N;
        for (i = 0; i < N; i++) {
            cin >> v[i];

            need[i] = E;
            used[i] = 0;
            pq.push(i);
        }

        ans = 0LL;
        while(!pq.empty()) {
            int node = pq.top();
            pq.pop();

            int li = get_left(node);
            int ri = get_right(node);

            if (li == -1) {
                need[node] = E;
            }
            else {
                need[node] = min(E, (need[li] - used[li]) + (node - li) * R);
            }

            if (ri == -1) {
                used[node] = need[node];
            }
            else {
                int tmp = need[node] - need[ri] + (ri - node) * R;
                tmp = min(tmp, E);
                tmp = max(tmp, 0);

                used[node] = tmp;
            }

            marked[node] = true;
            ans += (lli) used[node] * (lli) v[node];
        }

        cout << "Case #" << (tt + 1) << ": " << ans << endl;
    }
    return 0;
}
