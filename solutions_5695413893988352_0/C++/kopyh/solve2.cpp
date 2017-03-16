//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 1123456
using namespace std;
int n,m,sum,res,flag;
char s[N];
int a[200];
int b[10];
int main()
{
//    #ifndef ONLINE_JUDGE
//        freopen("in.in","r",stdin);
//        freopen("out.out","w",stdout);
//    #endif
    int i,j,k,cas,T,t,x,y,z;
    scanf("%d",&T);
    cas=0;
    while(T--)
//    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        n=strlen(s);
        a[0]=s[n-1]=='?'?10:s[n-1]-'0';
        if(n-2>=0)a[1]=s[n-2]=='?'?10:s[n-2]-'0';
        else a[1]=0;
        if(n-3>=0)a[2]=s[n-3]=='?'?10:s[n-3]-'0';
        else a[2]=0;
        scanf("%s",s);
        m=strlen(s);
        b[0]=s[m-1]=='?'?10:s[m-1]-'0';
        if(m-2>=0)b[1]=s[m-2]=='?'?10:s[m-2]-'0';
        else b[1]=0;
        if(m-3>=0)b[2]=s[m-3]=='?'?10:s[m-3]-'0';
        else b[2]=0;
//        printf("%d %d %d %d %d %d\n",a[0],a[1],a[2],b[0],b[1],b[2]);
        x=0;y=INF;
        for(i=0;i<1000;i++)
            for(j=0;j<1000;j++)
            {
                if(a[0]==10||i%10==a[0])
                    if(a[1]==10||i/10%10==a[1])
                        if(a[2]==10||i/100%10==a[2])
                            if(b[0]==10||j%10==b[0])
                                if(b[1]==10||j/10%10==b[1])
                                    if(b[2]==10||j/100%10==b[2])
                                    {
//                                        printf("%d %d",i,j);
                                        if(abs(i-j)<abs(x-y)||abs(i-j)==abs(x-y)&&i+j<x+y)
                                            {
                                                x=i;y=j;
//                                                printf("   %d %d",x,y);
                                            }
//                                        printf("\n");
                                    }
            }
        printf("Case #%d: ",++cas);
        if(n==3&&x<10)printf("00");
        else if(n==3&&x<100||n==2&&x<10)printf("0");
        printf("%d ",x);
        if(m==3&&y<10)printf("00");
        else if(m==3&&y<100||m==2&&y<10)printf("0");
        printf("%d\n",y);

    }
    return 0;
}
