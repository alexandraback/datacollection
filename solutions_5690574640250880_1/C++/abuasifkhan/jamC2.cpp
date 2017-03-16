//!
///

/**============= Approach =================**
@Author: A Asif Khan Chowdhury
@Category:
/**========================================**/


/**................ Headers ................**/
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case #%d:\n", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 100000007
#define mx 55
int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}

//    int XX[]={0,1,1,1,0,-1,-1,-1};
//    int YY[]={1,1,0,-1,-1,-1,0,1};
int main()
{
    open
    write
    int test,cnt;
    int r,c,m,left;
    char grid[mx][mx];
    S(test);
    FOR(C, 1, test){
        cin>>r>>c>>m;
        left=r*c-m;
        cnt=0;
        CLEAR(grid, 's');
        out(C);
        if((r==1 or c==1 or left==1) and left){
            for(int i=1; i<=r; i++){
                for(int j=1; j<=c; j++)
                    if(i==r and j==c)cout<<"c";
                    else if(cnt++<m)cout<<"*";
                    else cout<<".";
                cout<<endl;
            }
            continue;

        }
        if( left==5 or left==7 or left<4 or((r==2 or c==2) and left%2==1 )){
            printf("Impossible\n");
            continue;
        }
        if(left>=4){
            grid[r-1][c]=grid[r][c-1]=grid[r-1][c-1]='.';
            left-=4;
            grid[r][c]='c';
            if(left%2==1){
                grid[r-2][c-2]='.';
                left--;
            }

            bool pos=true;
            int i=r-2,j=c-2;
            while(left>0 && (i>0 || j>0)){
                if((pos or j<=0) and i>0){
                    grid[i][c]=grid[i][c-1]='.';
                    i--;
                }
                else if(j>0){
                    grid[r][j]=grid[r-1][j]='.';
                    j--;
                }
                left-=2;
                pos=!pos;
            }
            for(int i=1; i<=r; i++){
                for(int j=1; j<=c; j++)
                    if(i==r and j==c )cout<<"c";
                    else if((grid[i][j]!='.')and cnt++<m)cout<<"*";
                    else cout<<'.';
                cout<<endl;
            }
            continue;
        }
    }

}





