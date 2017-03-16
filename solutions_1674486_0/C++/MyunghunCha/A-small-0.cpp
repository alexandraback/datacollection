#include <stdio.h>
#include <memory.h>

#define MAX 1000

int a[MAX+1][MAX+1];
int acnt[MAX+1];
int c[MAX+1];

int n;

int traverse(int now)
{
    int i;

    if(c[now] == 1)
        return 1;

    c[now] = 1;

    for(i=0;i<acnt[now];i++)
        if(traverse(a[now][i]))
            return 1;

    return 0;
}

int main()
{
    int t,tt;
    int i,j;

    FILE *in = fopen("A-small-0.in","r");
    FILE *out = fopen("A-small-0.out","w");

    fscanf(in, "%d", &t);

    for(tt=1; tt<=t; tt++)
    {
        fscanf(in, "%d", &n);

        memset(a,0,sizeof(a));
        memset(acnt,0,sizeof(acnt));
        
        for(i=1;i<=n;i++)
        {
            fscanf(in, "%d", &acnt[i]);
            for(j=0;j<acnt[i];j++)
                fscanf(in,"%d", &a[i][j]);
        }

        for(i=1;i<=n;i++)
        {
            memset(c,0,sizeof(c));
            if(traverse(i))
                break;
        }

        fprintf(out,"Case #%d: ",tt);
        fprintf(out,"%s\n",(i>=n)? "No": "Yes");
    }

    return 0;
}
