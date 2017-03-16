#include <cstdio>
using namespace std;
int nrt,l,i,n,nn,a[100],b[100],aa,bb,j,ii[5],jj[5],ok,q,w,st,mindif,k;
char s[100];
int modul(int x)
{
    if(x<0)return -x;
    else return x;
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d\n",&nrt);
    for(l=1;l<=nrt;l++)
    {
        gets(s);
        i=0;
        n=0;
        nn=0;
        while(s[i]=='?'||(s[i]>='0'&&s[i]<='9'))
        {
            n++;
            if(s[i]=='?')
            {
                a[n]=-1;
            }
            else a[n]=s[i]-'0';
            i++;
        }
        i++;
        while(s[i]=='?'||(s[i]>='0'&&s[i]<='9'))
        {
            nn++;
            if(s[i]=='?')
            {
                b[nn]=-1;
            }
            else b[nn]=s[i]-'0';
            i++;
        }
        if(n==1)st=9;
        if(n==2)st=99;
        if(n==3)st=999;
        mindif=1000;
        for(i=0;i<=st;i++)
        {
            if(n==3){ii[1]=i%1000/100;
            ii[2]=i%100/10;
            ii[3]=i%10;}
            else if(n==2)
            {
                ii[1]=i%100/10;
                ii[2]=i%10;
            }
            else ii[1]=i;
            for(j=0;j<=st;j++)
            {
                if(n==3){jj[1]=j%1000/100;
                jj[2]=j%100/10;
                jj[3]=j%10;}
                else if(n==2)
                {
                    jj[1]=j%100/10;
                    jj[2]=j%10;
                }
                else jj[1]=j;
                ok=0;
                for(k=1;k<=n;k++)
                {
                    if(a[k]>=0&&ii[k]!=a[k])ok=1;
                    if(b[k]>=0&&jj[k]!=b[k])ok=1;
                }
                if(ok==0)
                {
                    if(mindif>modul(i-j))
                    {
                        mindif=modul(i-j);
                        q=i;
                        w=j;
                    }
                }
            }
        }
        printf("Case #%d: ",l);
        if(n==3)
            printf("%d%d%d %d%d%d\n",q%1000/100,q%100/10,q%10,w%1000/100,w%100/10,w%10);
        else if(n==2)
            printf("%d%d %d%d\n",q%100/10,q%10,w%100/10,w%10);
        else printf("%d %d\n",q,w);
    }
return 0;
}
