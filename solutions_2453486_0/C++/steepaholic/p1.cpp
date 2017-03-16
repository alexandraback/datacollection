#include <iostream>
#include <string>
using namespace std;

struct coords { int x; int y; };
struct line { coords p1; coords p2; coords inc; };
        
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        string strlines[4];
        for(int j = 0; j < 4; ++j)
        {
            cin >> strlines[j];
        }
        
        enum { NUM_LINES = 10 };
        line lines[NUM_LINES] = { { { 0, 0 }, { 0, 3 }, { 0, 1 } },
                           { { 1, 0 }, { 1, 3 }, { 0, 1 } },
                           { { 2, 0 }, { 2, 3 }, { 0, 1 } },
                           { { 3, 0 }, { 3, 3 }, { 0, 1 } },
                           { { 0, 0 }, { 3, 0 }, { 1, 0 } },
                           { { 0, 1 }, { 3, 1 }, { 1, 0 } },
                           { { 0, 2 }, { 3, 2 }, { 1, 0 } },
                           { { 0, 3 }, { 3, 3 }, { 1, 0 } },
                           { { 0, 0 }, { 3, 3 }, { 1, 1 } },
                           { { 0, 3 }, { 3, 0 }, { 1, -1 } } };
        bool hadDot = false;
        bool done = false;
        cout << "Case #" << (i + 1) << ": ";
        for(int j = 0; j < NUM_LINES; ++j)
        {
            line &l = lines[j];
            int x = l.p1.x, y = l.p1.y;
            bool allx = true;
            bool allo = true;
            for(int inc = 0; inc < 4; ++inc)
            {
                char pt = strlines[x].at(y);
                allx = allx && (pt == 'X' || pt == 'T');
                allo = allo && (pt == 'O' || pt == 'T');
                hadDot = hadDot || (pt == '.');
                x += l.inc.x;
                y += l.inc.y;
            }
            if(allx)
            {
                cout << "X won\n";
                done = true;
                break;
            }
            else if(allo)
            {
                cout << "O won\n";
                done = true;
                break;
            }
        }
        if(!done && hadDot)
        {
            cout << "Game has not completed\n";
        }
        else if(!done)
        {
            cout << "Draw\n";
        }
    }
}