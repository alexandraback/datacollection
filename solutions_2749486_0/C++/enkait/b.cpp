#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

class Mover {
    public:
    int posx, posy;
    int move;
    string result;
    Mover() {
        posx = 0;
        posy = 0;
        move = 1;
    }
    void makemove(int dir) {
        if (dir == NORTH) {
            result += "N";
            posy += move;
        }
        else if (dir == SOUTH) {
            posy -= move;
            result += "S";
        }
        else if (dir == EAST) {
            posx += move;
            result += "E";
        }
        else if (dir == WEST) {
            posx -= move;
            result += "W";
        }
        move++;
    }
};

int reflect(int dir) {
    if (dir == NORTH) return SOUTH;
    else if (dir == SOUTH) return NORTH;
    else if (dir == EAST) return WEST;
    return EAST;
}

void solve(int cas) {
    int x, y;
    cin >> x >> y;
    Mover mover;
    int dir = EAST;
    while(x != mover.posx) {
        mover.makemove(dir);
        dir = reflect(dir);
    }
    dir = NORTH;
    if (y < mover.move and y > 0) {
        dir = SOUTH;
    }
    while(y != mover.posy) {
        mover.makemove(dir);
        dir = reflect(dir);
    }
    assert(mover.result.size() <= 500);
    cout << "Case #" << cas << ": " << mover.result << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 1;i<=T;i++) solve(i);
    return 0;
}

