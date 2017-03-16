#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000000];
void find(char s[], int n)
{
    int i,len = strlen(s),a[len],count=0,sum=0,j,max=0;
    for(i=0;i<len;i++)
    {
        if(s[i]!='a' && s[i]!= 'e' && s[i] !='i' && s[i]!='o' && s[i]!='u')
        {
            a[i] = 1;
        }
        else
        {
            a[i]  = 0;
        }
    }
    for(i=0;i<len;i++)
    {
        max = count = 0;
        for(j=i;j<len;j++)
        {
            if(a[j] == 1)
            count++;
            else
            count =0;
            if(count>max)
            max = count;
            if(max>=n)
            sum++;
        }
    }
    printf("%d\n",sum);
}
int main()
{
    int i,t,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s %d",s,&n);
        printf("Case #%d: ",i+1);
        find(s,n);
    }
    return 0;
}