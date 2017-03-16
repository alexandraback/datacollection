#include <cstdio>
#include <cstdlib>
#include <cstring>

int width = 1;
int height = 1;
int mines;
int numCells = 1;
char* solutionData = nullptr;

struct pos {
    pos() { x = y = 0; }
    pos(int _x, int _y) { x = _x; y = _y; }
    int x;
    int y;
};

char* cell(pos p, char* data)
{
    if (p.x < 0 || p.x >= width) return nullptr;
    if (p.y < 0 || p.y >= height) return nullptr;
    return &data[p.y*width + p.x];
}

pos neighbor(pos p, int dir) {
    switch (dir) {
        case 0: return pos(p.x + 1, p.y    );
        case 1: return pos(p.x + 1, p.y + 1);
        case 2: return pos(p.x    , p.y + 1);
        case 3: return pos(p.x - 1, p.y + 1);
        case 4: return pos(p.x - 1, p.y    );
        case 5: return pos(p.x - 1, p.y - 1);
        case 6: return pos(p.x    , p.y - 1);
        case 7: return pos(p.x + 1, p.y - 1);
    }
    return pos();
}

void fillWithMines(char* data) {
    for (int i = 0; i < numCells; ++i) data[i] = '*';
    
}

void recurse(pos p, const char* parentdata, int numPossibleMines) {
    if (solutionData != nullptr) return; // already done
    
    // Make a copy of data && numPossibleMines
    char* data = new char[numCells];
    memcpy(data, parentdata, numCells);
    
    pos cand[8];
    int numCand = 0;
    
    for (int d = 0; d < 8; ++d) {
        pos np = neighbor(p, d);
        char* n = cell(np, data);
        if (n != nullptr && *n == '*') {
            *n = '.';
            numPossibleMines--;
            cand[numCand++] = np;
        }
    }

    if (numPossibleMines == mines) {
        solutionData = data;
        return;
    } else if (numPossibleMines > mines) {
        for (int i = 0; i < numCand; ++i) {
            recurse(cand[i], data, numPossibleMines);
        }
    } else {
        // went under the limit -> just exit
    }
    delete[] data;
}

void solve(int rows, int columns, int _mines) {
    width = columns;
    height = rows;
    numCells = rows*columns;
    mines = _mines;
    
    char* data = new char[numCells];
    
    solutionData = nullptr;
    // try starting at each cell...
    pos p;
    for (p.y = 0; p.y < rows; ++p.y) {
        for (p.x = 0; p.x < columns; ++p.x) {
            int numPossibleMines = numCells;
            
            // Fill the full field with mines
            fillWithMines(data);
            
            *cell(p, data) = 'c'; // Set starting point
            numPossibleMines--;
            if (numPossibleMines == mines) {
                solutionData = data;
                break;
            }
            recurse(p, data, numPossibleMines);
        }
        if (solutionData != nullptr) break;
    }
    
    if (solutionData != nullptr) {
        pos p;
        for (p.y = 0; p.y < rows; ++p.y) {
            for (p.x = 0; p.x < columns; ++p.x) {
                printf("%c", *cell(p, solutionData));
            }
            printf("\n");
        }
    } else {
        printf("Impossible\n");
    }
    if (solutionData != data) {
        delete[] data;
    }
    delete[] solutionData;
}

int main(int argc, const char * argv[])
{
    int numCases = 0;

    scanf("%d\n", &numCases);
    
    for (int count = 1; count <= numCases; ++count) {
        int a, b, c;
        scanf("%d %d %d\n", &a, &b, &c);
        printf("Case #%d:\n", count);
        solve(a, b, c);
    }
    return 0;
}

