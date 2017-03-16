#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstdint>
#include <algorithm>

using namespace std;

#define CENTER 200

vector<int> wall, new_wall;
int c;
int min_rel, max_rel;

struct tribe_t {
    int d, n, w, e, s, del_d, del_pi, del_s;
    void read() {
        cin >> d >> n >> w >> e >> s >> del_d >> del_pi >> del_s;
	}
    void do_atk() {
        --n;
        int del_c = 0;
        for (int i = w; i <= e; ++i) {
            if (wall[CENTER + i] < s) {
				del_c = 1;
                new_wall[CENTER + i] = max(new_wall[CENTER + i], s);
                min_rel = min(min_rel, CENTER + i);
                max_rel = max(max_rel, CENTER + i);
			}
		}
        c += del_c;
        d += del_d;
        s += del_s;
        e += del_pi;
        w += del_pi;
	}
};

int main(){
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        c = 0;
        wall.clear();
        wall.resize(CENTER * 2, 0);
        new_wall.clear();
        new_wall.resize(CENTER * 2, 0);
        int tribes; cin >> tribes;
        vector<tribe_t> tri;
        for (int t = 0; t < tribes; ++t) { tribe_t tr; tr.read(); tri.push_back(tr); }
        auto compare = [](const tribe_t& a, const tribe_t& b) -> bool { return a.d < b.d; };
        make_heap(begin(tri), end(tri), compare);
        int last_day = tri.front().d;
        while (tri.size() != 0) {
            int day = tri.front().d;
            if (day != last_day) {
                for (int i = min_rel; i <= max_rel; ++i)
                    wall[i] = new_wall[i];
                last_day = day;
			}
            auto next = tri.front();
            pop_heap(begin(tri), end(tri), compare);
            tri.pop_back();

            min_rel = INT_MAX;
            max_rel = INT_MIN;
            next.do_atk();

            if (next.n != 0) {
                tri.push_back(next);
                push_heap(begin(tri), end(tri), compare);
			}

		}
		cout << "Case #" << cas << ": " << c << "\n";
	}
}
