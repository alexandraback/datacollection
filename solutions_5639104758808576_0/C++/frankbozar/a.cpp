#include<cstdio>

int main()
{
    for(int N, Case=scanf("%d", &N); Case<=N; Case++)
    {
        int n, ans=0;
        char a[1024];
        scanf("%d%s", &n, a);
        
        for(int acc=a[0]-'0', i=1; i<=n; i++)
        {
            if( a[i]=='0' )
                continue;
            
            if( acc<i )
            {
                ans+=i-acc;
                acc=i;
            }
            
            acc+=a[i]-'0';
        }
        
        printf("Case #%d: %d\n", Case, ans);
    }
}