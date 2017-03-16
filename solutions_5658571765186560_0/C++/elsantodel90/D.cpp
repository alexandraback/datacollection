#include <iostream>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

#define esta(x,c) ((c).find(x) != (c).end())

typedef long long tint;

const string RICHARD = "RICHARD";
const string GABRIEL = "GABRIEL";

int main()
{
    int TT; cin >> TT;
    forn(tt,TT)
    {
        int X,R,C; cin >> X >> R >> C;
        if (R < C) swap(R,C); // R >= C
        string ret;
        // Careful exhaustive pencil and paper analysis yields this conditions.
        if (X >= 7) ret = RICHARD;
        else if (X == 1) ret = GABRIEL;
        else if (X == 2) ret = ((R*C) % 2 == 0) ? GABRIEL : RICHARD;
        else if (X == 3) ret = ((R*C) % 3 == 0 && R >= 3 && C >= 2) ? GABRIEL : RICHARD;
        else if (X == 4) ret = ((R*C) % 4 == 0 && R >= 4 && C >= 3) ? GABRIEL : RICHARD;
        else if (X == 5) ret = ((R*C) % 5 == 0 && ((R >= 10 && C >= 3) || (R >= 5 && C >= 4))) ? GABRIEL : RICHARD;
        else if (X == 6) ret = ((R*C) % 6 == 0 && R >= 6 && C >= 4) ? GABRIEL : RICHARD;
        else assert(false);
        cout << "Case #" << tt+1 << ": " << ret << endl;
    }
    return 0;
}
