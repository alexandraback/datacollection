#include <iostream>

int w[10][4][2] =
{
    { {0,0}, {0,1}, {0,2}, {0,3} },
    { {1,0}, {1,1}, {1,2}, {1,3} },
    { {2,0}, {2,1}, {2,2}, {2,3} },
    { {3,0}, {3,1}, {3,2}, {3,3} },
    { {0,0}, {1,0}, {2,0}, {3,0} },
    { {0,1}, {1,1}, {2,1}, {3,1} },
    { {0,2}, {1,2}, {2,2}, {3,2} },
    { {0,3}, {1,3}, {2,3}, {3,3} },
    { {0,0}, {1,1}, {2,2}, {3,3} },
    { {3,0}, {2,1}, {1,2}, {0,3} }
};

int T;
char m[4][4];

bool xwin() {
    for (int i = 0; i < 10; i++) {
        bool win = true;
        for (int j = 0; j < 4; j++) {
            if (m[w[i][j][0]][w[i][j][1]] != 'X' &&
                m[w[i][j][0]][w[i][j][1]] != 'T')
            {
                win = false;
                break;
            }
        }
        if (win) return true;
    }
    return false;
}

void flip() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (m[y][x] == 'X') m[y][x] = 'O';
            else if (m[y][x] == 'O') m[y][x] = 'X';
        }
    }
}

bool filled() {
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if (m[y][x] == '.')
                return false;
    return true;
}

int main()
{
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                std::cin >> m[y][x];

        if (xwin()) {
            std::cout << "Case #" << t << ": X won\n";
            continue;
        }
        
        flip();
        if (xwin()) {
            std::cout << "Case #" << t << ": O won\n";
            continue;
        }

        if (filled()) {
            std::cout << "Case #" << t << ": Draw\n";
        }
        else {
            std::cout << "Case #" << t << ": Game has not completed\n";
        }
    }
}

