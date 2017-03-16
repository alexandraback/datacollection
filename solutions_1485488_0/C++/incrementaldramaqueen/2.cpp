#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <sstream>
#define mst(a,v) memset(a, v, sizeof(a))
#define msk(s,p) for(p=(s-1)&s;p=(p-1)&s)
#define _USE_MATH_DEFINES
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define sz(x) x.size()
using namespace std;

typedef long long ll;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m, h;

double t[200][200];
int f[200][200], c[200][200];

double getNextTime(int x, int y, int xx, int yy, double tm)
{
    if (f[x][y] > c[xx][yy] - 50) return -1;
    if (f[xx][yy] > c[xx][yy] - 50) return -1;
    if (f[xx][yy] > c[x][y] - 50) return -1;
    double ret = tm;
    double curLevel = h - tm * 10;
    if (curLevel < 0) curLevel = 0;
    if (curLevel > c[xx][yy] - 50) ret += (curLevel - c[xx][yy] + 50) / 10;
    double level = h - ret * 10;
    if (ret <= 0) return 0;
    if (level < 0) level = 0;
    if (level - f[x][y] >= 20) ret += 1; else ret += 10;
    //cout << x << " " << y << " " << xx << " " << yy << " " << ret << endl;
    return ret;
}

int main(void)
{
    int t1, tt;
    cin >> t1;
    int i, j;
    fo(tt, t1)
        {
            cin >> h >> n >> m;
            fo(i,n)fo(j,m) cin >> c[i][j];
            fo(i,n)fo(j,m) cin >> f[i][j];

            fo(i,n)fo(j,m) t[i][j] = 100000;
            
            t[0][0] = 0;
            priority_queue < pair< double, pair < int, int> > > q;
            q.push( mp( 0, mp(0, 0) ) );
            while(!q.empty())
                {
                    double time = -q.top().first;
                    int x = q.top().second.first;
                    int y = q.top().second.second;
                    q.pop();
                    if (time > t[x][y]) continue;
                    fo(i,4)
                        {
                            int xx, yy;
                            xx = x + dx[i];
                            yy = y + dy[i];
                            if (xx < 0 || xx >= n) continue;
                            if (yy < 0 || yy >= m) continue;
                            if (t[xx][yy] <= time) continue;
                            //cout << x << " " << y << " " << time << " " << t[xx][yy] << endl;
                            double newTime = getNextTime(x, y, xx, yy, time);
                            if (newTime < 0 || newTime >= t[xx][yy]) continue;
                            t[xx][yy] = newTime;
                            q.push( mp( -t[xx][yy], mp(xx, yy) ) );
                        }
                }
            //cout << t[2][2] << endl;
            cout << "Case #" << tt+1 << ": " << t[n-1][m-1] << endl;
        }
}
