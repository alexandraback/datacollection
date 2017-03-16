#include<cmath>
#include<cstdio>
#include<fstream>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<utility>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<cassert>

#define f(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define BIG 2000000000
#define inp(x) scanf("%d",&(x))
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,bool> pib;
typedef long long lol;
typedef unsigned long long ull;
typedef pair<lol,lol> pll;

ifstream fin;
ofstream fout;
int c[102][102];
int f[102][102];
int t[102][102];
bool vis[102][102];
int mv[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    fin.open("B.in");
    fout.open("B.out");
    
    int cas;
    int h,n,m;
    int xc,yc;
    int tmp,tmp2;
    fin>>cas;
    queue<pair<int,int> > bfs;
    priority_queue <pair<int, pair<int,int > > > dij;
    f(caseno,1,cas+1)
    {
              //       cerr<<caseno<<"\n";
       fin>>h>>n>>m;
       f(i,1,n+1)
       {
               f(j,1,m+1){ fin>>c[i][j];
               t[i][j]=BIG;
               }
       }
       f(i,1,n+1)
       {
               f(j,1,m+1) fin>>f[i][j];
       }
       f(i,0,n+2)
       {
                 c[i][0]=0;
                 f[i][0]=0;
                 c[i][m+1]=0;
                 f[i][m+1]=0;
       }
        f(j,0,m+2)
       {
                 c[0][j]=0;
                 f[0][j]=0;
                 c[n+1][j]=0;
                 f[n+1][j]=0;
       }
       bfs.push(mp(1,1));
       dij.push(mp(0,mp(1,1)));
       t[1][1]=0;
       while(!bfs.empty())
       {
                          
                          xc=bfs.front().x;
                          yc=bfs.front().y;
                          
                          bfs.pop();
                          f(i,0,4)
                          {
                                  if(min(c[xc][yc],c[xc+mv[i][0]][yc+mv[i][1]])-max(h,max(f[xc][yc],f[xc+mv[i][0]][yc+mv[i][1]]))>=50)
                                  {
                                     if(t[xc+mv[i][0]][yc+mv[i][1]]!=0)
                                     {
                                        t[xc+mv[i][0]][yc+mv[i][1]]=0;
                                        bfs.push(mp(xc+mv[i][0],yc+mv[i][1]));
                                        dij.push(mp(0,mp(xc+mv[i][0],yc+mv[i][1])));
                                     }
                                  }
                          }
       }
       while(!dij.empty())
       {
                          xc=dij.top().y.x;
                          yc=dij.top().y.y;
                          if(-dij.top().x>t[xc][yc]) {dij.pop();
                                                     continue;}
                      //    cerr<<"d"<<xc<<" "<<yc<<"\n";
                          dij.pop();
                          f(i,0,4)
                          {
                                  if(min(c[xc][yc],c[xc+mv[i][0]][yc+mv[i][1]])-max(f[xc][yc],f[xc+mv[i][0]][yc+mv[i][1]])>=50)
                                  {
                                  if(min(c[xc][yc],c[xc+mv[i][0]][yc+mv[i][1]])-(h-t[xc][yc])>=50)
                                                                                                  tmp=0;
                                  else tmp=50-(min(c[xc][yc],c[xc+mv[i][0]][yc+mv[i][1]])-(h-t[xc][yc]));
                                 // cerr<<"c"<<xc+mv[i][0]<<" "<<yc+mv[i][1]<<"\n";
                                //  cerr<<t[xc][yc]<<" "<<f[xc][yc]<<"\n";
                                  if(h-t[xc][yc]-tmp-f[xc][yc]>=20) tmp2=10;
                                  else tmp2=100;
                                     if(t[xc+mv[i][0]][yc+mv[i][1]]>t[xc][yc]+tmp+tmp2)
                                     {
                                        t[xc+mv[i][0]][yc+mv[i][1]]=t[xc][yc]+tmp+tmp2;
                                        dij.push(mp(-(t[xc][yc]+tmp+tmp2),mp(xc+mv[i][0],yc+mv[i][1])));
                                     }
                                  }
                          }
                            
       }
      /* f(i,1,n+1)
       {
                 f(j,1,m+1)
                 {
                           cerr<<t[i][j]<<" ";
                 }
                 cerr<<"\n";
       }*/
       fout<<"Case #"<<caseno<<": "<<t[n][m]/10.0<<"\n";                
    }
    fin.close();
    fout.close();
    
    return 0;
}
