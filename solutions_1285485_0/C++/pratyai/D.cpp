#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int H,W,D;
vector<string>g;

int cnt(int x2, int y2, int w, int h, int lim)
{
    set<pair<int,int> >oc;
    //cout<<x<<' '<<y<<' '<<w<<' '<<h<<' '<<lim<<endl;
    int R = 0;
    int r, _x, _y;
    for (int i=1; ; ++i)
    {
        if (i&1) _x = x2 + (i-1)*w;
        else _x = i*w;
        bool again = false;
        for (int j=1; ; ++j)
        {
            if (j&1) _y = y2 + (j-1)*h;
            else _y = j*h;
            int _g = __gcd(_x,_y);
            assert(_g);
            pair<int,int> xy(_x/_g,_y/_g);
            r = _x*_x+_y*_y;
            //cout<<i<<' '<<_x<<' '<<j<<' '<<_y<<' '<<r<<endl;
            if (r>lim) break;
            if (oc.find(xy)!=oc.end()) continue;
            oc.insert(xy);
            again = true;
            ++R;
        }
        if (!again) break;
    }
    return R;
}

int main()
{
    //freopen("in.txt", "rt", stdin);
    freopen("D-small-attempt4.in", "rt", stdin);
    freopen("D-small-attempt4.out", "wt", stdout);
    int T;
    cin>>T;
    for (int cas=1; cas<=T; ++cas)
    {
        cin>>H>>W>>D;
        g.resize(H);
        int ox, oy;
        for (int i=0; i<H; ++i)
        {
            cin>>g[i];
            for (int j=0; j<W; ++j) if (g[i][j]=='X') oy = i-1, ox = j-1;
        }
        int h = H-2, w = W-2;
        int _C = 0;
        _C += cnt(2*ox+1,2*oy+1,w,h,D*D);
        _C += cnt(2*w-2*ox-1,2*oy+1,w,h,D*D);
        _C += cnt(2*w-2*ox-1,2*h-2*oy-1,w,h,D*D);
        _C += cnt(2*ox+1,2*h-2*oy-1,w,h,D*D);
        if (2*ox+1<=D) ++_C;
        if (2*oy+1<=D) ++_C;
        if (2*w-2*ox-1<=D) ++_C;
        if (2*h-2*oy-1<=D) ++_C;
        printf("Case #%d: %d\n", cas, _C);
    }
    return 0;
}
