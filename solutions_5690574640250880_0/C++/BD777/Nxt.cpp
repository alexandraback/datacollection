#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn =  100086;
const ll mod = 1e9+7;

struct Node
{
    int x,y;
    Node(int X,int Y)
    {
        x = X;
        y = Y;
    }
};

char a[60][60];
int b[60][60];
int ca[][2] = {{0,1},{0,-1},{1,1},{1,-1},{-1,0},{1,0},{-1,1},{-1,-1}};
bool vis[60][60];
int R,C,M;
int num;

void pnt(int,int);

bool dfs(int x,int y,int ceng)
{
    //cout << x << ' ' << y <<endl;
    //cout << num << endl;
    //pnt(R,C);
    vis[x][y] = true;
    if(num == 0) return true;
    if(num < 0) return false;
    a[x][y] = '.';
    int i;
    int tmp = 0;
    for(i=0;i<8;i++)
    {
        if(a[x+ca[i][0]][y+ca[i][1]] == '*')
        {
            b[x+ca[i][0]][y+ca[i][1]] = ceng;
            a[x+ca[i][0]][y+ca[i][1]] = 'x';
            tmp ++;
        }
    }
    num -= tmp;
    for(i=0;i<8;i++)
    {
        if(b[x+ca[i][0]][y+ca[i][1]] == ceng)
        {

            if(dfs(x+ca[i][0],y+ca[i][1],ceng+1)) return true;
            //a[x+ca[i][0]][y+ca[i][1]] = '*';
        }
    }
    for(i=0;i<8;i++)
    {
        if(b[x+ca[i][0]][y+ca[i][1]] == ceng)
        {

            //if(dfs(x+ca[i][0],y+ca[i][1])) return true;
            a[x+ca[i][0]][y+ca[i][1]] = '*';
        }
    }
    num += tmp;
    a[x][y] = 'a';
    return false;
}

void pnt(int r,int c)
{
    int i,j;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(i == 1 && j == 1) cout << 'c';
            else{
                //cout << a[i][j];
                if(a[i][j] == 'a' || a[i][j] == 'x')
                    cout << '.';
                else cout << a[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    freopen("C-small-attempt1.txt","w+",stdout);
    freopen("C-small-attempt1.in","r",stdin);
    int T;
    int kase = 0;
    cin >> T;
    while(T--)
    {
        //int R,C,M;
        cin >> R>> C>>M;
        memset(a,'*',sizeof(a));
        int i,j;
        for(i=0;i<=R+1;i++) a[i][0] = a[i][C+1] = 'b';
        for(i=0;i<=C+1;i++) a[0][i] = a[R+1][i] = 'b';
        num = R*C - M;
        a[1][1] = 'a';
        num --;
        printf("Case #%d:\n",++kase);
        //cout << "Case #" << ++kase << ":" << endl;
        memset(b,-1,sizeof(b));
        if(dfs(1,1,0))
        {
            pnt(R,C);
        }
        else cout << "Impossible" << endl;
        //pnt(R,C);
    }
    fclose(stdout);
    fclose(stdin);
}
