#include <iostream>
#include <stdio.h>


using namespace std;

char check_sequence(char seq[4]) {
    bool X_won = true;
    bool O_won = true;
    for (int i = 0; i < 4; ++i) {
        switch (seq[i]) {
        case 'X':
            O_won = false;
            break;
        case 'O':
            X_won = false;
            break;
        case '.':
            X_won = false;
            O_won = false;
            break;
        default:
            break;
        }
    }
    return X_won ? 'X' : (O_won ? 'O' : '.');
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input-file>" << endl;
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        cerr << "Couldn't open file" << endl;
        return 2;
    }
    int T = 0;
    if (!fscanf(fp, "%d", &T))
        cerr << "File not valid" << endl;

    for (int case_no = 0; case_no < T; ++case_no) {
        char buf[256];
        char state[4][4];
        bool draw_possible = true;

        for (int i = 0; i < 4; ++i) {
            fscanf(fp, "%s", buf);
            for (int j = 0; j < 4; ++j) {
                state[i][j] = buf[j];
                if (state[i][j] == '.') {
                    draw_possible = false;
                }
            }
        }

        char result = '.';

        // rows
        for (int i = 0; i < 4; ++i) {
            result = check_sequence(state[i]);
            if (result != '.')
                break;
        }

        // columns
        if (result == '.') {
            for (int j = 0; j < 4; ++j) {
                char tmp_state[4];
                for (int i = 0; i < 4; ++i) {
                    tmp_state[i] = state[i][j];
                }
                result = check_sequence(tmp_state);
                if (result != '.') {
                    break;
                }
            }
        }

        if (result == '.') {
            char tmp_state[4];
            for (int i = 0; i < 4; ++i) {
                tmp_state[i] = state[i][i];
            }
            result = check_sequence(tmp_state);
        }

        if (result == '.') {
            char tmp_state[4];
            for (int i = 0; i < 4; ++i) {
                tmp_state[i] = state[i][3-i];
            }
            result = check_sequence(tmp_state);
        }

        printf("Case #%d: ", case_no + 1);
        switch (result) {
        case 'X':
            printf("X won");
            break;
        case 'O':
            printf("O won");
            break;
        case '.':
            if (draw_possible) {
                printf("Draw");
            } else {
                printf("Game has not completed");
            }
            break;
        }
        printf("\n");
    }

    return 0;
}
