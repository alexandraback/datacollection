#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORI(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,b) FOR(i,0,b)

struct board {
    const int R;
    const int C;
    const int M;
    char data[54][54];

    board(int R, int C, int M) : R(R), C(C), M(M) {
        REP(y, R+2) {
            REP(x, C+2) {
                data[y][x] = within(x, y) ? '*' : '.';
            }
        }
    }

    void print() const;
    void debug_print() const;

    bool within(int x, int y) const {
        return 1 <= y && y <= R && 1 <= x && x <= C;

    }

    char& operator()(int x, int y) {
        return data[y+1][x+1];
    }

    char operator ()(int x, int y) const {
        return data[y+1][x+1];
    }

    int count_possible_mines() const;

    bool brute_force(const int x, const int y);

    void expand_selection(int x, int y);

    void place_trivial();
};

struct snapshot {
    board& b;
    const int x1;
    const int y1;
    char data[3][3];

    snapshot(board& b, int x, int y): b(b), x1(x-1), y1(y-1) {
        // cout << "START x1="<<x1<<",y1="<<y1<<endl;
        REP(dy,3){
            REP(dx, 3){
                data[dy][dx] = b(x1+dx, y1+dy);
            }
        }
    }

    void revert() {
        // cout << "REV   x1="<<x1<<",y1="<<y1<<endl;
        REP(dy,3){
            REP(dx, 3){
                b(x1+dx, y1+dy) = data[dy][dx];
            }
        }
    }
};

void board::print() const{
    bool printed_self = false;
    REP(y,R) {
        REP(x,C) {
            const char c = (*this)(x,y);
            char output;
            switch(c) {
                case '*':
                    output = '*'; break;
                case '.':
                    if (!printed_self) {
                        output = 'c';
                        printed_self = true;
                        break;
                    }
                    output = '.';
                    break;
                default:
                    output = '.';
                    break;
            }
            cout << output;
        }
        cout << endl;
    }
}

void board::debug_print() const{
    REP(y,R) {
        REP(x,C) {
            const char c = (*this)(x,y);
            cout << c;
        }
        cout << endl;
    }
}

void board::place_trivial() {
    assert(M == R * C - 1);
    (*this)(0, 0) = '.';
}

void board::expand_selection(const int x, const int y) {
    assert((*this)(x, y) != '.');
    const int x1 = max(0, x-1);
    const int x2 = min(C, x+2);
    const int y1 = max(0, y-1);
    const int y2 = min(R, y+2);

    (*this)(x, y) = '.';

    FOR(ny, y1, y2) {
        FOR(nx, x1, x2) {
            char& val = (*this)(nx, ny);
            if (val == '.' || val == '!') {
                continue;
            }
            val = (x == nx || y == ny) ? '!' : '?';
        }
    }
}

int board::count_possible_mines() const {
    int seen = 0;
    REP(y, R) {
        REP(x, C) {
            if ((*this)(x, y) == '*') {
                seen++;
            }
        }
    }
    return seen;
}

// * blocked
// ? candidate square
// ! adjacend to placed
// . placed square

// Brute force a board which already has one piece played.
bool board::brute_force(const int newX, const int newY) {
    snapshot snap(*this, newX, newY);
    expand_selection(newX, newY);
    const int seen = count_possible_mines();

    // cout << "seen=" << seen << endl;
    if (seen == M) {
        return true;
    } else if (seen < M) {
        snap.revert();
        return false;
    }

    REP(y, R) {
        REP(x, C) {
            if ((*this)(x, y) == '!') {
                if (brute_force(x, y)) return true;
            }
        }
    }
    snap.revert();
    return false;
}

board* solve(const int R, const int C, const int M) {
    assert(1 <= R && R <= 50);
    assert(1 <= C && C <= 50);
    assert(0 <= M && M < R*C);


    board* b = new board(R, C, M);

    if (R * C - 1 == M) {
        b->place_trivial();
        return b;
    }

    if (R == 2 || C == 2) {
        delete b;
        return nullptr;
    }
    FORI(y,0,(R+1)/2) {
        FORI(x,0,(C+1)/2) {
            // cout << "Trying..."<<endl;
            if (b->brute_force(x, y)) {
                return b;
            }
        }
    }

    delete b;
    return nullptr;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int R, C, M;
        cin >> R >> C >> M;
        cerr << R << " " << C << " " << M << endl;

        board* solution = solve(R, C, M);
        cout << "Case #" << (i+1) << ":" << endl;
        if (solution == nullptr) {
            cout << "Impossible" << endl;
        } else {
            solution->print();
            delete solution;
        }
    }
}
