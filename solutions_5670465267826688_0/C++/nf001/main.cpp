#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define N 200000
#define M 1001
char s[N],ts[N];
int pre[N],suf[N];
int as[5][5]=   {
                 0,0,0,0,0,
                 0,1,2,3,4,
                 0,2,-1,4,-3,
                 0,3,-4,-1,2,
                 0,4,3,-2,-1
                };
int mp[255];
int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    mp['i']=2;mp['j']=3;mp['k']=4;
    int T,cas=0,n;
    cin>>T;
    while (T--)
    {
        int L,X,t=0;
        scanf("%d%d",&L,&X);
        scanf("%s",ts);
        if (X>12)   X-=(X-12)/4*4;
    //    cout<<X<<endl;
        for (int i=1;i<=X;i++)
            for (int j=0;j<L;j++)
            s[t++]=ts[j];
        s[t]='\0';
   //     puts(s);
        pre[0]=mp[s[0]];
        int ok=X*L,yes=0;
        if (pre[0]==2) ok=0;
  //      cout<<pre[0]<<endl;
        for (int i=1;i<X*L;i++)
        {
            if (pre[i-1]<0)
                pre[i]=-as[-pre[i-1]][mp[s[i]]];
            else
                pre[i]=as[pre[i-1]][mp[s[i]]];
            if (pre[i]==2 && ok==X*L) ok=i;
       //     cout<<'!'<<pre[i]<<endl;
        }
  //      cout<<ok<<endl;
        suf[X*L-1]=mp[s[L-1]];
        for (int i=X*L-1;i>(X-4)*L && i>=0;i--)
        {
            if (i<X*L-1)
            {
                if (suf[i+1]<0)
                    suf[i]=-as[mp[s[i]]][-suf[i+1]];
                else
                    suf[i]=as[mp[s[i]]][suf[i+1]];
            }
            if (suf[i]==4 && pre[i-1]==4 && i-1>ok)
            {
                yes=1;
                break;
            }
        }
        printf("Case #%d: ",++cas);
        if (!yes) puts("NO");
        else puts("YES");
    }
}
