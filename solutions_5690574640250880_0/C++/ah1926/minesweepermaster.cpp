#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_D = 8;
const int DX[MAX_D] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int DY[MAX_D] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MAX_R = 5;
const int MAX_C = 5;

vector< vector<char> > SmallTables[MAX_R + 1][MAX_C + 1][MAX_R * MAX_C + 1];

inline void FillTable(vector< vector<char> > &table) {
    int rows = int(table.size()), columns = int(table[0].size());
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < columns; ++y) {
            if (table[x][y] == '*')
                continue;
            int count = 0;
            for (int d = 0; d < MAX_D; ++d) {
                int nx = x + DX[d], ny = y + DY[d];
                if (nx < 0 || rows <= nx || ny < 0 || columns <= ny)
                    continue;
                if (table[nx][ny] == '*')
                    ++count;
            }
            table[x][y] = char('0' + count);
        }
    }
}

void DFS(const vector< vector<char> > &table, const int x, const int y, vector< vector<bool> > &used) {
    int rows = int(table.size()), columns = int(table[0].size());
    used[x][y] = true;
    if (table[x][y] != '0')
        return;
    for (int d = 0; d < MAX_D; ++d) {
        int nx = x + DX[d], ny = y + DY[d];
        if (nx < 0 || rows <= nx || ny < 0 || columns <= ny)
            continue;
        if (table[nx][ny] == '*' || used[nx][ny])
            continue;
        DFS(table, nx, ny, used);
    }
}

inline bool ValidTable(const vector< vector<char> > &table) {
    int rows = int(table.size()), columns = int(table[0].size());
    vector< vector<bool> > used = vector< vector<bool> >(rows, vector<bool>(columns, false));
    int zeroComponents = 0, safeCells = 0;
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < columns; ++y) {
            if (used[x][y])
                continue;
            if (table[x][y] != '*')
                ++safeCells;
            if (table[x][y] == '0') {
                DFS(table, x, y, used);
                ++zeroComponents;
            }
        }
    }
    if (safeCells == 1)
        return true;
    if (zeroComponents > 1)
        return false;
    for (int x = 0; x < rows; ++x)
        for (int y = 0; y < columns; ++y)
            if (table[x][y] != '*' && !used[x][y])
                return false;
    return true;
}

inline vector< vector<char> > GetSmallTable(const int rows, const int columns, const int mask) {
    vector< vector<char> > table = vector< vector<char> >(rows, vector<char>(columns, '.'));
    for (int x = 0, bit = 0; x < rows; ++x)
        for (int y = 0; y < columns; ++y, ++bit)
            if ((mask >> bit) & 1)
                table[x][y] = '*';
    return table;
}

void PreprocessSmallTables() {
    for (int rows = 1; rows <= MAX_R; ++rows) {
        for (int columns = 1; columns <= MAX_C; ++columns) {
            for (int mask = 0; mask < (1 << (rows * columns)); ++mask) {
                int count = 0;
                for (int bit = 0; bit < rows * columns; ++bit)
                    if ((mask >> bit) & 1)
                        ++count;
                if (!SmallTables[rows][columns][count].empty())
                    continue;
                vector< vector<char> > table = GetSmallTable(rows, columns, mask);
                FillTable(table);
                if (ValidTable(table))
                    SmallTables[rows][columns][count] = table;
            }
        }
    }
}

inline void ClickTable(vector< vector<char> > &table) {
    int rows = int(table.size()), columns = int(table[0].size()), safeCells = 0;
    bool clicked = false;
    for (int x = 0; x < rows && !clicked; ++x) {
        for (int y = 0; y < columns && !clicked; ++y) {
            if (table[x][y] == '0') {
                table[x][y] = 'c';
                clicked = true;
            }
            if (table[x][y] != '*')
                ++safeCells;
        }
    }
    if (!clicked && safeCells == 1) {
        for (int x = 0; x < rows && !clicked; ++x) {
            for (int y = 0; y < columns && !clicked; ++y) {
                if (table[x][y] != '*') {
                    table[x][y] = 'c';
                    clicked = true;
                }
            }
        }
    }
    for (int x = 0; x < rows; ++x)
        for (int y = 0; y < columns; ++y)
            if (table[x][y] != '*' && table[x][y] != 'c')
                table[x][y] = '.';
}

int main() {
    PreprocessSmallTables();
    ifstream in("input.txt");
    ofstream out("output.txt");
    int testCount;
    in >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int rows, columns, count;
        in >> rows >> columns >> count;
        out << "Case #" << t << ":\n";
        if (SmallTables[rows][columns][count].empty()) {
            out << "Impossible\n";
            continue;
        }
        vector< vector<char> > table = SmallTables[rows][columns][count];
        ClickTable(table);
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < columns; ++y)
                out << table[x][y];
            out << "\n";
        }
    }
    in.close();
    out.close();
    return 0;
}
