#include<cstdio>
typedef long long lld;

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        lld k, c, s;
        scanf("%lld%lld%lld", &k, &c, &s);
        
        if( k>c*s )
        {
            printf("Case #%d: IMPOSSIBLE\n", cases);
            continue;
        }
        
        printf("Case #%d:", cases);
        
        for(lld i=0; i<k; )
        {
            lld v=0;
            
            for(lld j=0; j<c; j++)
            {
                v*=k;
                v+= i>=k ? 0 : i;
                i++;
            }
            
            printf(" %lld", v+1);
        }
        
        printf("\n");
    }
}

/*

5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3

*/