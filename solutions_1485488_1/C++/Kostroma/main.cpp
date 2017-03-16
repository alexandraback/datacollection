#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int timer=1;
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while (t--)
        solve(), ++timer;
    return 0;
}

//#define int li

int h, n, m;
int f[200][200], c[200][200];

set < pair <int, pair <int, int> > > a;
unsigned int d[200][200];

void solve()
{  
    cin>>h>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>c[i][j];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>f[i][j];
    a.clear();
    memset (d, -1, sizeof d);
    d[0][0]=0;
    a.insert( mp( 0, mp(0, 0) ) );
    while ( !a.empty() )
    {
        pair < int, pair <int, int> > curr=*a.begin();
        pair <int, int> cur=curr.second;
        int dist=curr.first;
        a.erase(a.begin());
        pair <int, int> now;
        
        //cout<<cur.first<<' '<<cur.second<<' '<<dist<<endl;
        
        now=mp(cur.first-1, cur.second);
        if (now.first>=0 && now.second>=0 && now.first<n && now.second<m)
        {
            if (c[now.first][now.second]-f[now.first][now.second]>=50 && c[cur.first][cur.second]-f[now.first][now.second]>=50 && c[now.first][now.second]-f[cur.first][cur.second]>=50)
            {
                int H=h-dist;
                int newdist;
                if ( c[now.first][now.second]-H>=50 )
                {
                    if (dist==0)
                        newdist=0;
                    else
                        if (H-f[cur.first][cur.second]>=20)
                            newdist=dist+10;
                        else
                            newdist=dist+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase(mp ( d[now.first][now.second], now ));
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
                else
                {
                    int lev=c[now.first][now.second]-50;
                    if (lev-f[cur.first][cur.second]>=20)
                        newdist=dist+H-lev+10;
                    else
                        newdist=dist+H-lev+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase( mp ( d[now.first][now.second], now ) );
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
            }
        }
        
        now=mp(cur.first+1, cur.second);
        if (now.first>=0 && now.second>=0 && now.first<n && now.second<m)
        {
            if (c[now.first][now.second]-f[now.first][now.second]>=50 && c[cur.first][cur.second]-f[now.first][now.second]>=50 && c[now.first][now.second]-f[cur.first][cur.second]>=50)
            {
                int H=h-dist;
                int newdist;
                if ( c[now.first][now.second]-H>=50 )
                {
                    if (dist==0)
                        newdist=0;
                    else
                        if (H-f[cur.first][cur.second]>=20)
                            newdist=dist+10;
                        else
                            newdist=dist+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase(mp ( d[now.first][now.second], now ));
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );                        
                    }
                }
                else
                {
                    int lev=c[now.first][now.second]-50;
                    if (lev-f[cur.first][cur.second]>=20)
                        newdist=dist+H-lev+10;
                    else
                        newdist=dist+H-lev+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase( mp ( d[now.first][now.second], now ) );
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
            }
        }
        
        now=mp(cur.first, cur.second-1);
        if (now.first>=0 && now.second>=0 && now.first<n && now.second<m)
        {
            if (c[now.first][now.second]-f[now.first][now.second]>=50 && c[cur.first][cur.second]-f[now.first][now.second]>=50 && c[now.first][now.second]-f[cur.first][cur.second]>=50)
            {
                int H=h-dist;
                int newdist;
                if ( c[now.first][now.second]-H>=50 )
                {
                    if (dist==0)
                        newdist=0;
                    else
                        if (H-f[cur.first][cur.second]>=20)
                            newdist=dist+10;
                        else
                            newdist=dist+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase(mp ( d[now.first][now.second], now ));
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
                else
                {
                    int lev=c[now.first][now.second]-50;
                    if (lev-f[cur.first][cur.second]>=20)
                        newdist=dist+H-lev+10;
                    else
                        newdist=dist+H-lev+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase( mp ( d[now.first][now.second], now ) );
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
            }
        }
        
        now=mp(cur.first, cur.second+1);
        if (now.first>=0 && now.second>=0 && now.first<n && now.second<m)
        {
            if (c[now.first][now.second]-f[now.first][now.second]>=50 && c[cur.first][cur.second]-f[now.first][now.second]>=50 && c[now.first][now.second]-f[cur.first][cur.second]>=50)
            {
                int H=h-dist;
                int newdist;
                if ( c[now.first][now.second]-H>=50 )
                {
                    if (dist==0)
                        newdist=0;
                    else
                        if (H-f[cur.first][cur.second]>=20)
                            newdist=dist+10;
                        else
                            newdist=dist+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase(mp ( d[now.first][now.second], now ));
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
                else
                {
                    int lev=c[now.first][now.second]-50;
                    if (lev-f[cur.first][cur.second]>=20)
                        newdist=dist+H-lev+10;
                    else
                        newdist=dist+H-lev+100;
                    if (d[now.first][now.second]>newdist)
                    {
                        a.erase( mp ( d[now.first][now.second], now ) );
                        d[now.first][now.second]=newdist;
                        a.insert( mp ( newdist, now ) );
                    }
                }
            }
        }
    }
    
    
    cout<<"Case #"<<timer<<": ";
    ld ans=(ld)d[n-1][m-1];
    ans/=10.0;
    printf ("%.10lf", ans);
    cout<<endl;
}
