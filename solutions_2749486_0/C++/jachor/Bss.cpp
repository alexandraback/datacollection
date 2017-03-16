#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

string solve(int x, int y) {
    if(x==0 && y==0)
        return "";
    string R;
    while(x > 0) { R += "WE"; x--; }
    while(x < 0) { R += "EW"; x++; }
    while(y > 0) { R += "SN"; y--; }
    while(y < 0) { R += "NS"; y++; }
    return R.substr(1);
}

int main() {
    int _T; scanf("%d", &_T);
    for(int _Ti=1; _Ti<=_T; _Ti++) {
        int x, y;
        scanf("%d%d", &x, &y);
        string r = solve(x,y);
        fprintf(stderr, "(%d,%d) -> %d\n", x,y, r.size());
        printf("Case #%d: %s\n", _Ti, r.c_str());
    }
}

