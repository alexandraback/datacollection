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
#include <cstring>

using namespace std;
typedef long long LL;

int a[5][5];
int win;

bool isX(int x)
{
    return (x==0 || x==2);
}
bool isO(int o)
{
    return (o==1 || o==2);
}
void check(int x, int y, int z, int t)
{
    if (isX(x) && isX(y) && isX(z) && isX(t)) win=0;
    if (isO(x) && isO(y) && isO(z) && isO(t)) win=1;
}
int main()
{
    freopen("tictactoe.in","r",stdin);
    freopen("tictactoe.out","w",stdout);
    int nt, tt=1;
    cin>>nt;
    while (nt--)
    {
        int end=1;
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
            {
                char ch;
                cin>>ch;
                if (ch=='X') a[i][j]=0;
                else if (ch=='O') a[i][j]=1;
                else if (ch=='T') a[i][j]=2;
                else
                {
                    a[i][j]=-1;
                    end=0;
                }
            }
        win=-1;
        for (int i=0;i<4;i++)
        {
            check(a[i][0],a[i][1],a[i][2],a[i][3]);
            check(a[0][i],a[1][i],a[2][i],a[3][i]);
        }
        check(a[0][0],a[1][1],a[2][2],a[3][3]);
        check(a[3][0],a[2][1],a[1][2],a[0][3]);
        cout<<"Case #"<<tt++<<": ";
        if (win==0) cout<<"X won"<<endl;
        else if (win==1) cout<<"O won"<<endl;
        else
        {
            if (end) cout<<"Draw"<<endl;
            else cout<<"Game has not completed"<<endl;
        }
    }
}
