#include<iostream>

using namespace std;

int T;
int N,S,p;
int a[110];
int tmp;
int ans;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        ans=0;
        scanf("%d %d %d",&N,&S,&p);
        for(int j=1;j<=N;j++)
            scanf("%d",a+j);
        for(int j=1;j<=N;j++)
            for(int k=j+1;k<=N;k++)
            if(a[j]<a[k])
            {
                tmp=a[j];a[j]=a[k];a[k]=tmp;
            }
        for(int j=1;j<=N;j++)
        {
            if(a[j]%3==0)
            {
                if(a[j]/3>=p) ans++;
                else
                {
                    if(S>0 && a[j]/3+1>=p && a[j]!=0)
                    {
                        S--;
                        ans++;
                    }
                }
            }
            if(a[j]%3==1)
            {
                if(a[j]/3+1>=p) ans++;
            }
            if(a[j]%3==2)
            {
                if(a[j]/3+1>=p) ans++;
                else
                {
                    if(S>0 && a[j]/3+2>=p)
                    {
                        S--;
                        ans++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
}
