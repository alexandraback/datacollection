/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define pb push_back
#define pis pair < pii, string >
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int dist[805][805];
int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("B.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas = 0;
    while(t--)
    {
        //memset(dist,100000000,sizeof(dist));
        for(int i= 0;i<805;i++)
        {
            for(int j=0;j<805;j++)
                dist[i][j] = 100000000;
        }
        cas++;
        int x,y;
        scanf("%d %d",&x,&y);
        dist[401][401] = 0;
        x += 401;
        y += 401;
        queue< pair < pii, string > > Q;
        string s = "";
         Q.push( pis (pii(401,401) ,s ) );
        string ans;
        while(!Q.empty())
        {
            int m = Q.front().first.first;
            int n = Q.front().first.second;
            int dis = dist[m][n];
            string str = Q.front().second,str2;
          //  cout << m << " " << n << endl;
            Q.pop();
            if(x == m && y==n)
            {
                ans = str;
                break;
            }
            int i,j;
            i = m + (dis + 1);
            j = n;
            str2 = str + "E";
          //  cout << i << " " << j;
            //cout << dist[i][j] << " " << dis+1 << endl;
            if(i >=0 && j>=0 && i<805 && j < 805)
            if(dist[i][j]>dis+1)
            {
                dist[i][j] = dis+1;
                Q.push(pis(pii(i,j),str2));
            }
            i = m - (dis + 1);
            j = n;
            str2 = str + "W";
            if(i >=0 && j>=0 && i<805 && j < 805)
            if(dist[i][j]>dis+1)
            {
                dist[i][j] = dis+1;
                Q.push(pis(pii(i,j),str2));
            }
            i = m;
            j = n + (dis+1);
            str2 = str + "N";
            if(i >=0 && j>=0 && i<805 && j < 805)
            if(dist[i][j]>dis+1)
            {
                dist[i][j] = dis+1;
                Q.push(pis(pii(i,j),str2));
            }
            i = m;
            j = n - (dis + 1);
            str2 = str + "S";
            if(i >=0 && j>=0 && i<805 && j < 805)
            if(dist[i][j]>dis+1)
            {
                dist[i][j] = dis+1;
                Q.push(pis(pii(i,j),str2));
            }
        }
        printf("Case #%d: ",cas);
        cout << ans << endl;
    }
return 0;
}
