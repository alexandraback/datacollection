#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
//#define DEBUG
using namespace std;

void syntax(char** argv) {
    printf("Syntax: %s <filename>\n", argv[0]);
}

typedef vector<vector<int> > table;
const int MINE=-1;
const int SPACE=-2;
const int CLICK=-3;

void reveal_cells(table& tbl, int r, int c) {
    int cell_value = tbl[r][c];
    if (cell_value >= 0) { // already revealed
       return;
    }
    int row_count = tbl.size();
    int col_count = tbl[0].size();
    int mine_count=0;
    for (int i=-1; i<2 && r+i < row_count; ++i) {
        if (r+i < 0) {
            continue;
        }
        for (int j=-1; j<2 && c+j < col_count; ++j) {
            if ((i==0 and j==0) || c+j<0) {
                continue;
            }
            if (tbl[r+i][c+j] == MINE) {
                ++mine_count;
            }
        }
    }
    tbl[r][c] = mine_count;
    if (mine_count == 0) {
       for (int i=-1; i<2 && r+i < row_count; ++i) {
           if (r+i < 0) {
               continue;
           }
           for (int j=-1; j<2 && c+j < col_count; ++j) {
               if ((i==0 and j==0) || c+j<0) {
                   continue;
               }
               int cell_value = tbl[r+i][c+j];
               if (cell_value < 0) { // not yet revealed
                   reveal_cells(tbl, r+i, c+j);
               }
           }
       }
    }
    return;
}

bool place_mines(table& tbl, int r, int c, int m) {
    if (m==0) return true;
    int mines_placed = 0;
    int x= (r < c ? r : c); 
    int steps[2]={0,1}; // columns then rows
    if (r<c || c==1) {
        // rows then columns
        steps[0]=1;
        steps[1]=0;
    }
    for (int i = 0; i < x; ++i) {
        for (int s=0; s<2; ++s) {
            if (steps[s] == 0) {
                for (int j=i; j<c; ++j) { // populate row
                    if (tbl[i][j] == MINE) {
                        continue;
                    }
                    tbl[i][j] = MINE;
                    ++mines_placed;
                    if (mines_placed == m) {
                        return true;
                    } else {
                        // don't place the last mine leaving just 1 empty cell
                        if (i+1==r-1 && tbl[i+1][j] != MINE) { // just one row below
                            tbl[i+1][j] = MINE;
                            ++mines_placed;
                            if (mines_placed==m) {
                                return true;
                            }
                        }
                        if (mines_placed >= m-2 && j!=c-1 && r!=1) {
                            if (m - mines_placed == 2 && i+2 <= r) { // can fill the line if there is enough space below
                                 if (i+2==r-1 && j+2!=c-1) {
                                    tbl[i+1][j]= MINE;
                                    tbl[i+2][j]= MINE;
                                    mines_placed += 2;
                                    if (mines_placed==m) {
                                        return true;
                                    }
                                 }
                                 continue;
                            } else 
                            if (m - mines_placed == 1 && (j+1 == c-1 || j+1 < c-2) && i+2 <=r) {
                                continue;
                            }
                            break;
                        }
                    }
                }
            }
            if (steps[s] == 1) {
                for (int j=i; j<r; ++j) { // populate column
                    if (tbl[j][i] == MINE) {
                        continue;
                    }
                    tbl[j][i] = MINE;
                    ++mines_placed;
                    if (mines_placed == m) {
                        return true;
                    } else {
                        // don't place the last mine leaving just 1 empty cell
                        if (i+1==c-1 && tbl[j][i+1] != MINE) {
                            tbl[j][i+1] = MINE;
                            ++mines_placed;
                            if (mines_placed==m) {
                                return true;
                            }
                        }
                        if (mines_placed >= m-2 && j!=r-1 && c!=1) {
                           if (m - mines_placed == 2 && i+2 <= c) { // can fill the row if there is enough on the right
                                 if (i+2==c-1 && j+2!=r-1) {
                                    tbl[j][i+1] = MINE;
                                    tbl[j][i+2] = MINE;
                                    mines_placed += 2;
                                    if (mines_placed==m) {
                                        return true;
                                    }
                                 }
                                 continue;
                           } else 
                           if (m - mines_placed == 1 && (j+1 == r-1 || j+1 < r-2) && i+2 <=c) {
                                continue;
                           }
                           break;
                        }
                    }
                }
            }
        }
    }
    if (mines_placed != m) {
        return false;
    }
    return true;
}

void print_result(int r, int c, int m) {
    table tbl(r, vector<int>(c, SPACE));
    if (!place_mines(tbl, r, c, m)) {
        cout << "Impossible" << endl;
        return;
    }
    if (tbl[r-1][c-1] == SPACE) {
        reveal_cells(tbl, r-1, c-1);
        tbl[r-1][c-1] = CLICK;
    }
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            if (tbl[i][j] == SPACE) {
                cout << "Impossible" << endl;
                #ifndef DEBUG
                return;
                #endif
            }
        }
    }
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            char c;
            if (tbl[i][j] == MINE) c = '*';
            else if (tbl[i][j] == SPACE) c = '_';
            else if (tbl[i][j] == CLICK) c = 'c';
            else c = '.';
            cout << c;
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        syntax(argv);
        return 1;
    }
    ifstream in;
    in.open(argv[1], ios::in);
    if (!in) {
        cerr << "Could not open file " << argv[1] << endl;
        return 1;
    }
    int numTestCases;
    in >> numTestCases;
    for (int i=0; i<numTestCases; ++i) {
        int r,c,m;
        in >> r >> c >> m;
        cout << "Case #" << i+1 << ":" << endl;
        print_result(r,c,m);
    }
    in.close();
    return 0;
}
