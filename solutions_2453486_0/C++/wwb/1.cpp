#include <iostream>
#include <string>
using namespace std;

class Game
{
public:
    Game() {for (int i = 0; i <16; ++i) cin >> state[i];}

    bool check(int begin, int step, char x)
    {
        for (int i = 0; i <4; ++i)
            if (state[begin + i * step] != x && state[begin + i * step] != 'T')
                return false;
        return true;
    }
    string result()
    {
        if (check(0, 1, 'X') || check(4, 1, 'X') || check(8, 1, 'X') || check(12, 1, 'X') || check(0, 5, 'X') || check(3, 3, 'X')) return "X won";
        if (check(0, 1, 'O') || check(4, 1, 'O') || check(8, 1, 'O') || check(12, 1, 'O') || check(0, 5, 'O') || check(3, 3, 'O')) return "O won";
        if (check(0, 4, 'X') || check(1, 4, 'X') || check(2, 4, 'X') || check(3, 4, 'X')) return "X won";
        if (check(0, 4, 'O') || check(1, 4, 'O') || check(2, 4, 'O') || check(3, 4, 'O')) return "O won";
        for (int i = 0; i < 16; ++i) if (state[i] == '.') return "Game has not completed";
        return "Draw";
    }
private:
    char state[16];
};

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        Game g;
        cout << "Case #" << i << ":" << " " << g.result() << endl;
    }
}