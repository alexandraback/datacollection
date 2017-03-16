#include <fstream>
#include <queue>
#include <functional>

using namespace std;

int main() {
        ifstream fin("C-small-attempt0.in");
        ofstream fout("C-small-attempt0.out");
        int T;
        fin >> T;
        for (int casenum = 1; casenum <= T; ++casenum) {
                const int MAXN = 10;
                int N, d[MAXN], n[MAXN], w[MAXN], e[MAXN], s[MAXN], delta_d[MAXN], delta_p[MAXN], delta_s[MAXN];
                fin >> N;
                for (int i = 0; i < N; ++i)
                        fin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> delta_d[i] >> delta_p[i] >> delta_s[i];
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < n[i]; ++j)
                                q.push(make_pair(d[i] + j * delta_d[i], i));
                int ans = 0;
                const int ORIGIN = 300;
                vector<int> wall(2 * ORIGIN, 0);
                vector<int> new_wall = wall;
                while (!q.empty()) {
                        int day = q.top().first, t = q.top().second;
                        q.pop();
                        bool commit = true;
                        if (!q.empty() && q.top().first == day) commit = false;
                        int idx = (day - d[t]) / delta_d[t];
                        int west = w[t] + idx * delta_p[t] + ORIGIN;
                        int east = e[t] + idx * delta_p[t] + ORIGIN;
                        int strength = s[t] + idx * delta_s[t];
                        bool success = false;
                        for (int i = west; i < east; ++i)
                                if (wall[i] < strength) {
                                        success = true;
                                        if (new_wall[i] < strength)
                                                new_wall[i] = strength;
                                }
                        if (success) ++ans;
                        if (commit) wall = new_wall;
                }
                fout << "Case #" << casenum << ": " << ans << '\n';
        }
        fin.close();
        fout.close();
        return 0;
}