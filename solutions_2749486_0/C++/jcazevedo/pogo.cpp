#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define MAXX 200
#define MAXY 200
#define MAXM 500

char p[MAXX + 1][MAXY + 1][MAXM + 1];
int T, X, Y;

string getDirections() {
    X += 100;
    Y += 100;

    for (int i = 0; i <= MAXX; i++) {
        for (int j = 0; j <= MAXY; j++) {
            for (int k = 0; k <= MAXM; k++) {
                p[i][j][k] = '-';
            }
        }
    }

    p[100][100][0] = '.';

    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(100, 100), 0));

    //    cout << X << " " << Y << endl;

    while (!q.empty()) {
        pair<pair<int, int>, int> s = q.front(); q.pop();
        int x = s.first.first;
        int y = s.first.second;
        int m = s.second;
        int n = m + 1;

        if (x == X && y == Y)
            break;

        if (n <= MAXM) {
            if (y + n <= MAXY && p[x][y + n][n] == '-') {
                p[x][y + n][n] = 'N';
                q.push(make_pair(make_pair(x, y + n), n));
            }

            if (y - n >= 0 && p[x][y - n][n] == '-') {
                p[x][y - n][n] = 'S';
                q.push(make_pair(make_pair(x, y - n), n));
            }

            if (x + n <= MAXX && p[x + n][y][n] == '-') {
                p[x + n][y][n] = 'E';
                q.push(make_pair(make_pair(x + n, y), n));
            }

            if (x - n >= 0 && p[x - n][y][n] == '-') {
                p[x - n][y][n] = 'W';
                q.push(make_pair(make_pair(x - n, y), n));
            }
        }
    }

    string s = "";

    for (int i = 1; i <= MAXM; i++) {
        if (p[X][Y][i] != '-') {
            int k = i;
            while (p[X][Y][k] != '-' && k > 0) {
                s = p[X][Y][k] + s;
                if (p[X][Y][k] == 'N')
                    Y -= k;
                else if (p[X][Y][k] == 'S')
                    Y += k;
                else if (p[X][Y][k] == 'E')
                    X -= k;
                else if (p[X][Y][k] == 'W')
                    X += k;
                k--;
            }

            break;
        }
    }

    return s;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> X >> Y;
        cout << "Case #" << i << ": " << getDirections() << endl;
    }
    return 0;
}
