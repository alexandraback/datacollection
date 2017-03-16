#include <iostream>
#include <cstdio>
#include <map>

using namespace std;


int max_y = 1;
map<pair<int, int>, bool> used;
int solve(int x, int y, int n, int total) {
    if (total == n) {
        if (used[make_pair(x, y)]) return 1;
        else return 0;
    }
    //if (used[make_pair(x, y)]) {
        //return 1 << (n - total);
    //}
    int ans = 0;
    // Go left
    int current_x = 0;
    int current_y = max_y + 1;
    bool started = false;
    int x_offset = -1;
    int y_offset = -1;
    bool has_choice = true;
    for (;;) {
        if (!used[make_pair(current_x + x_offset, current_y + y_offset)] &&
            current_y + y_offset >= 0) {
            current_x += x_offset;
            current_y += y_offset;
            started = true;
        } else {
            if (started) {
                //cout << total << " " << current_x << " " << current_y << endl;
                used[make_pair(current_x, current_y)] = true;
                if (current_y == max_y + 1) {
                    max_y += 2;
                }
                ans += solve(x, y, n, total + 1);
                used[make_pair(current_x, current_y)] = false;
                if (current_y == max_y + 3) {
                    max_y -= 2;
                }
                break;
            } else {
                has_choice = false;
                started = true;
                x_offset = -x_offset;
            }
        }
    }
    // Go right
    if (!has_choice) {
        return ans;
    }
    current_x = 0;
    current_y = max_y + 1;
    x_offset = 1;
    started = false;
    for (;;) {
        if (!used[make_pair(current_x + x_offset, current_y + y_offset)] &&
            current_y + y_offset >= 0) {
            current_x += x_offset;
            current_y += y_offset;
            started = true;
        } else {
            if (started) {
                used[make_pair(current_x, current_y)] = true;
                if (current_y == max_y + 1) {
                    max_y += 2;
                }
                ans += solve(x, y, n, total + 1);
                used[make_pair(current_x, current_y)] = false;
                if (current_y == max_y + 3) {
                    max_y -= 2;
                }
                break;
            } else {
                started = true;
                x_offset = -x_offset;
            }
        }
    }
    return ans;
}


int main() {
    int tn;
    cin >> tn;
    for (int tt = 1; tt <= tn; ++tt) {
        int n, x, y;
        used.clear();
        max_y = 1;
        cin >> n >> x >> y;
        used[make_pair(0, 0)] = true;
        int favorable = solve(x, y, n, 1);
        double prob = double(favorable) / ((1 << (n - 1)));
        printf("Case #%d: %.6f\n", tt, prob);
    }
    return 0;
}

