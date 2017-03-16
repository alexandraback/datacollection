#include <algorithm>
#include <iostream>
#include <fstream>
#include <windows.h>

#define SUBMIT 0
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

#define lose "RICHARD"
#define win "GABRIEL"

using namespace std;

ifstream fin("D-small.in");
ofstream fout("D-small.out");

int T;
int x, R, C;
string answer;

int main()
{
    cin >> T;

    for (int test=1; test<=T; test ++) {
        cin >> x >> R >> C;

        if (R > C) swap(R, C);   /// ensure R <= C

        /// GENERAL

        if (x > R*C) {
            answer = lose;
        } else if (x > C) {
            answer = lose;
        } else if ((R*C)%x != 0) {
            answer = lose;
        }

        /// DETAILS

        else if (x == 1 || x == 2) {
            answer = win;
        } else if (x == 3) {
            if (R == 1) answer = lose;
            else answer = win;
        } else if (x == 4) {
            if (R == 1 || R == 2) answer = lose;
            else answer = win;
        }

        cout << "Case #" << test << ": " << answer << endl;

    }

}
