#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int matrix[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, -1, 4, -3},
    {0, 3, -4, -1, 2},
    {0, 4, 3, -2, -1}};

int l;
long long x;
int ps;
int used;

void print_ans(int t, string ans) {
    cout << "Case #" << t << ": " << ans << "\n";
}

void move() {
    ps++;
    if (ps == l) {
        ps = 0;
        used++;
    }
}

int convert(char c) {
    if (c == 'i') {
        return 2;
    } else if (c == 'j') {
        return 3;
    } else {
        return 4;
    }
}

int next_state(int state, char c) {
    bool negative = false;
    if (state < 0) {
        negative = true;
        state *= -1;
    }
    int res = matrix[state][convert(c)];
    if (negative) {
        res *= -1;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        cin >> l >> x;
        string s;
        cin >> s;
        ps = 0;
        used = 0;
        int state = convert(s[ps]);
        while (state != 2) {
            move();
            if (used == x) {
                break;
            }
            state = next_state(state, s[ps]);
        }
        if (used == x) {
            print_ans(t, "NO");
            continue;
        }
        move();
        if (used == x) {
            print_ans(t, "NO");
            continue;
        }
        state = convert(s[ps]);
        while (state != 3) {
            move();
            if (used == x) {
                break;
            }
            state = next_state(state, s[ps]);
        }
        if (used == x) {
            print_ans(t, "NO");
            continue;
        }
        move();
        if (used == x) {
            print_ans(t, "NO");
            continue;
        }
        state = convert(s[ps]);
        while (true) {
            move();
            if (used == x) {
                break;
            }
            state = next_state(state, s[ps]);
        }
        print_ans(t, (state == 4 ? "YES" : "NO"));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
