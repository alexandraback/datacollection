#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long int64;
typedef vector<int>::iterator it;

const int oo = 0x3f3f3f3f;
const int Size = 4;

inline bool Winner(const vector< vector<int> > &Values) {
    for (int i = 0; i < Size; ++i) {
        int sum = 0;
        for (int j = 0; j < Size; ++j)
            sum += Values[i][j];
        if (sum == 4)
            return true;
    }
    for (int j = 0; j < Size; ++j) {
        int sum = 0;
        for (int i = 0; i < Size; ++i)
            sum += Values[i][j];
        if (sum == 4)
            return true;
    }
    int diagonalSum1 = 0, diagonalSum2 = 0;
    for (int i = 0; i < Size; ++i) {
        diagonalSum1 += Values[i][i];
        diagonalSum2 += Values[i][Size - 1 - i];
    }
    return (diagonalSum1 == 4 || diagonalSum2 == 4);
}

int main() {
    ifstream in("input.in");
    ofstream out("output.out");
    int Tests; in >> Tests;
    for (int t = 1; t <= Tests; ++t) {
        vector<string> Table = vector<string>(Size, "");
        for (int i = 0; i < Size; ++i)
            in >> Table[i];
        vector< vector<int> > X = vector< vector<int> >(Size, vector<int>(Size, 0));
        vector< vector<int> > O = vector< vector<int> >(Size, vector<int>(Size, 0));
        bool Empty = false;
        for (int i = 0; i < Size; ++i) {
            for (int j = 0; j < Size; ++j) {
                if (Table[i][j] == 'X' || Table[i][j] == 'T')
                    ++X[i][j];
                if (Table[i][j] == 'O' || Table[i][j] == 'T')
                    ++O[i][j];
                Empty |= (Table[i][j] == '.');
            }
        }
        out << "Case #" << t << ": ";
        if (Winner(X)) {
            out << "X won\n";
            continue;
        }
        if (Winner(O)) {
            out << "O won\n";
            continue;
        }
        if (Empty) {
            out << "Game has not completed\n";
            continue;
        }
        out << "Draw\n";
    }
    in.close();
    out.close();
    return 0;
}
