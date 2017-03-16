#include<cstdio>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;++i)
using namespace std;
typedef long long LL;
const int mn=20100,ml=20;
int f[mn][ml],log[mn],bi[ml];
int v[mn];
int n,E,R;
LL ans=0;
bool cmp(int i,int j){return v[i]<v[j]||v[i]==v[j];}
void rmq()
{
    int i,j;
    fo(i,1,n)f[i][0]=i;
    fo(j,1,log[n])
        fo(i,1,n-bi[j]+1)
            f[i][j]=max(f[i][j-1],f[i+bi[j-1]][j-1],cmp);
}
int query(int i,int j)
{
    int k=log[j-i+1];
    return max(f[i][k],f[j-bi[k]+1][k],cmp);
}
void calc(int l,int r,int st,int ed)
{
    int k=query(l,r);
    LL now=min((LL)E,st+(LL)(k-l+1)*R),low=max(0LL,ed-(LL)R*(r-k+1));
    LL co=now-low;
    ans+=co*v[k];
    if(k>l)calc(l,k-1,st,now);
    if(k<r)calc(k+1,r,low,ed);

}
int main()
{
    int Q,T,i;
    scanf("%d",&Q);
    fo(i,2,10000)log[i]=log[i/2]+1;
    fo(i,0,19)bi[i]=1<<i;
    fo(T,1,Q)
    {
        scanf("%d%d%d",&E,&R,&n);
        fo(i,1,n)scanf("%d",v+i);
        rmq();
        ans=0;
        calc(1,n,E,0);
        printf("Case #%d: ",T);
        cout<<ans<<endl;
    }
    return 0;
}
