#include <iostream>
#include <algorithm>
#include <cassert>


bool badOminoExists(int x, int r, int c) {
    assert(1 <= x && x <= 20);
    assert(1 <= r && r <= 20);
    assert(1 <= c && c <= 20);
    
    if ((r * c) % x != 0) {
        return true; // we just can't fill grid. Any X-omino is bad.
    }
    if (x >= 7) {
        return true; // ###
                     // # #
                     // ##  we can isolate single cell.
    }
    if (x <= 2) {
        return false;
    }
    if (r > c) {
        std::swap(r, c); // r <= c now
    }
    if (x == 3) {
        if (r == 1) {
            return true; // #
                         // ##
        } else { // c >= r > 1
            return false;
        }
    }
    if (x == 4) {
        if (c < 4) {
            return true; // ####
        }
        if (r == 1) {
            return true; // ##
                         // ##
        }
        if (r == 2) {
            return true; //  ##
                         // ##  left part size is 1 or 3 modulo 4
        }
        // Any 4-omino can be placed into 3x4 filled grid (prove by hand)
        // Any grid with 3<=r<=c, (r*c % 4) == 0 can be covered by 3x4, 2x2 and 1x4
        return false;
    }
    if (x == 5) {
        if (c < 5) {
            return true; // #####
        }
        if (r <= 2) {
            return true; //  #
                         // ###
                         //  #
        }
        if (r == 3) { // c == 5, 10, 15, 20, ...
            if (c == 5) {
                return true; // ##
                             //  ##
                             //   # left part size is 3,6 or 9
            }
            // ##   <-- it can be placed into 3x10 grid. So, 3x15,3x20,... can
            //  ##      be filled with 3x5 and 3x10.
            //   ##
            return false;
        }
        // Any 5-omino can be placed into 4x5 filled grid (prove by hand)
        // Any grid with 4<=r<=c, (r*c % 5) == 0 can be covered by 4x5 or 1x5
        return false;
    }
    if (x == 6) {
        if (c < 6) {
            return true; // ######
        }
        if (r <= 2) {
            return true; // #
                         // ##
                         // ###
        }
        if (r == 3) {
            return true; //  ##
                         //  #
                         // ### left part size is 2 modulo 3, and we can't rotate it by pi/2
        }
        // Any 6-omino can be placed into 4x6 filled grid (prove by hand)
        // Any grid with 4<=r<=c, (r*c % 6) == 0 can be covered by 4x6, 2x3 and 1x6
        return false;
    }
    assert(false);
    return false;
}

int main() {
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    
    int T, x, r, c;
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        std::cin >> x >> r >> c;
        std::cout << "Case #" << t << ": " << (badOminoExists(x,r,c) ? "RICHARD" : "GABRIEL") << std::endl;
    }
    return 0;
}