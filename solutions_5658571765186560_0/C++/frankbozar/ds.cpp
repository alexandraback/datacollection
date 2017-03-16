#include<cstdio>

bool solve(int x, int r, int c)
{
    if( r*c%x!=0 )
        return false;
    
    switch( x )
    {
        case 1:
        case 2:
            return true;
        
        case 3:
            return c*r>1*3;
            
        case 4:
            return r*c>2*4;
    }
}

int main()
{
    for(int N, Case=scanf("%d", &N); Case<=N; Case++)
    {
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        printf("Case #%d: %s\n", Case, solve(x, r, c) ? "GABRIEL" : "RICHARD");
    }
}