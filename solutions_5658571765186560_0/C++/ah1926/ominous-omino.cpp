#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

#define x first
#define y second

using namespace std;

typedef pair<int, int> Point;

const int MAX_D = 4;
const int DX[MAX_D] = {-1, 0, 1, 0};
const int DY[MAX_D] = {0, 1, 0, -1};
const int oo = 0x3f3f3f3f;

int DFS(vector< vector<bool> > &board, const int x, const int y) {
    int size = 1;
    board[x][y] = false;
    for (int d = 0; d < MAX_D; ++d) {
        int nx = x + DX[d], ny = y + DY[d];
        if (0 <= nx && nx < int(board.size()) && 0 <= ny && ny < int(board[0].size()) && board[nx][ny])
            size += DFS(board, nx, ny);
    }
    return size;
}

vector<Point> NormalizePolyomino(vector<Point> polyomino) {
    int xmin = oo, ymin = oo;
    for (const auto &c: polyomino) {
        xmin = min(xmin, c.x);
        ymin = min(ymin, c.y);
    }
    for (auto &c: polyomino) {
        c.x -= xmin;
        c.y -= ymin;
    }
    sort(polyomino.begin(), polyomino.end());
    return polyomino;
}

bool IsPolyomino(const vector<Point> &polyomino) {
    int xmin = oo, ymin = oo, xmax = -oo, ymax = -oo;
    for (const auto &c: polyomino) {
        xmin = min(xmin, c.x);
        ymin = min(ymin, c.y);
        xmax = max(xmax, c.x);
        ymax = max(ymax, c.y);
    }
    vector< vector<bool> > board = vector< vector<bool> >(xmax - xmin + 1, vector<bool>(ymax - ymin + 1, false));
    for (const auto &c: polyomino) {
        if (board[c.x - xmin][c.y - ymin])
            return false;
        board[c.x - xmin][c.y - ymin] = true;
    }
    return DFS(board, polyomino[0].x - xmin, polyomino[0].y - ymin) == int(polyomino.size());
}

void GeneratePolyominoes(const int n, vector<Point> &polyomino, set< vector<Point> > &polyominoSet) {
    if (int(polyomino.size()) == n) {
        polyominoSet.insert(NormalizePolyomino(polyomino));
        return;
    }
    for (int i = 0; i < int(polyomino.size()); ++i) {
        int x = polyomino[i].x, y = polyomino[i].y;
        for (int d = 0; d < MAX_D; ++d) {
            int nx = x + DX[d], ny = y + DY[d];
            polyomino.push_back(Point(nx, ny));
            if (IsPolyomino(polyomino))
                GeneratePolyominoes(n, polyomino, polyominoSet);
            polyomino.pop_back();
        }
    }
}

bool CoverBoard(vector< vector<bool> > &board, const int coveredArea, const set< vector<Point> > &polyominoes) {
    int rows = int(board.size()), columns = int(board[0].size());
    if (coveredArea == rows * columns)
        return true;
    for (const auto &p: polyominoes) {
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < columns; ++y) {
                bool valid = true;
                for (const auto &c: p) {
                    int nx = c.x + x, ny = c.y + y;
                    if (nx < 0 || rows <= nx || ny < 0 || columns <= ny || board[nx][ny])
                        valid = false;
                }
                if (valid) {
                    for (const auto &c: p)
                        board[c.x + x][c.y + y] = true;
                    if (CoverBoard(board, coveredArea + int(p.size()), polyominoes))
                        return true;
                    for (const auto &c: p)
                        board[c.x + x][c.y + y] = false;
                }
            }
        }
    }
    return false;
}

inline void Mirror(vector<Point> &polyomino) {
    for (auto &c: polyomino)
        c.y = -c.y;
}

inline void Rotate(vector<Point> &polyomino) {
    for (auto &c: polyomino)
        c = Point(-c.y, c.x);
}

string Solve(const int rows, const int columns, const int size) {
    vector<Point> polyomino = vector<Point>(1, Point(0, 0));
    set< vector<Point> > polyominoes;
    GeneratePolyominoes(size, polyomino, polyominoes);
    for (auto polyomino: polyominoes) {
        bool impossible = true;
        for (int r = 0; r < 4; ++r) {
            Rotate(polyomino);
            for (int m = 0; m < 2; ++m) {
                Mirror(polyomino);
                vector<Point> p = NormalizePolyomino(polyomino);
                for (int x = 0; x < rows && impossible; ++x) {
                    for (int y = 0; y < columns && impossible; ++y) {
                        bool valid = true;
                        for (const auto &c: p) {
                            int nx = c.x + x, ny = c.y + y;
                            if (nx < 0 || rows <= nx || ny < 0 || columns <= ny)
                                valid = false;
                        }
                        if (valid) {
                            vector< vector<bool> > board = vector< vector<bool> >(rows, vector<bool>(columns, false));
                            for (const auto &c: p)
                                board[c.x + x][c.y + y] = true;
                            if (CoverBoard(board, size, polyominoes))
                                impossible = false;
                        }
                    }
                }
            }
        }
        if (impossible)
            return "Richard";
    }
    return "Gabriel";
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int R, C, X;
        cin >> X >> R >> C;
        string answer = "";
        //if (R < 3 || C < 3 || R * C < 21 || X < 7)
            answer = Solve(R, C, X);
        //else
            //answer = "Richard";
        cout << "Case #" << t << ": " << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
