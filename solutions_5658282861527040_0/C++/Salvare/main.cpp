#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[200],lib[200],te[200];
int cnt[200][200];
int sb[200];
void cal(int z,char s[],char t[])
{
    int k=1;t[0]=s[0];cnt[z][0]=1;
    for(int i=1;s[i];i++)
        if(t[k-1]==s[i])cnt[z][k-1]++;
        else t[k]=s[i],cnt[z][k++]=1;
    t[k]=0;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int a,b,k,cnt=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                if((i&j)<k)cnt++;
        printf("Case #%d: %d\n",ti++,cnt);
    }
    return 0;
}
