#include <iostream>
#include <string>

using namespace std;

const int FIELD_SIZE = 4;

char FIELD[2+FIELD_SIZE][2+FIELD_SIZE];

void read_input()
{
    for (int i = 1; i <= FIELD_SIZE; ++i) {
        for (int j = 1; j <= FIELD_SIZE; ++j) {
            cin >> FIELD[i][j];
        }
    }
}

typedef struct {
    int W, SW, S, SE;
} Counter;

Counter Xs[2+FIELD_SIZE][2+FIELD_SIZE];
Counter Os[2+FIELD_SIZE][2+FIELD_SIZE];

string solve()
{
    for (int i = FIELD_SIZE; i >= 1; --i) {
        for (int j = FIELD_SIZE; j >= 1; --j) {
            char c = FIELD[i][j];

            if (c == 'X' || c == 'T') {
                Xs[i][j].W = 1 + Xs[i][j+1].W;
                Xs[i][j].SW = 1 + Xs[i+1][j+1].SW;
                Xs[i][j].S = 1 + Xs[i+1][j].S;
                Xs[i][j].SE = 1 + Xs[i+1][j-1].SE;
            } else {
                Xs[i][j].W = 0;
                Xs[i][j].SW = 0;
                Xs[i][j].S = 0;
                Xs[i][j].SE = 0;
            }

            if (c == 'O' || c == 'T') {
                Os[i][j].W = 1 + Os[i][j+1].W;
                Os[i][j].SW = 1 + Os[i+1][j+1].SW;
                Os[i][j].S = 1 + Os[i+1][j].S;
                Os[i][j].SE = 1 + Os[i+1][j-1].SE;
            } else {
                Os[i][j].W = 0;
                Os[i][j].SW = 0;
                Os[i][j].S = 0;
                Os[i][j].SE = 0;
            }
        }
    }

    bool has_empty = false;
    for (int i = 1; i <= FIELD_SIZE; ++i) {
        for (int j = 1; j <= FIELD_SIZE; ++j) {
            const Counter &cX = Xs[i][j];
            if (cX.W == FIELD_SIZE || cX.SW == FIELD_SIZE ||
                cX.S == FIELD_SIZE || cX.SE == FIELD_SIZE) {
                return "X won";
            }
            const Counter &cO = Os[i][j];
            if (cO.W == FIELD_SIZE || cO.SW == FIELD_SIZE ||
                cO.S == FIELD_SIZE || cO.SE == FIELD_SIZE) {
                return "O won";
            }
            if (FIELD[i][j] == '.') {
                has_empty = true;
            }
        }
    }

    return (has_empty ? "Game has not completed" : "Draw");
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        read_input();
        string answer = solve();
        cout << "Case #" << t << ": " << answer << endl;
    }
}