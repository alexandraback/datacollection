#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    freopen("tide.in","r",stdin);
    freopen("tide.out","w",stdout);
    int tc;
    cin>>tc;
    for (int tcc=1;tcc<=tc;tcc++)
    {
        int h, n, m;
        cin>>h>>n>>m;
        int floor[110][110], ceil[110][110];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) cin>>ceil[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) cin>>floor[i][j];
        double time[110][110];
        for (int i=0;i<110;i++)
            for (int j=0;j<110;j++) time[i][j]=-1;
        queue< pair<int, int> > q;
        q.push(make_pair(0,0));
        time[0][0]=0;
        while (!q.empty())
        {
              pair<int, int> p=q.front();
              q.pop();
              int x=p.first, y=p.second;
//              cout<<"       "<<x<<" "<<y<<" "<<time[x][y]<<endl;cin.get();
              for (int k=0;k<4;k++)
              {
                  int i=x+dx[k], j=y+dy[k];
                  double w=h-10*time[x][y];
                  w>?=0;
                  if (i<0 || i>=n || j<0 || j>=m) continue;
//                  cout<<i<<" "<<j<<" "<<w<<endl;cin.get();
//                  cout<<floor[x][y]<<" "<<ceil[i][j]<<" "<<floor[i][j]<<endl;
                  if (floor[x][y]+50>ceil[i][j] || floor[i][j]+50>ceil[i][j] || floor[i][j]+50>ceil[x][y]) continue;
//                  cout<<"asdf"<<endl;
                  double ex=0, t=0;
                  if (w+50>ceil[i][j])
                  {
                                      ex=(w+50-ceil[i][j])/10.;
                                      w=ceil[i][j]-50;
                  }
//                  cout<<ex<<" "<<w<<" "<<time[i][j]<<endl;
                  if (w-floor[x][y]>=20) t=1;
                  else t=10;
                  if (w==h) t=0;
//                  cout<<"                            "<<time[x][y]+ex+t<<endl;cin.get();
                  if (time[i][j]==-1 || time[i][j]>time[x][y]+ex+t)
                  {
                                     time[i][j]=time[x][y]+ex+t;
                                     q.push(make_pair(i,j));
                  }
              }
        }
        cout<<"Case #"<<tcc<<": "<<time[n-1][m-1]<<endl;
    }
}
