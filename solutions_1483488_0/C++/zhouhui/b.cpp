#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char t[10];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int a,b,cnt=0;
        scanf("%d%d",&a,&b);
        for(int j=a; j<=b; j++)
        {
            int c=j,len,s[10],d=0,q;
             sprintf(t,"%d",c);
            len=strlen(t);
            for(int k=0; k<len; k++)
            {
                int m=0;
                for(int p=len-k; p<len; p++)
                    m=m*10+(t[p]-'0');
                for(int p=0; p<len-k; p++)
                    m=m*10+(t[p]-'0');
                    s[d++]=m;
            }
            sort(s,s+d);
            for(int k=0;k<d;k++)
            {
                if(s[k]>j&&s[k]<=b&&k==0)
                {
                    cnt++;
                    q=s[0];
                }
                if(s[k]>j&&s[k]<=b&&k!=0&&q!=s[k])
                {
                    cnt++;
                    q=s[k];
                }
            }
        }
        printf("Case #%d: %d\n",i,cnt);
    }
    return 0;
}
