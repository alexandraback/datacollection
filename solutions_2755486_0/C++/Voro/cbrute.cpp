#include <cstdio>
#include <vector>

using namespace std;

struct attack {
    int x, y, power;

    attack(int _x, int _y, int _power) {
        x = _x;
        y = _y;
        power = _power;
    }
};

using namespace std;

const int kMaxT = 700005, MAXD = 1005;

vector <attack> event[kMaxT];

int height[2 * MAXD];

void solve() {
    for (int i = 0; i < 2 * MAXD; ++i)
        height[i] = 0;
        
	for (int i = 0; i < kMaxT; ++i)
		event[i].clear();

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        int day, number, xc, yc, power, delta_day, delta_distance, delta_power;
        scanf("%d%d%d%d%d%d%d%d", &day, &number, &xc, &yc, &power, &delta_day, &delta_distance, &delta_power);

        for (int cnumber = 1; cnumber <= number; ++cnumber) {
            event[day].push_back(attack(xc + MAXD, yc + MAXD - 1, power));
            day += delta_day;
            xc += delta_distance;
            yc += delta_distance;
            power += delta_power;
        }
    }

    int ans = 0;

    for (int day = 0; day < kMaxT; ++day) {
        //query
        for (size_t i = 0; i < event[day].size(); ++i) {
			bool ok = 0;
            for (int j = event[day][i].x; j <= event[day][i].y; ++j)
                if (height[j] < event[day][i].power)
                    ok = 1;
			ans += (int)ok;
		}

        //update
        for (size_t i = 0; i < event[day].size(); ++i)
            for (int j = event[day][i].x; j <= event[day][i].y; ++j)
                if (height[j] < event[day][i].power)
                    height[j] = event[day][i].power;
    }

    printf("%d", ans);
}

int main() {
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);

        solve();

        printf("\n");
    }

    return 0;
}
