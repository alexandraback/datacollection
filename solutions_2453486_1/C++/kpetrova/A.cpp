#include <cstdio>

using namespace std;

char a[5][5],pl[2];
int fl[2];

int main()
{
    char c;
    int t,i,j,tt,k,flag;
    scanf ("%d",&t);
    
    pl[0] = 'X';
    pl[1] = 'O';
    
    for ( tt=1; tt<=t; tt++ )
    {
        fl[0] = fl[1] = 0;
        
        scanf ("%c",&c);
        for ( i=0; i<4; i++ ) scanf ("%s",a[i]);
        
        for ( k=0; k<2; k++ )
        {
            for ( i=0; i<4; i++ )
            {
                flag = 0;
                for ( j=0; j<4; j++ )
                    if ( a[i][j] != pl[k] && a[i][j] != 'T' ) flag = 1;
                if ( !flag ) fl[k] = 1;    
            }
            
            for ( i=0; i<4; i++ )
            {
                flag = 0;
                for ( j=0; j<4; j++ )
                    if ( a[j][i] != pl[k] && a[j][i] != 'T' ) flag = 1;
                if ( !flag ) fl[k] = 1;    
            }
            
            flag = 0;
            for ( i=0; i<4; i++ )
                if ( a[i][i] != pl[k] && a[i][i] != 'T' ) flag = 1;
            if ( !flag ) fl[k] = 1;
            
            flag = 0;
            for ( i=0; i<4; i++ )
                if ( a[i][3-i] != pl[k] && a[i][3-i] != 'T' ) flag = 1;
            if ( !flag ) fl[k] = 1;
                
        }
        
        if ( fl[0] ) printf ("Case #%d: X won\n",tt);
        else if ( fl[1] ) printf("Case #%d: O won\n",tt);
        else
        {
            flag = 0;
            for ( i=0; i<4; i++ )
                for ( j=0; j<4; j++ )
                    if ( a[i][j] == '.' ) flag = 1;
            
            if ( !flag ) printf("Case #%d: Draw\n",tt);
            else printf("Case #%d: Game has not completed\n",tt);    
        }
    }
}