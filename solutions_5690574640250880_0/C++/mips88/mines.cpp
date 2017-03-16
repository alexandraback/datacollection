#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#define FOR(i,n) for (int i = 0 ; i< n;i++)
#define FORI(i,s,e) for (int i = s ; i<= e;i++)
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define FZ(x) memset(x,0,sizeof(x))
using namespace std;
FILE* fin;
FILE* fout;
int nTESTS;

int x,y,m,initm;
bool possible;
void read()
{

    fscanf(fin,"%d %d %d",&x,&y,&m);
    initm = m;
}
char matr[100][100];
void solve()
{
    possible = m<x*y;


    FOR(i,x)
    FOR(j,y)
    matr[i][j] = '.';
    int ptx = x;
    int pty = y;
    while (m>=min(ptx,pty))
    {
        m-=min(ptx,pty);
        if (ptx<pty)
        {
            FOR(i,x)
            {
                matr[i][y-pty] = '*';
            }
            pty--;
        }
        else
        {
            FOR(i,y)
            {
                matr[x-ptx][i] = '*';
            }
            ptx--;
        }

    }

    matr[x-1][y-1] = 'c';
    if (min(ptx,pty) == 1)
    {
        if (max(ptx,pty) == 1)
        {
        }
        else
        if ((x== 1) || (y == 1))
        {

        }
        else
        possible = false;

    }

    if (min(ptx,pty) == 2)
    {
        if (m == 0)
        {
        }
        else
        possible = false;
    }

    if (max(ptx,pty) > 2)
    {
        int space = max(2,max(ptx,pty)-m);
        m-=max(ptx,pty)-space;
        if (ptx>pty)
        {
            FOR(i,x-space)
            {
                matr[i][y-pty] = '*';
            }
        }
        else
        {
            FOR(i,y-space)
            {
                matr[x-ptx][i] = '*';
            }
        }
    }

    if (min(ptx,pty) == 3)
    {
        if (m > 0)
            possible = false;
    }
    if (min(ptx,pty) > 3)
    {
        if (m>0)
        {
        matr[x-ptx+1][y-pty] = '*';
        matr[x-ptx][y-pty+1] = '*';
        }
    }

/*
    FOR(i,x)
    {
        FOR(j,y)
        cout << matr[i][j] ;

        cout << endl;
    }
    cout << ptx << endl;
    cout << pty << endl;
    cout << m << endl;
*/
}

void write()
{
    fprintf(fout,"\n");
    // quick check
    if (possible)
    {

        FOR(i,x)
        FOR(j,y)
        {
            initm -= (matr[i][j] =='*');
        }
        if ((initm!=0)||(matr[x-1][y-1]!='c'))
            cout << "WRONG"<<nTESTS<<"!!!!!!!!!!!!!!!!";
        FOR(i,x)
        {
            FOR(j,y)
            fprintf(fout,"%c", matr[i][j] );

            fprintf(fout,"\n");
        }
    }
    else
    {
         fprintf(fout,"Impossible");
    }
}
/*
*******
*******
*******
****
XXXXXXX000
0000000000
000000000X

X00
000
00x

*/

int gen()
{
    fout = fopen("input.txt","w");
    int n = 1000;
    fprintf(fout,"%d\n",n);
    FOR(i,n)
    {
        int x = rand()%10+1;
        int y = rand()%10+1;
        fprintf(fout,"%d %d %d\n",x,y,max(x*y-rand()%4-1,0));
    }
    fclose(fout);
}

int main()
{
    //gen();
    fin = fopen("input.txt","r");
    fout = fopen("output.txt","w");

    fscanf(fin,"%d",&nTESTS);

    FOR(crtTest,nTESTS)
    {
        read();
        solve();
        fprintf(fout,"Case #%d: ",crtTest+1);
        write();
        fprintf(fout,"\n");
    }
    fclose(fout);

    return 0;
}
