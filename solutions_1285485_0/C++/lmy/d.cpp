#include <cstdio>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

char cell[30][31];

template <class T>
inline T gcd(T a, T b)
{
    if(a < 0) return gcd(-a, b);
    if(b < 0) return gcd(a, -b);
    return (b==0)?a:gcd(b, a%b);
}

set < pair<int, int> > res;

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int no = 1; no <= t; no++)
    {
        int h, w, d;
        int x, y;
        res.clear();
        scanf("%d %d %d", &h, &w, &d);
        for (int i = 0; i < h; i++)
            scanf("%s", cell[i]);
        for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            if (cell[i][j] == 'X')
            {
                x = 2*i-1;
                y = 2*j-1;
                //printf("%d %d\n", x, y);
            }
        }
        for (int m = -(d/(2*(h-2))+1); m <=(d/(2*(h-2))+1); m++)
        for (int n = -(d/(2*(w-2))+1); n <=(d/(2*(w-2))+1); n++)
        {
            for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)
            {
                int px = 2*2*m*(h-2) + i*x;
                int py = 2*2*n*(w-2) + j*y;
                if (px==x&&py==y) continue;
                //printf("%d %d\n", px, py);
                int xx = px-x;
                int yy = py-y;
                if (xx*xx+yy*yy <= 2*2*d*d)
                {

                    int g = gcd(xx, yy);
                    res.insert(make_pair(xx/g, yy/g));
                }
            }
        }
        //set<pair<int, int> >::iterator it;
        //for ( it=res.begin() ; it != res.end(); it++ )
            //cout << " " << (*it).first << " " << (*it).second <<endl;
        printf("Case #%d: %d\n", no, res.size());
    }
}
