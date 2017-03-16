#include<stdio.h>
#include<string.h>

int total,each[200],maxn,s,l,k;
char keyboard[200],target[200],str[200];

void check()
{
    int i,j,cnt=0,flag;
    for(i=0;i<s;i++)
    {
        flag=0;
        for(j=0;j<l && (i+j)<s && flag==0;j++)
        {
            if(str[i+j]!=target[j])
                flag=1;
        }
        if(flag==0 && j==l)
        {
            cnt++;
        }
    }
    each[cnt]++;
    if(cnt>maxn)
        maxn=cnt;
}

void rec(int n)
{
    int i;
    if(n==s)
    {
        total++;
        check();
    }
    else
    {
        for(i=0;i<k;i++)
        {
            str[n]=keyboard[i];
            rec(n+1);
        }
    }
}

int main()
{
    int t,i,j;
    double ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",keyboard);
        scanf("%s",target);

        total=0;
        memset(each,0,sizeof(each));
        maxn=0;

        rec(0);

        ans=0;
        for(j=0;j<=maxn;j++)
        {
            ans += (double)each[j]*(double)j/(double)total;
        }
        ans=maxn-ans;
        printf("Case #%d: %lf\n",i,ans);
    }
    return 0;
}
