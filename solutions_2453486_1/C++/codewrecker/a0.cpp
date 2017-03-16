#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

pair<bool, char> is_win(char c1, char c2, char c3, char c4)
{
    bool win = true;
    char base = c1;
    if (c1 == 'T')
        base = c2;
    if (base == '.') {
        win = false;
        goto end;
    }
    if (c2 != 'T' && c2 != base) {
        win = false;
        goto end;
    }
    if (c3 != 'T' && c3 != base) {
        win = false;
        goto end;
    }
    if (c4 != 'T' && c4 != base) {
        win = false;
        goto end;
    }

    //cout << c1 << c2 << c3 << c4 << " " << win << " " << base << endl;

    end:
    return {win, base};
}

int main()
{
    int T, tcnt = 0;
    cin >> T;
    string line;
    getline(cin, line); //newline after T

    while (T--) {
        vector<string> vs;
        for (int i = 0; i < 4; ++i) {
            getline(cin, line);
            vs.push_back(line);
        }
        getline(cin, line);
        bool x_win = false, o_win = false, draw = false;
        int fill_cnt = 0;
        for (int row = 0; row < 4; ++row) {
            char c0 = vs[row][0];
            if (c0 != '.')
                ++fill_cnt;
            char c1 = vs[row][1];
            if (c1 != '.')
                ++fill_cnt;
            char c2 = vs[row][2];
            if (c2 != '.')
                ++fill_cnt;
            char c3 = vs[row][3];
            if (c3 != '.')
                ++fill_cnt;
            auto p = is_win(c0, c1, c2, c3);
            if (p.first) {
                if (p.second == 'X')
                    x_win = true;
                else
                    o_win = true;
                break;
            }
        }
        if (!x_win && !o_win) {
            for (int col = 0; col < 4; ++col) {
                char c0 = vs[0][col];
                char c1 = vs[1][col];
                char c2 = vs[2][col];
                char c3 = vs[3][col];
                auto p = is_win(c0, c1, c2, c3);
                if (p.first) {
                    if (p.second == 'X')
                        x_win = true;
                    else
                        o_win = true;
                    break;
                }
            }
            if (!x_win && !o_win) {
                char c0 = vs[0][0], c1 = vs[1][1], c2 = vs[2][2], c3 = vs[3][3];
                auto p = is_win(c0, c1, c2, c3);
                if (p.first) {
                    if (p.second == 'X')
                        x_win = true;
                    else
                        o_win = true;
                } else {
                    char c0 = vs[3][0], c1 = vs[2][1], c2 = vs[1][2], c3 = vs[0][3];
                    auto p = is_win(c0, c1, c2, c3);
                    if (p.first) {
                        if (p.second == 'X')
                            x_win = true;
                        else
                            o_win = true;
                    }    
                }
            }
            if (!x_win && !o_win)
                if (fill_cnt == 16)
                    draw = true;
        }
        cout << "Case #" << ++tcnt << ": ";
        if (x_win)
            cout << "X won" << endl;
        else if (o_win)
            cout << "O won" << endl;
        else if (draw)
            cout << "Draw" << endl;
        else
            cout << "Game has not completed" << endl;
    }
}

