

#include <stdio.h>
#include <string.h>
#define MAXN 1010


int N;


int array[MAXN][2];
char mark1[MAXN];
char mark2[MAXN];


int stars;
int n2;
int n1;

char f()
{
    int i;
    for(i=0;i<N;i++)
    {
        if (mark2[i])
            continue;
        if (array[i][1]<=stars)
        {
            if (mark1[i])
                stars+=1;
            else
                stars+=2;
            mark2[i]=1;
            n2++;
            return 1;
        }
    }
    for(i=0;i<N;i++)
    {
        if (mark1[i] || mark2[i])
            continue;
        if (array[i][0]<=stars)
        {
            mark1[i]=1;
            stars+=1;
            n1++;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int T,caso;
    scanf("%d",&T);
    int i;
    for(caso=1;caso<=T;caso++)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d %d",&array[i][0],&array[i][1]);
        memset(mark2,0,MAXN);
        memset(mark1,0,MAXN);
        stars=0;
        n2=0;
        n1=0;
        char flag=0;
        char res;
        while(1)
        {
            res=f();
            if (n2==N)
                break;
            if (res==0)
            {
                flag=1;
                break;
            }
        }
        if (flag)
            printf("Case #%d: Too Bad\n",caso);
        else
            printf("Case #%d: %d\n",caso,n1+n2);
    }
    return 0;
}