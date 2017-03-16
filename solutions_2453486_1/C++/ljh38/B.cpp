#include <iostream>
#include <fstream>

using namespace std;

bool match(char c, char test) {
    return c == test || c == 'T';
}

bool winner(char a, char b, char c, char d, char test) {
    return match(a, test) && match(b, test) && match(c, test) && match(d, test);
}

int main()
{
    std::istream& input = cin;
    // std::ifstream input("sample");

    int T = 0;
    input >> T;
    
    for (int t = 0; t != T; ++t) {

        std::string lines[4];
        input >> lines[0] >> lines[1] >> lines[2] >> lines[3];

        bool XWon = false;
        bool OWon = false;
        bool spaces = false;
        for (int i = 0; i != 4; ++i) {
            XWon |= winner(lines[0][i], lines[1][i], lines[2][i], lines[3][i], 'X');
            XWon |= winner(lines[i][0], lines[i][1], lines[i][2], lines[i][3], 'X');
            OWon |= winner(lines[0][i], lines[1][i], lines[2][i], lines[3][i], 'O');
            OWon |= winner(lines[i][0], lines[i][1], lines[i][2], lines[i][3], 'O');
            spaces |= (lines[0][i] == '.' || lines[1][i] == '.' || lines[2][i] == '.' || lines[3][i] == '.');
        }
        XWon |= winner(lines[0][0], lines[1][1], lines[2][2], lines[3][3], 'X');
        OWon |= winner(lines[0][0], lines[1][1], lines[2][2], lines[3][3], 'O');
        XWon |= winner(lines[0][3], lines[1][2], lines[2][1], lines[3][0], 'X');
        OWon |= winner(lines[0][3], lines[1][2], lines[2][1], lines[3][0], 'O');

        if (XWon) {
            cout << "Case #" << t + 1 << ": X won\n";
        } else if (OWon) {
            cout << "Case #" << t + 1 << ": O won\n";
        } else if (spaces) {
            cout << "Case #" << t + 1 << ": Game has not completed\n";
        } else {
            cout << "Case #" << t + 1 << ": Draw\n";
        }
    }

    return 0;
}
