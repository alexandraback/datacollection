//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
# include <utility>
# include <array>
# include <cassert>

using namespace std;

typedef std::vector<std::vector<char>> Field;

const char SPACE = '.', MINE = '*', CLICK = 'c';

Field makeField(int r, int c, char fill = SPACE)
{
    return Field(r, std::vector<char>(c, fill));
}

Field transpose(const Field & field)
{
    Field result = makeField(field.front().size(), field.size());
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[i].size(); ++j)
            result[j][i] = field[i][j];
    }
    return result;
}

Field make1row(int c, int mines)
{
    Field field = makeField(1, c);
    for (int i = 0; i < mines; ++i)
        field.back()[i] = MINE;
    field.back().back() = CLICK;
    return field;
}

/// @param spaces Must be even and not less than 4.
/// spaces / 2 <= c.
Field make2rows(int r, int c, int spaces)
{
    assert(spaces % 2 == 0 && spaces >= 4);
    Field field = makeField(r, c, MINE);
    const int spaceCols = spaces / 2;
    assert(spaceCols <= c);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < spaceCols; ++j)
            field[i][j] = SPACE;
    }
    field.front().front() = CLICK;
    return field;
}

/// newR == newC, mines == newR - 1
Field makePyramid(int r, int c, int newR)
{
    assert(newR > 3);
    Field field = makeField(r, c, MINE);
    for (int i = 0; i < newR; ++i) {
        for (int j = 0; j < newR; ++j) {
            if ((i == newR - 1 && j > 1)
                    ||
                    (j == newR - 1 && i == newR - 2)
               ) {
                continue;
            }
            field[i][j] = SPACE;
        }
    }
    field.front().front() = CLICK;
    return field;
}

/// mines < newC - 1
Field makeTopSpace(int r, int c, int newR, int newC, int mines)
{
    Field field = makeField(r, c, MINE);
    for (int i = 0; i < newR; ++i) {
        for (int j = 0; j < newC; ++j) {
            if (i == newR - 1 && j > newC - 1 - mines)
                continue;
            field[i][j] = SPACE;
        }
    }
    field.front().front() = CLICK;
    return field;
}

bool fit(const int r, const int c, int mines, Field & field)
{
    if (r == 1) {
        field = make1row(c, mines);
        return true;
    }
    if (c == 1) {
        field = transpose(make1row(r, mines));
        return true;
    }
    const int spaces = r * c - mines;
    if (spaces == 1) {
        field = makeField(r, c, MINE);
        field.back().back() = CLICK;
        return true;
    }
    const std::array<int, 4> impossibleSpaces = {{ 2, 3, 5, 7 }};
    if (find(impossibleSpaces.begin(), impossibleSpaces.end(), spaces)
            != impossibleSpaces.end()) {
        return false;
    }

    if (spaces == 4) {
        field = make2rows(r, c, spaces);
        return true;
    }

    if (spaces == 6) {
        if (c == 2) // r > 2
            field = transpose(make2rows(c, r, spaces));
        else        // c > 2
            field = make2rows(r, c, spaces);
        return true;
    }

    assert(spaces >= 8);

    if (r == 2 || c == 2) {
        if (spaces % 2 == 0) {
            if (c == 2)
                field = transpose(make2rows(c, r, spaces));
            else
                field = make2rows(r, c, spaces);
            return true;
        }
        return false;
    }

    assert(r > 2 && c > 2);

    int newR = r, newC = c;
    for (int i = 0; i < 2; ++i) {
        while (newR > 3 && mines >= newC) {
            mines -= newC;
            --newR;
        }
        swap(newR, newC);
    }

    assert(newR > 2 && newC > 2 && mines < newR && mines < newC);

    if (newR == newC && mines == newR - 1)
        field = makePyramid(r, c, newR);
    else {
        if (newR > newC)
            field = transpose(makeTopSpace(c, r, newC, newR, mines));
        else
            field = makeTopSpace(r, c, newR, newC, mines);
    }
    return true;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("small.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        cout << "Case #" << cas << ": " << endl;

        int rows, cols, mines;
        cin >> rows >> cols >> mines;
        Field field;
        if (fit(rows, cols, mines, field)) {
            assert(int(field.size()) == rows &&
                   int(field.back().size()) == cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j)
                    std::cout << field[i][j];
                std::cout << endl;
            }
        }
        else
            cout << "Impossible" << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}
