#include<cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    
    for(int cases=1; cases<=N; cases++)
    {
        char s[2048]={0};
        scanf("%s", s);
        int c[256]={0};
        
        for(int i=0; s[i]!='\0'; i++)
            c[ s[i] ]++;
        
        const char *t="ZXUFVWONIT", *d="0645721983", *v[10]={"ZERO", "SIX", "FOUR", "FIVE", "SEVEN", "TWO", "ONE", "NINE", "EIGHT", "THREE"};
        
        for(int i=0; i<10; i++)
        {
            c[ d[i] ]=c[ t[i] ]>>(i==7 ? 1 : 0);
            
            for(int j=0; v[i][j]!='\0'; j++)
                c[ v[i][j] ]-=c[ d[i] ];
        }
        
        printf("Case #%d: ", cases);
        
        for(int i='0'; i<='9'; i++)
            for(int j=c[i]; j>0; j--)
                printf("%c", i);
        
        printf("\n");
    }
}