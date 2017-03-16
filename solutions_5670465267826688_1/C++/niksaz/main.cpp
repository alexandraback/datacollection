#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
const int N = 100000 + 10;
const int matrix[5][5] = {
    {0, 1, 2, 3, 4},
    {1, 1, 2, 3, 4},
    {2, 2, -1, 4, -3},
    {3, 3, -4, -1, 2},
    {4, 4, 3, -2, -1}};

int l;
long long x;
int ps;
int used;
int automata[10][N];
int first_ps[10][10];
int mas[4];

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

int lets(int state, int go) {
    bool negative = false;
    if (state < 0) {
        negative ^= true;
        state *= -1;
    }
    if (go < 0) {
        negative ^= true;
        go *= -1;
    }
    int res = matrix[state][go];
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
        for (int start = 0; start < 10; start++) {
            int state = start - 5;
            for (int i = 0; i < 10; i++) {
                first_ps[start][i] = 0;
            }
            for (int i = 0; i < l; i++) {
                state = next_state(state, s[i]);
                automata[start][i] = state;
                int value = state + 5;
                if (first_ps[start][value] == 0) {
                    first_ps[start][value] = i + 1;
                }
            }
        }
        int ps = -1;
        int used = 0;
        int state = 0;
        for (int it = 1; it <= 50; it++) {
            if (first_ps[state + 5][7] != 0) {
                ps = first_ps[state + 5][7] - 1;
                state = 2;
                break;
            } else {
                state = automata[state + 5][l - 1];
                used++;
                if (used == x) {
                    break;
                }
            }
        }
        if (state != 2 || used == x) {
            print_ans(t, "NO");
            continue;
        }
        state = 0;
        while (true) {
            ps++;
            if (ps == l) {
                ps = -1;
                used++;
                break;
            }
            state = next_state(state, s[ps]);
            if (state == 3) {
                break;
            }
        }
        if (state != 3) {
            for (int it = 1; it <= 50; it++) {
                if (first_ps[state + 5][8] != 0) {
                    ps = first_ps[state + 5][8] - 1;
                    state = 3;
                    break;
                } else {
                    state = automata[state + 5][l - 1];
                    used++;
                    if (used == x) {
                        break;
                    }
                }
            }
        }
        if (state != 3 || used == x) {
            print_ans(t, "NO");
            continue;
        }
        state = 0;
        while (true) {
            ps++;
            if (ps == l) {
                ps = -1;
                used++;
                break;
            }
            state = next_state(state, s[ps]);
        }
        long long leave = x - used;
        leave %= 4;
        mas[1] = automata[5][l - 1];
        mas[2] = automata[mas[1] + 5][l - 1];
        mas[3] = automata[mas[2] + 5][l - 1];
        mas[0] = automata[mas[3] + 5][l - 1];
        state = lets(state, mas[leave]);
        print_ans(t, (state == 4 ? "YES" : "NO"));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
