#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case #%d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

char grid[5][5];

int main()
{
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
        int i, j, k;
        for(i=0;i<4;i++)
            scanf(" %s", &grid[i]);
        int x=0, o=0, c=0;
        for(i=0;i<4;i++) for(j=0;j<4;j++) if(grid[i][j]=='.') {c=1; break;}
        int cnt;
        //for X
        for(i=0;i<4;i++)
        {
            cnt=0;
            for(j=0;j<4;j++)
            {
                if(grid[i][j]=='T' || grid[i][j]=='X')
                    cnt++;
            }
            if(cnt==4)
            {
                x=1;
                break;
            }
        }
        for(j=0;j<4;j++)
        {
            cnt=0;
            for(i=0;i<4;i++)
            {
                if(grid[i][j]=='T' || grid[i][j]=='X')
                    cnt++;
            }
            if(cnt==4)
            {
                x=1;
                break;
            }
        }
        cnt=0;
        for(i=0,j=0;i<4;i++,j++)
        {
            if(grid[i][j]=='T' || grid[i][j]=='X')
                    cnt++;
            if(cnt==4)
                x=1;
        }
        cnt=0;
        for(i=3,j=0;i>=0;i--,j++)
        {
            if(grid[i][j]=='T' || grid[i][j]=='X')
                    cnt++;
            if(cnt==4)
                x=1;
        }

        //For O
        for(i=0;i<4;i++)
        {
            cnt=0;
            for(j=0;j<4;j++)
            {
                if(grid[i][j]=='T' || grid[i][j]=='O')
                    cnt++;
            }
            if(cnt==4)
            {
                o=1;
                break;
            }
        }
        for(j=0;j<4;j++)
        {
            cnt=0;
            for(i=0;i<4;i++)
            {
                if(grid[i][j]=='T' || grid[i][j]=='O')
                    cnt++;
            }
            if(cnt==4)
            {
                o=1;
                break;
            }
        }
        cnt=0;
        for(i=0,j=0;i<4;i++,j++)
        {
            if(grid[i][j]=='T' || grid[i][j]=='O')
                    cnt++;
            if(cnt==4)
                o=1;
        }
        cnt=0;
        for(i=3,j=0;i>=0;i--,j++)
        {
            if(grid[i][j]=='T' || grid[i][j]=='O')
                    cnt++;
            if(cnt==4)
                o=1;
        }
        csprnt;
        if(x==1)
            cout<<"X won"<<endl;
        else if(o==1)
            cout<<"O won"<<endl;
        else if(c==0)
            cout<<"Draw"<<endl;
        else cout<<"Game has not completed"<<endl;
    }
    return 0;
}

