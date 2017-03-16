#include <cstdio>
#include <cstring>
using namespace std;
int nrt,l,i,nr,ras,k,x[20],ok,ookk,o1,o2,j,s,n,jj;
char a[20][22],b[20][22],ss[50];
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&nrt);
    for(l=1;l<=nrt;l++)
    {
        scanf("%d\n",&nr);

        for(i=1;i<=nr;i++)
        {
            gets(ss);
            ras=strlen(ss);
            n=-1;
            for(j=0;j<ras;j++)
                if(ss[j]>='A'&&ss[j]<='Z')
                {
                    n++;
                    a[i][n]=ss[j];
                }
                else break;
                a[i][n+1]='\0';
            n=-1;
            for(jj=j+1;jj<ras;jj++)
                if(ss[jj]>='A'&&ss[jj]<='Z')
                {
                    n++;
                    b[i][n]=ss[jj];
                }
                b[i][n+1]='\0';
        }
        ras=0;
        k=1;
        x[k]=0;
        while(k>0)
        {
            ok=0;
            while(ok==0&&x[k]<2&&k<=nr)
            {
                x[k]++;
                ok=1;
            }
            if(ok==1)
            {
                if(k==nr)
                {
                    ookk=0;
                    for(i=1;i<=nr;i++)
                    {
                        if(x[i]==1)
                        {
                            o1=o2=0;
                            for(j=1;j<=nr;j++)
                            {
                                if(x[j]==2&&strcmp(a[i],a[j])==0){o1=1;break;}
                            }
                            for(j=1;j<=nr;j++)
                            {
                                if(x[j]==2&&strcmp(b[i],b[j])==0){o2=1;break;}
                            }
                            if(o1==0||o2==0){ookk=1;break;}
                        }
                    }
                    s=0;
                    for(i=1;i<=nr;i++)
                        if(x[i]==1)s=s+x[i];

                    if(ookk==0)
                        if(ras<s)ras=s;
                }
                else {k++;x[k]=0;}
            }
            else k--;
        }
        printf("Case #%d: %d\n",l,ras);
    }
    return 0;
}
