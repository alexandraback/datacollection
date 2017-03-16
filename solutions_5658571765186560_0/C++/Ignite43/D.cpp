#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool gariel(int X, int R, int C) {
       if (R * C % X != 0 || X >= 7 || (X+1) / 2 > min(R,C) || X > max(R,C)) {
               return false;
       }

       if (X <= 3)
               return true;
       if (X == 4)
               return min(R,C) > 2;
       if (X == 5)
               return !(min(R, C) == 3 && max(R, C) == 5);
       if (X == 6)
               return min(R, C) > 3;
       return false;
}

int main(int argc, char *args[]) {
        if (argc == 2 && strcmp(args[1], "small") == 0) {
                freopen("D-small-attempt0.in", "rt", stdin);
                freopen("D-small.out", "wt", stdout);
        }
        else if (argc == 2 && strcmp(args[1], "large") == 0) {
                freopen("D-large.in", "rt", stdin);
                freopen("D-large.out", "wt", stdout);
        }
        else {
                freopen("d.txt", "rt", stdin);
        }

        int N;
        cin >> N;
        for (int i=0; i<N; ++i) {
                int X, R, C;
                cin >> X >> R >> C;
                cout << "Case #" << i+1 << ": " 
                     << (gariel(X, R, C) ? "GABRIEL" : "RICHARD") << endl;
        }

        return 0;
}
