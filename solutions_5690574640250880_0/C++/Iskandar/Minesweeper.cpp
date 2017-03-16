#include<iostream>
#include<utility>
#include<queue>

using namespace std;

/** Global variable */
char map[7][7];
int T, R, C, GM;

bool check(int x, int y) {
    bool isChecked[7][7];
    int num = R * C - GM;

    for (int p = 0; p <= R+1; p++)
        for (int q = 0; q <= C+1; q++)
            isChecked[p][q] = false;

    queue< pair<int, int> > points;
    pair<int, int> current_point, temp_point, temp_point2;

    current_point = make_pair(x, y);
    points.push(current_point);

    isChecked[x][y] = true;

    while(!points.empty()) {
        temp_point = points.front();
        points.pop();
        if (temp_point.first == 0 || temp_point.first == R+1) continue;
        if (temp_point.second == 0 || temp_point.second == C+1) continue;
        num--;

        bool isFlagged = false;

        if (map[temp_point.first-1][temp_point.second-1] == '*') isFlagged = true;
        if (map[temp_point.first-1][temp_point.second] == '*') isFlagged = true;
        if (map[temp_point.first-1][temp_point.second+1] == '*') isFlagged = true;
        if (map[temp_point.first][temp_point.second-1] == '*') isFlagged = true;
        if (map[temp_point.first][temp_point.second+1] == '*') isFlagged = true;
        if (map[temp_point.first+1][temp_point.second-1] == '*') isFlagged = true;
        if (map[temp_point.first+1][temp_point.second] == '*') isFlagged = true;
        if (map[temp_point.first+1][temp_point.second+1] == '*') isFlagged = true;

        if (!isFlagged) {
            if (!isChecked[temp_point.first-1][temp_point.second-1]) {
                temp_point2 = make_pair(temp_point.first - 1, temp_point.second - 1);
                isChecked[temp_point.first-1][temp_point.second-1] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first-1][temp_point.second]) {
                temp_point2 = make_pair(temp_point.first - 1, temp_point.second);
                isChecked[temp_point.first-1][temp_point.second] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first-1][temp_point.second+1]) {
                temp_point2 = make_pair(temp_point.first - 1, temp_point.second + 1);
                isChecked[temp_point.first-1][temp_point.second+1] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first][temp_point.second-1]) {
                temp_point2 = make_pair(temp_point.first, temp_point.second - 1);
                isChecked[temp_point.first][temp_point.second-1] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first][temp_point.second+1]) {
                temp_point2 = make_pair(temp_point.first, temp_point.second + 1);
                isChecked[temp_point.first][temp_point.second+1] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first+1][temp_point.second-1]) {
                temp_point2 = make_pair(temp_point.first + 1, temp_point.second - 1);
                isChecked[temp_point.first+1][temp_point.second-1] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first+1][temp_point.second]) {
                temp_point2 = make_pair(temp_point.first + 1, temp_point.second);
                isChecked[temp_point.first+1][temp_point.second] = true;
                points.push(temp_point2);
            }
            if (!isChecked[temp_point.first+1][temp_point.second+1]) {
                temp_point2 = make_pair(temp_point.first + 1, temp_point.second + 1);
                isChecked[temp_point.first+1][temp_point.second+1] = true;
                points.push(temp_point2);
            }
        }
    }

    if (num == 0) return true;
    else return false;
}

int main() {

    cin >> T;

    for (int i = 1; i <= T; i++) {
        bool isPossible = false;
        int M;

        cin >> R >> C >> GM;
        M = GM;

        /** Initialize */
        for (int j = 0; j <= R+1; j++)
            for (int k = 0; k <= C+1; k++) {
                if (j == 0 || j == R+1 || k == 0 || k == C+1) map[j][k] = '*';
                    else map[j][k] = '.';
            }

        /** Fill the bomb */
        int x = 1, y = 1, direction = 1;
        while (M != 0) {
            if (direction == 1) {
                if (map[x][y] == '*') {
                    direction = 2; // down
                    y--; x++;
                } else {
                    map[x][y] = '*';
                    y++; M--;
                }
            }
            if (direction == 2) {
                if (map[x][y] == '*') {
                    direction = 3; // left
                    x--; y--;
                } else {
                    map[x][y] = '*';
                    x++; M--;
                }
            }
            if (direction == 3) {
                if (map[x][y] == '*') {
                    direction = 4; // up
                    y++; x--;
                } else {
                    map[x][y] = '*';
                    y--; M--;
                }
            }
            if (direction == 4) {
                if (map[x][y] == '*') {
                    direction = 1; // left
                    x++; y++;
                } else {
                    map[x][y] = '*';
                    x--; M--;
                }
            }
        }

        for (int j = 0; j <= R+1; j++) {
            map[j][0] = '.';
            map[j][C+1] = '.';
        }
        for (int j = 0; j <= C+1; j++) {
            map[0][j] = '.';
            map[R+1][j] = '.';
        }

        for (int j = 1; j <= R; j++) {
            for (int k = 1; k <= C; k++) {
                if (map[j][k] == '.') isPossible = check(j, k);
                if (isPossible) {
                    map[j][k] = 'c';
                    break;
                }
            }
            if (isPossible) break;
        }

        cout << "Case #" << i << ":" << endl;

        if (isPossible) {
            for (int j = 1; j <= R; j++)
                for (int k = 1; k <= C; k++) {
                    cout << map[j][k];
                    if (k == C) cout << endl;
                }
        } else cout << "Impossible" << endl;
    }

    return 0;
}
/** Created by freedomofkeima */
