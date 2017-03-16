#include <iostream>
#include <string>
using namespace std;
string Solve(int X, int Y);

int main(void)
{
    int T;
    cin >> T;
    int i = 1;
    while (T--) {
        int X, Y;
        cin >> X >> Y;
        cout << "Case #" << i++  << ": " << Solve(X, Y) << endl;
    }

    return 0;
}

string Solve(int X, int Y)
{
    string path;
    if (X) {
    int x = 0;
    int dir = (X < 0) ? -1 : 1;
    int i = 1;
    do {
        x += (i*dir);
        if (-1 == dir) {
            path += 'W';
            dir = 1;
        } else {
            path += 'E';
            dir = -1;
        }
        ++i;
    } while (x != X);
    }

    if (Y) {
    int y = 0;
    int dir = (Y < 0) ? 1 : -1;
    int i = 1;
    do {
        y += (i*dir);
        if (-1 == dir) {
            path += 'S';
            dir = 1;
        } else {
            path += 'N';
            dir = -1;
        }
        ++i;
    } while (y != Y);
    }
    return path;
}

