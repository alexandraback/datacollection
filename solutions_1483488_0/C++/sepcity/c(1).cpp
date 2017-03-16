#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int num[2011010];
char c[10],t[10];
int ten[10]={1,10,100,1000,10000,100000,1000000};
int mn,mx;
int vert[10];
int Get(int n)
{
    int v=0;
    int res=0;
    sprintf(c,"%d",n);
    //int len=strlen(c);
    int len=(int)log10(n+0.1)+1;

    for(int i=1;i<len;i++)
    {
        /*
        if(c[len-i]=='0') continue;
        for(int j=len-i;j<len;j++)
        {
            t[j-len+i]=c[j];
        }
        for(int j=0;j<len-i;j++)
        {
            t[j+i]=c[j];
        }
        t[len]=0;
        int tmp;
        sscanf(t,"%d",&tmp);
        */
        int tmp=n/ten[i]+n%ten[i]*ten[len-i];
        if(tmp>n && tmp<=mx)
        {
            vert[v++]=tmp;
        }
    }
    sort(vert,vert+v);
    return (int*)unique(vert,vert+v)-vert;
}
int main()
{
    freopen("C-small-attempt0(1).in","r", stdin);
    freopen("C-small-attempt0(1).out", "w", stdout);
    int cases;
    scanf("%d",&cases);
    for(int ca=1;ca<=cases;ca++)
    {
        scanf("%d%d",&mn,&mx);
        int res=0;
        for(int i=mn;i<mx;i++)
        {
            res+=Get(i);
        }
        printf("Case #%d: %d\n",ca,res);
    }
}
