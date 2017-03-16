#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int t[101][101];
bool blok[501];

int main ()
{
    int z,a,b,c,d,n,m,mam;
    bool rzyc;
    
    scanf ("%d", &z);
    
    for (a=1; a<=z; a++)
    {
        scanf ("%d%d", &n, &m);
        
        for (b=0; b<n; b++)
            blok[b]=0;
        
        for (b=0; b<m; b++)
            blok[200+b]=0;
        
        for (b=0; b<n; b++)
            for (c=0; c<m; c++)
                scanf ("%d", &t[b][c]);
                
        rzyc=0;
        
        for (b=100; b; b--)
        {
            for (c=0; c<n; c++)
                for (d=0; d<m; d++)
                    if (t[c][d]==b)
                                   if (blok[c] && blok[200+d])
                                      rzyc=1;
                                      
            for (c=0; c<n; c++)
                for (d=0; d<m; d++)
                    if (t[c][d]==b)
                    {
                                   blok[c]=1;
                                   blok[200+d]=1;
                    }
        }
        
        if (rzyc)
                 printf ("Case #%d: NO\n", a);
        else
            printf ("Case #%d: YES\n", a);
    }
                                      
    getchar();
    getchar();
    return 0;
}
