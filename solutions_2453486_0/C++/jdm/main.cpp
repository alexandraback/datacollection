#include <cassert>

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <cstdlib>
using std::abs;

#include <cmath>
using std::sqrt;

#include <algorithm>
using std::transform;
using std::max;
using std::min;

#include <vector>
using std::vector;
#include <set>
using std::set;
using std::multiset;

#include <utility>
using std::pair;
using std::make_pair;

#include <memory>
using std::auto_ptr;

#include <map>
using std::map;

#include <list>
using std::list;
#include <bitset>
using std::bitset;
#include <cstring>
using std::memset;

typedef int64_t Int;

Int T;
string A, B, C, D;

#if 0
// A vaguely useful object
struct Box{
    int x1, y1, x2, y2;
    Box(int px1, int py1, int px2, int py2)
        : x1(max(0,px1)), y1(max(0,py1)), x2(px2), y2(py2) {}

    bool contains(int x, int y) const {
        ////cerr << x1 << "<=" << x << "<" << x2 << ", ";
        ////cerr << y1 << "<=" << y << "<" << y2 << endl; 
        return x >= x1 && x < x2 && y >= y1 && y < y2;
    }
    bool contains(Box b) const {
        return x1 <= b.x1 && y1 <= b.y1 && x2 >= b.x2 && y2 >= b.y2;
    }
    bool intersects(Box b) const {
        if (x1 >= b.x2) return false;
        if (y1 >= b.y2) return false;
        if (b.x1 >= x2) return false;
        if (b.y1 >= y2) return false;
        return true;
    }
    bool operator==(const Box& rhs)  const{
        return x1 == rhs.x1
            && y1 == rhs.y1
            && x2 == rhs.x2
            && y2 == rhs.y2;
    }
    bool operator<(const Box& rhs) const {
        if (x1 < rhs.x1) return true;
        if (x1 > rhs.x1) return false;
        if (y1 < rhs.y1) return true;
        if (y1 > rhs.y1) return false;
        if (x2 < rhs.x2) return true;
        if (x2 > rhs.x2) return false;
        return y2 < rhs.y2;
    }
    Int area() const {
        return (x2 - x1) * (y2 - y1);
    }
    
};

std::ostream& operator<<(std::ostream& os, const Box& b) 
{
    os << "(" << b.x1 << ", " << b.y1 << ", "
        << b.x2 << ", " << b.y2 << ") [" << b.area() << "]";
    return os;
}
#endif

bool game_over;
bool winner(char a, char b, char c, char d)
{
    map<char, int> h;
    h[a]++;
    h[b]++;
    h[c]++;
    h[d]++;
    if (h['.']) game_over = false;
    if (h['X']==4) throw 'X';
    if (h['X']==3 && h['T']==1) throw 'X';
    if (h['O']==4) throw 'O';
    if (h['O']==3 && h['T']==1) throw 'O';
    return false;
}

string answer()
{
    try {
        winner(A[0],A[1], A[2], A[3]) ||
        winner(B[0],B[1], B[2], B[3]) ||
        winner(C[0],C[1], C[2], C[3]) ||
        winner(D[0],D[1], D[2], D[3]) ||
        winner(A[0],B[0], C[0], D[0]) ||
        winner(A[1],B[1], C[1], D[1]) ||
        winner(A[2],B[2], C[2], D[2]) ||
        winner(A[3],B[3], C[3], D[3]) ||
        winner(A[0],B[1], C[2], D[3]) ||
        winner(A[3],B[2], C[1], D[0]);
    } catch (char winner) {
        return winner + string(" won");
    }
    if (game_over) return "Draw";
    return "Game has not completed";
}

int main(int argc, char** argv)
{
    cin >> T;

    string junk;
    for (Int testcase = 1; testcase <= T; ++testcase) {
        game_over=true;
        cin >> A >> B >> C >> D ;

        cout << "Case #" << testcase << ": "
            << answer() << endl;

    }
}
