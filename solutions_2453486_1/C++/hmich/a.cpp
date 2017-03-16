#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 4996 4800 )
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "a.in" );
ofstream out( "a.out" );

string field[4];

bool check(int x, int y, int dx, int dy, char ch) {
    for (int i = 0; i < 4; ++i, x += dx, y += dy)
        if (field[x][y] != ch && field[x][y] != 'T')
            return false;
    return true;
}

bool won(char ch) {
    for (int i = 0; i < 4; ++i) {
        if (check(i, 0, 0, 1, ch))
            return true;
        if (check(0, i, 1, 0, ch))
            return true;
    }
    if (check(0, 0, 1, 1, ch))
        return true;
    return check(0, 3, 1, -1, ch);
}

int main() {
    int ntest;
    in >> ntest;
    for (int test = 1; test <= ntest; ++test) {
        getline(in, field[0]);
        for (int i = 0; i < 4; ++i)
            getline(in, field[i]);
        out << "Case #" << test << ": ";
        if (won('X'))
            out << "X won";
        else if (won('O'))
            out << "O won";
        else if (std::any_of(field, field + 4, [](string s) { return s.find('.') != string::npos; } ))
            out << "Game has not completed";
        else
            out << "Draw";
        out << "\n";
    }
    return 0;
}