#include <bits/stdc++.h>

#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;

double eps = 1e-6;

bool equal(double a, double b) {
    return abs(a-b) < eps;
}

struct human {
    ll D;
    ll H;
    ll M;
};

struct state{
    ll D;
    ll M;
    bool operator<(const state& rhs) const {
        return M < rhs.M;
    }
};

int solve(int N, const vector<human>& V) {
    int sum = 0;
    vector<state> s;
    for (int i = 0; i < N; i++) {
        sum += V[i].H;
        for (int j = 0; j < V[i].H; j++) {
            s.push_back(state{V[i].D, V[i].M+j});
        }
    }
    if (sum == 1) return 0;
    sort(s.begin(), s.end());
    if (s[0].M == s[1].M) return 0;
    ll diff = 360+s[1].D-s[0].D;
    ll tmp = s[1].D+s[0].M*diff/(s[1].M-s[0].M);
    //cout << "tmp is " << tmp << endl;
    if (s[1].D+s[0].M*diff/(s[1].M-s[0].M) > 360) return 0;
    if (tmp == 360) {
        if (s[1].D+s[0].M*diff%(s[1].M-s[0].M)) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<human> V(N);
        for (int i = 0; i < N; i++) {
            int d, h, m;
            cin >> d >> h >> m;
            V[i] = (human{d, h, m});
        }
        printf("Case #%d: %d\n", t, solve(N, V));
    }
    return 0;
}
