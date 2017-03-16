#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct testcase {
    int r, c, m;
};

vector<testcase*> cases;

bool readFile() {
    std::string line;
    std::ifstream cfile("msin.txt");

    if(cfile.is_open()) {
        getline(cfile, line);
        int num = std::stoi(line);
        for(int i = 0; i < num; i++) {
            getline(cfile, line);
            testcase *loaded = new testcase();
            std::string::size_type sz = 0;
            loaded->r = std::stoi(line, &sz, 0);
            line = line.substr(sz);
            loaded->c = std::stoi(line, &sz, 0);
            line = line.substr(sz);
            loaded->m = std::stoi(line, &sz, 0);

            cases.push_back(loaded);
        }
        cfile.close();
    }
    else return false;

    return true;
}

void writeFile(vector<string*> towrite) {
    ofstream out;
    out.open("minesweeper_out.txt");
    for(unsigned int i = 0; i < towrite.size(); i++) {
        out << *towrite[i];
    }
    out.close();
}

// determines if a point is on the board
bool on(int x, int y, int rows, int cols) {
    return (x >= 0) && (x < rows) && (y >= 0) && (y < cols);
}

// makes a copy of the board
int* getCopy(int *board, int size) {
    int *result = new int[size];
    for(int i = 0; i < size; i++)
        result[i] = board[i];
    return result;
}

// helper function that determines how many squares are open if the currently
// marked squares on the board are adjacent to no mines
int expand(int *board, int rows, int cols) {
    int *copy = getCopy(board, rows*cols);

    // expand left and right
    for(int i = 1; i < rows*cols; i++) {
        if(i % cols != 0)
            copy[i] |= board[i-1];
    }
    for(int i = 1; i < rows*cols; i++) {
        if(i % cols != 0)
            copy[i-1] |= board[i];
    }

    // expand up and down
    int *copy2 = getCopy(copy, rows*cols);
    for(int i = cols; i < rows*cols; i++)
        copy[i] |= copy2[i-cols];
    for(int i = cols; i < rows*cols; i++)
        copy[i-cols] |= copy2[i];

    delete[] copy2;

    // count number of opened squares
    int result = 0;
    for(int i = 0; i < rows*cols; i++) {
        if(copy[i] == 1)
            result++;
    }

    delete[] copy;

    return result;
}

// sets up the board for printing the result
int* expf(int *board, int rows, int cols) {
    int *copy = getCopy(board, rows*cols);

    for(int i = 1; i < rows*cols; i++) {
        if(i % cols != 0)
            copy[i] |= board[i-1];
    }
    for(int i = 1; i < rows*cols; i++) {
        if(i % cols != 0)
            copy[i-1] |= board[i];
    }

    int *copy2 = getCopy(copy, rows*cols);
    for(int i = cols; i < rows*cols; i++)
        copy[i] |= copy2[i-cols];
    for(int i = cols; i < rows*cols; i++)
        copy[i-cols] |= copy2[i];
    delete[] copy2;

    return copy;
}

// perform a recursive depth-first search starting from the clicked square
bool dfs(int *board, int rows, int cols, int x, int y, int open) {
    int test = expand(board, rows, cols);

    if(test == open) // solution found
        return true;
    else if(test > open) // we have too many squares containing 0
        return false;

    // consider all 8 directions
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(on(x+dx, y+dy, rows, cols) && board[(x+dx)*cols+y+dy] == 0) {
                board[(x+dx)*cols+y+dy] = 1;
                if(dfs(board, rows, cols, x+dx, y+dy, open))
                    return true;
                board[(x+dx)*cols+y+dy] = 0;
            }
        }
    }

    return false;
}

int main(int argc, char **argv) {
    readFile();

    vector<string*> towrite;

    for(int i = 0; i < cases.size(); i++) {
        testcase *tc = cases[i];

        int rows = tc->r;
        int cols = tc->c;
        int mines = tc->m;
        // initialize board representation to 0s
        int *board = new int[rows*cols];
        for(int x = 0; x < rows*cols; x++)
                board[x] = 0;

        int open = rows*cols - mines;
        // for recording solution
        bool solved = false;
        int clickx = -1;
        int clicky = -1;

        for(int j = 0; (j < rows/2 + 1) && !solved; j++) {
            for(int k = 0; k < cols/2 + 1; k++) {
                // set clicked square
                board[j*cols+k] = 1;
                // search
                if(dfs(board, rows, cols, j, k, open)) {
                    // stop searching if solution found
                    solved = true;
                    clickx = j;
                    clicky = k;
                    break;
                }
                board[j*cols+k] = 0;
            }
        }

        stringstream stream;

        stream << "Case #" << i+1 << ":" << endl;

        if(!solved) {
            // special case
            if(open == 1) {
                for(int m = 0; m < rows; m++) {
                    for(int n = 0; n < cols; n++) {
                        if(m == 0 && n == 0)
                            stream << "c";
                        else
                            stream << "*";
                    }
                    stream << endl;
                }
            }
            else
                stream << "Impossible" << endl;
        }
        else {
            board = expf(board, rows, cols);
            for(int m = 0; m < rows; m++) {
                for(int n = 0; n < cols; n++) {
                    if(m == clickx && n == clicky)
                        stream << "c";
                    else if(board[m*cols+n])
                        stream << ".";
                    else
                        stream << "*";
                }
                stream << endl;
            }
        }

        string *result = new string( stream.str() );
        towrite.push_back(result);
        delete board;
    }

    writeFile(towrite);

    return 0;
}
