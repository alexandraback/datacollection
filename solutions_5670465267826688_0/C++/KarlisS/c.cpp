#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int MXL = 16*1024;
char txt[MXL];
int l;
ll x;


struct V {
    int v;
    V():v(0){};
    V(char c)
    {
        switch (c)
        {
            case '1': v = 1; break;
            case 'i': v = 2; break;
            case 'j': v = 3; break;
            case 'k': v = 4; break;
            default: v = 0; break;
        }
    }
    V(int v):v(v){}
    bool operator==(V b) { return v == b.v; }
};
static V operator*(V a, V b)
{
    static const int ml[5][5]={
        {0, 0, 0, 0, 0},
        {0, 1, 2, 3, 4},
        {0, 2,-1, 4,-3},
        {0, 3,-4,-1, 2},
        {0, 4, 3,-2,-1}
    };
    int r=ml[abs(a.v)][abs(b.v)];
    if ((a.v < 0) != (b.v < 0)) r = -r;
    return {r};
}

V val[MXL];
V pref[MXL];

bool solve()
{
    for (int i=0; i<l; i++) val[i] = V(txt[i]);
    pref[0] = val[0];
    for (int i=1; i<l; i++) pref[i] = pref[i-1]*val[i];
//    for (int i=0; i<l; i++) printf("%d %d %d\n", i, val[i].v, pref[i].v);
    V ps = pref[l-1];
    if (!((ps.v == -1) ||
          (ps.v != 1 && x%4 == 2)))
    {
    //    cout << "sb\n";
        return false;
    }

    //cout << "SG \n";

    ii posI{-1, -1};
    V blp; 
    blp = {1};
    for (int bl=0; bl<min(4LL, x); bl++)
    {
        for (int i=0; i<l; i++)
        {
     //       printf("bl:%d %d | %d %d %d\n", bl, i, blp.v, pref[i].v, (blp*pref[i]).v);
            if (posI.first == -1 &&
                blp * pref[i] == V('i'))
            {
                posI = {bl, i};
            }

        }
        blp = blp*ps;
    }
    if (posI.first == -1) return false;
    //cout << "fi\n";

    blp = {1};
    for (int bl=0; bl<min(8LL, x); bl++)
    {
        for (int i=0; i<l; i++)
        {
            if (blp * pref[i] == V('k') &&
                posI < ii(bl, i))
            {
                return true;
            }

        }
        blp = blp*ps;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        scanf("%d %lld", &l, &x);
        scanf("%s", txt);
        printf("Case #%d: %s\n", i, solve() ? "YES" : "NO");
    }
}
