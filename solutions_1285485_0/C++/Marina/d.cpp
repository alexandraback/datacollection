#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;
char mat[32][32];

inline double sqr(double x)
{
    return x * x;
}
double dist2(double x1, double y1, double x2, double y2)
{
    return (sqr(x1-x2) +  sqr(y1-y2));       
}
int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    
    int t, w, h, d, ntest, i, j, lx, cx, lin, col, res;
    double x1, y1, x2, y2;
    
    cin >> ntest;
    for(t = 1; t <= ntest; ++t)
    {
        cin >> h >> w >> d;
        for(i = 0; i < h; ++i)
        {
            cin >> mat[i];
            for(j = 0; j < w; ++j)
                if(mat[i][j] == 'X') lx = i, cx = j;
        }
        
        h -= 2; w -= 2; --lx; --cx;
        x1 = lx + 0.5; y1 = cx + 0.5;
        set<pair<double, bool> > dir;
        for(lin = -d/h - 1; lin <= d/h + 1; ++lin)
            for(col = -d/w - 1; col <= d/w + 1; ++col)
            {
                if(!lin && !col) continue;
                x2 = lin*h; y2 = col*w;
                if(abs(lin) % 2) x2 += h - x1;
                else x2 += x1;
                if(abs(col) % 2) y2 += w - y1;
                else y2 += y1;
                if(dist2(x1, y1, x2, y2) <= d*d)
                {                    
                    double a = ((x1 != x2) ? (double)(y2 - y1) / (x2 - x1) : 1e9);
                    bool b = (x1 > x2) || (x1 == x2 && y1 > y2);
                    dir.insert(make_pair(a, b));
                }
            }
        cout << "Case #" << t << ": " << dir.size() << "\n";
    }
    return 0;
}
