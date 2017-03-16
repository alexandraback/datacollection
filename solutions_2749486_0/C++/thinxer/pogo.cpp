#include <iostream>
#include <cmath>

using namespace std;

string result;

bool solve(int x, int y, int steps, char last_dir) {
    // cout << "solving: " << x << ", " << y << " in " << steps << " steps, with dir [" << last_dir << "]" << endl;
    int farest = steps * (steps + 1) / 2;
    if (steps == 0) {
        if (x == 0 && y == 0) {
            result += last_dir;
            return true;
        } else {
            return false;
        }
    }
    if (abs(x) + abs(y) > farest) return false;
    const char * orders = "NEWS";
    for (int i = 0; i < 4; i++) {
        char dir = orders[i];
        bool ret = false;
        switch (dir) {
            case 'W':
                ret = solve(x - steps, y, steps - 1, dir);
                break;
            case 'E':
                ret = solve(x + steps, y, steps - 1, dir);
                break;
            case 'S':
                ret = solve(x, y - steps, steps - 1, dir);
                break;
            case 'N':
                ret = solve(x, y + steps, steps - 1, dir);
                break;
        }
        if (ret == true) {
            result += last_dir;
            return true;
        }
    }
    return false;
}

void print_result() {
    for (int i = 0; i < result.size() - 1; i++) {
        char x = result.at(i);
        if (x == 'W') cout << 'E';
        if (x == 'E') cout << 'W';
        if (x == 'N') cout << 'S';
        if (x == 'S') cout << 'N';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        int steps = 0;
        do {
            result = "";
            steps++;
            cerr << "running case #" << i << "[" << steps << "]" << endl;
        } while (!solve(x, y, steps, '!'));
        cout << "Case #" << (i + 1) << ": ";
        print_result();
    }
}
