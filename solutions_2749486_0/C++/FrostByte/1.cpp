#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <sstream>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

#define fo(a,b,c) for(a = (b); a < (c); a++)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define fn fr
#define forit(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

using namespace std;

template <class T> T abs(T x) { return x < 0 ? -x : x; }
template <class T> inline string to_str(const T& x) { ostringstream s(""); s << x; return s.str(); }

const long double PI = acos(-1.0);

typedef long long ll;
typedef unsigned long long ull;

string moves;
bool fixX, fixY;

enum state
{
    N, E, W, S
}
go, lastMove;

int dist(int a, int b)
{
    if(a * b < 0) return abs(a) + abs(b);
    return abs(a-b);
}

int do_thing(int x, int y, int px, int py, int step)
{

    //cout << "At " << px << ", " << py << endl;

    if(px == x && py == y)
        return 0;

    if(px == x) fixX = false;
    if(py == y) fixY = false;

    if(px + step == x) 
        go = E;

    else if(px - step == x) 
        go = W;

    else if(py + step == y) 
        go = N;

    else if(py - step == y) 
        go = S;

    else if(fixX)
    {
        go = lastMove;
        lastMove = lastMove == W ? E : W;
    }

    else if(fixY)
    {
        go = lastMove;
        lastMove = lastMove == S ? N : S;
    }

    else if(py == y)
    {
        fixX = true;
        lastMove = px > x ? E : W;
        if(dist(px,x) > step) lastMove = lastMove == W ? E : W;
        return do_thing(x, y, px, py, step);
    }

    else 
    {
        fixY = true;
        lastMove = py > y ? N : S;
        if(dist(py,y) > step) lastMove = lastMove == N ? S : N;
        return do_thing(x, y, px, py, step);
    }

    switch(go)
    {
        case N: py += step; moves += 'N'; break;
        case S: py -= step; moves += 'S'; break;
        case E: px += step; moves += 'E'; break;
        case W: px -= step; moves += 'W'; break;
    }

    // cout << "Going " << moves[moves.length()-1] << endl; 

    if(step > 500) 
    {
        // cout << "Ended at " << px << ',' << py << " instead of " << x << ',' << y << endl;
        return 0;
    }
    return do_thing(x, y, px, py, step+1);
}

int main()
{
    int i, t, tt;
    int x, y;

    cin >> tt;

    for(t=1; t<=tt; t++)
    {
        moves = "";
        fixX = fixY = false;

        cin >> x >> y;

        printf("Case #%d: ", t);
        do_thing(x, y, 0, 0, 1);
        cout << moves;
        printf("\n");
    }

    return 0;
}



