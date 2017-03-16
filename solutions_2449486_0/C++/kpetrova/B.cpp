#include <cstdio>
#include <algorithm>

using namespace std;

struct cell
{
    int x,y,h;
};

int a[108][108];

cell r[10008];

bool f(const cell &u, const cell &v)
{
    if ( u.h < v.h ) return true;
    if ( u.h > v.h ) return false;
    if ( u.x < v.x ) return true;
    if ( u.x > v.x ) return false;
    if ( u.y < v.y ) return true;
    return false;
}

int main()
{
    int t,tt,n,m,i,j,flag1,br,flag2,flag;
    scanf ("%d",&t);
    for ( tt=1; tt<=t; tt++ )
    {
        flag = 0;
        
        br = 0;
        scanf ("%d%d",&n,&m);
        for ( i=1; i<=n; i++ )
            for ( j=1; j<=m; j++ )
            {
                scanf ("%d",&a[i][j]);
                br++;
                r[br].h = a[i][j];
                r[br].x = i;
                r[br].y = j;
            }
        
        sort ( r+1, r+br+1, f );    
        
        for ( i=1; i<=br; i++ )
        {
            flag1 = 0;
            for ( j=1; j<=n; j++ )
                if ( a[j][ r[i].y ] > r[i].h ) flag1 = 1;
            
            flag2 = 0;
            for ( j=1; j<=m; j++ )
                if ( a[ r[i].x ][j] > r[i].h ) flag2 = 1;
            
            if ( flag1 && flag2 ) 
            {
                flag = 1;
                break;
            }       
        }
        
        if ( flag ) printf ("Case #%d: NO\n",tt);
        else printf ("Case #%d: YES\n",tt);
    }
}