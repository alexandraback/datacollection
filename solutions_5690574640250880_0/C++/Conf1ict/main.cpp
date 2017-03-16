#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

ifstream input ("input.txt",  ios_base::in);
ofstream output("output.txt", ios_base::out);

void solveCase()
{
    int r, c, m;
    input >> r >> c >> m;
    output.put('\n');

    int ec = r * c - m;

    if(r == 1 || c == 1) {
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(i == 0 && j == 0) {
                    output.put('c');
                    --ec;
                } else if(ec > 0) {
                    output.put('.');
                    --ec;
                } else
                    output.put('*');
            }
            output.put('\n');
        }
        return;
    }

    char data[50][50];
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            data[i][j] = '.';

    for(int i = 0; i < r-2; ++i)
        for(int j = 0; j < c-2; ++j)
            if(m > 0 && !(i == r-3 && j == c-3)) {
                data[i][j] = '*';
                --m;
            }

    for(int i = 0; i < r-3; ++i) {
        if(m > 1) {
            data[i][c-2] = '*';
            data[i][c-1] = '*';
            m -= 2;
        }
    }

    for(int i = 0; i < c-3; ++i) {
        if(m > 1) {
            data[r-2][i] = '*';
            data[r-1][i] = '*';
            m -= 2;
        }
    }

    if(m > 0) {
        if(r > 2 && c > 2) {
            if(m > 0) {
                data[r-3][c-3] = '*';
                --m;
            }
        }
        if(r > 2 && m > 1) {
            data[r-3][c-2] = '*';
            data[r-3][c-1] = '*';
            m -= 2;
        }
        if(c > 2 && m > 1) {
            data[r-2][c-3] = '*';
            data[r-1][c-3] = '*';
            m -= 2;
        }
    }

    if(m == 3) {
        data[r-2][c-2] = '*';
        data[r-2][c-1] = '*';
        data[r-1][c-2] = '*';
        m -= 3;
    }

    if(m != 0) {
        output << "Impossible" << endl;
        return;
    }

    data[r-1][c-1] = 'c';
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            output.put(data[i][j]);
        output << '\n';
    }
}

int main()
{
    int n;
    input >> n;

    for(int i = 1; i <= n; ++i)
    {
        output << "Case #" << i << ": ";
        solveCase();
        //output << endl;
    }
}
