#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>

#define ll long long
#define maxn 10005*26
#define inf 0x3f3f3f3f
#define bug puts("here")

using namespace std;

int T,L,n,m;
ll X;
char ch[maxn];
int sign[maxn],a[maxn];
int to1[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int to2[4][4]={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

bool judge(int a[],int len)
{

    int ret=1;
    int t,tt;
    t=a[0];
    tt=1;
    if(t==1)
        ret++;
    for(int i=1;i<len;++i)
    {
        int j=a[i];
        //cout<<tt<<' '<<t<<' '<<j<<endl;
        tt*=to2[t][j];
        t=to1[t][j];
        if(i==len-1){
            if(ret==3&&tt==-1&&t==0)
                return true;
        }
        else if(ret==1){
            if(tt==1&&t==1)
                ret++;
        }
        else if(ret==2)
        {
            if(tt==1&&t==3)
                ret++;
        }
    }
    return false;
}
int work(int a[],int len)
{

    int ret=1;
    int t,tt;
    t=a[0];
    tt=1;
    for(int i=1;i<len;++i)
    {
        int j=a[i];
        tt*=to2[t][j];
        t=to1[t][j];
    }
    n=tt;m=t;
    //cout<<tt<<' '<<t<<endl;
    for(int i=1;;i++)
    {
        if(tt==1&&t==0)
            return i;
        tt*=to2[t][m]*n;
        t=to1[t][m];
        if(i>10)
        {
            bug;
            return 10;
        }
    }
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
   cin>>T;
   int kase=1;
   while(T--){
    cin>>L>>X;
    scanf(" %s",ch);
    int len=L;
    for(int i=0;i<len;++i)
    {
        if(ch[i]=='i')
            a[i]=1;
        else if(ch[i]=='j')
            a[i]=2;
        else a[i]=3;
    }
    bool ans=0;
    int x=work(a,len);
    for(int i=1;i<=min(25LL,X)&&!ans;++i)
        if((X-i)%x==0){
            int totlen=len*i;
            for(int j=len;j<totlen;++j)
                a[j]=a[j%len];
            ans|=judge(a,totlen);
        }
    if(ans)
        printf("Case #%d: YES\n",kase++);
    else printf("Case #%d: NO\n",kase++);
   }
}
