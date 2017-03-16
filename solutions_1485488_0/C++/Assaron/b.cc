#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};


bool ok(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

struct TimeAndSpace {
    double time;
    int i;
    int j;
    TimeAndSpace(double time, int i, int j) 
        : time(time), i(i), j(j) {}
    bool operator<(TimeAndSpace const & other) const {
        if (time != other.time) {
            return time < other.time;
        }

        if (i != other.i) {
            return i < other.i;
        }

        return j < other.j;

    }
};

void update(vector<vector<double> > & d, int i, int j, double new_val, set<TimeAndSpace> & queue) {
    // cerr << "updating " << i << " " << j << " to " << new_val << "\n";
    double old_val = d[i][j];
    if (old_val >= 0) {
        if (old_val <= new_val) {
            return;
        }

        queue.erase(TimeAndSpace(old_val, i, j));
    }
    d[i][j] = new_val;
    queue.insert(TimeAndSpace(new_val, i, j));
}

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int h, n, m;
        cin >> h >> n >> m;
        vector<vector<int> > f(n, vector<int>(m, 0));
        vector<vector<int> > c(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> c[i][j];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> f[i][j];
            }
        }

        vector<vector<double> > d(n, vector<double>(m, -1));

        d[0][0] = 0;

        set<TimeAndSpace> queue;

        queue.insert(TimeAndSpace(0, 0, 0));

        bool tide_started = false;

        while (!queue.empty()) {
            TimeAndSpace cur = *queue.begin();
            queue.erase(queue.begin());

            double cur_t = cur.time;;
            int i = cur.i;
            int j = cur.j;

            tide_started = cur_t > 0;

            double cur_water = h - 10 * cur_t;
            // printf("i: %d, j: %d, water: %lf, cur_t: %lf\n", i, j, cur_water, cur_t);

            for (int z = 0; z < 4; ++z) {
                if (!ok(i + di[z], j + dj[z], n, m)) {
                    continue;
                }

                int i1 = i + di[z];
                int j1 = j + dj[z];

                if (c[i1][j1] < f[i1][j1] + 50) {
                    continue;
                }

                if (c[i1][j1] < f[i][j] + 50) {
                    continue;
                }

                if (c[i][j] < f[i1][j1] + 50) {
                    continue;
                }


                if (!tide_started && c[i1][j1] >= h + 50) {
                    update(d, i1, j1, 0, queue);
                } else {
                    double water_after_waiting = min(cur_water, c[i1][j1] - 50.);
                    double waiting = (cur_water - water_after_waiting) / 10.;

                    // cerr << cur_water << " " << water_after_waiting << "\n";
                    // cerr << f[i][j] << "\n";
                    // printf("i1: %d, j1: %d, waiting = %lf \n", i1, j1, waiting);
                    // cerr << (water_after_waiting >= f[i][j] + 20) << "\n";

                    update(d, i1, j1, cur_t + waiting + ((water_after_waiting >= f[i][j] + 20) ? 1 : 10), queue);
                }
            }
        }

        printf("Case #%d: %.10lf\n", k, d[n - 1][m - 1]);

    }
    return 0;
}
