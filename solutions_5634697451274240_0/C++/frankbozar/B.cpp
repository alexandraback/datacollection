#include<cstdio>
#include<cstring>

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        char s[128];
        scanf("%s", s);
        int n=strlen(s), ans=0;
        
        for(int i=n-1; i>=0; i--)
        {
            if( ans%2==0 && s[i]=='-' )
                ans++;
            else if( ans%2==1 && s[i]=='+' )
                ans++;
        }
        
        printf("Case #%d: %d\n", cases, ans);
    }
}

/*

5
-
-+
+-
+++
--+-

*/