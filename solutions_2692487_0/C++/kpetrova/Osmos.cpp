#include <cstdio>
#include <algorithm>

using namespace std;

int a[128];

int main()
{
    int t,tt;
    scanf ("%d",&t);
    for ( tt=1; tt<=t; tt++ ){
    
    int n,A,br=0,mini;
    scanf ("%d%d",&A,&n);
    
    for ( int i=1; i<=n; i++ ) scanf ("%d",&a[i]);
    sort (a+1,a+n+1);
    
    mini = n;
    
    if ( A == 1 )
    {
        printf ("Case #%d: %d\n",tt,mini);
        continue;
    }
    
    for ( int i=1; i<=n; i++ )
    {
        while ( A <= a[i] )
        {
            A += A - 1;
            br++;
        }
        A += a[i];
        
        if ( mini > br + n - i ) mini = br + n - i;
    }
    printf ("Case #%d: %d\n",tt,mini);
}

}