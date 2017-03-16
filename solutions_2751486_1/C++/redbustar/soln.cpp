#include<stdio.h>
char s[1000010];
int fre[1000010];
int main()
{
    int t,n,i,j,count,ans,prev,c,k,l,temp;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        scanf("%s %d",s,&n);
        //printf("%s ",s);
        j=0;
        while(s[j]!=0)
        {
            if(s[j]!='a'&&s[j]!='e'&&s[j]!='i'&&s[j]!='o'&&s[j]!='u')
            {
                if(j!=0)
                fre[j]=fre[j-1]+1;
                else
                    fre[j]=1;
            }
            else
                fre[j]=0;
            j++;
        }
        ans=0;
        count=0;
        temp=0;
        for(k=0;k<j;)
        {
                if(fre[k]>=n)
                {
                    count=k+2-n;
                    k++;
                    temp=0;
                    while(k<j&&fre[k]<n)
                    {
                        temp+=count;
                        k++;
                    }
                    ans=ans+count+temp;
                }
                else
                    k++;
                //printf("%d ",ans);
        }
        printf("Case #%d: %d\n",i,ans);
        for(k=0;k<j;k++)
            fre[k]=0;
    }
    return 0;
}
