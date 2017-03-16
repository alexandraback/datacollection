#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#define forup(i,a,b) for (int i=a;i<=b;i++)
#define fordown(i,a,b) for (int i=a;i>=b;--i)

using namespace std;

int T;
char a[5][5];

bool check(char now){
    forup(i,1,4)
    {
        bool ok=true;
        forup(j,1,4)
            if (a[i][j]!=now && a[i][j]!='T') 
            {
               ok=false;
               break;
            }
        if (ok) return(true);
        ok=true;
        forup(j,1,4)
            if (a[j][i]!=now && a[j][i]!='T') 
            {
               ok=false;
               break;
            }
        if (ok) return(true);
    }
    bool ok=true;
    forup(i,1,4)
        if (a[i][i]!=now && a[i][i]!='T') 
        {
               ok=false;
               break;
        }
    if (ok) return(true);
    ok=true;
    forup(i,1,4)
        if (a[i][5-i]!=now && a[i][5-i]!='T') 
        {
               ok=false;
               break;
        }
    if (ok) return(true);
    return(false);
}

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&T);
    forup(uu,1,T)
    {
        printf("Case #%d: ",uu);
        int cnt=0;
        forup(i,1,4) 
        {
            scanf("%s",a[i]);
            fordown(j,4,1) a[i][j]=a[i][j-1];
            forup(j,1,4) 
                if (a[i][j]=='.') ++cnt;
        }
        if (check('O')) printf("O won\n");
        else if (check('X')) printf("X won\n");
        else if (!cnt) printf("Draw\n");
        else printf("Game has not completed\n");
    }
}
