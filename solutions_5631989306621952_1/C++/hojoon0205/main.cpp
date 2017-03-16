#include<stdio.h>
#include<string.h>
int n;
char arr[1010], x[1010], y[1010], ans[1010];
int main()
{
    FILE *fin=fopen("input.txt","r");
    FILE *fout=fopen("output.txt","w");
    int i, j, T, tt;
    fscanf(fin, "%d", &T);
    for(tt=1; tt<=T; ++tt)
    {
        fscanf(fin, "%s", arr);
        n=strlen(arr);
        for(i=0; i<1000; ++i) x[i]=y[i]=ans[i]=NULL;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<strlen(ans); ++j) x[j]=y[j+1]=ans[j];
            x[strlen(ans)]=arr[i];
            y[0]=arr[i];
            if(strcmp(x, y)==-1)
            {
                for(j=0; j<strlen(y); ++j) ans[j]=y[j];
            }
            else
            {
                for(j=0; j<strlen(x); ++j) ans[j]=x[j];
            }
        }
        fprintf(fout, "Case #%d: %s\n", tt, ans);
    }
}
