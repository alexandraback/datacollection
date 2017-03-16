#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cmath>
inline long long Input(){
    long long ret=0;bool isN=0;char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') isN=1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return isN?-ret:ret;
}

inline void Output(long long x){
    if(x<0){
        putchar('-');x=-x;
    }
    int len=0,data[20];
    while(x){
        data[len++]=x%10;x/=10;
    }
    if(!len)    data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}
#pragma comment(linker,"/STACK:124000000,124000000")
#include<map>
#include<vector>
#include<queue>
#include<set>
#include <bitset>
#define eps 1e-6
#define INF 2147483647
#define maxn  1005
#define maxm 1000005
#define mod  20090717
#define llINF 9023372036854775807LL
#define In freopen("solve_in.txt", "r", stdin);
#define Out freopen("solve_out.txt", "w", stdout);
#define HASH 100009
#define totnum 26
const double PI=acos(-1.0);
using namespace std;

long long ten[20];
long long a[20];
long long rev(long long x)
{
    int len=0;
    while(x)
    {
        a[len++]=x%10;
        x=x/10;
    }
    long long ans=0;
    for(int i=0;i<len;i++)
    {
        ans=ans*10+a[i];
    }
    return ans;
}
int getlen(long long x)
{
    int len=0;
    while(x)
    {
        a[len++]=x%10;
        x=x/10;
    }
    return len;
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    ten[0]=1;
    for(int i=1;i<20;i++)
        ten[i]=ten[i-1]*10;
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        long long n;
        cin>>n;
        long long ans=0;
        for(int i=1;i<20;i++)
        if(n==ten[i]){
            ans++;
            n--;
            break;
        }
        while(n>21)
        {
            int l=getlen(n);
            ans+=n%ten[(l+1)/2];
            //printf("%d %d %I64d\n",l,(l+1)/2,ten[(l+1)/2]);
            n-=n%ten[(l+1)/2]-1;
            n=rev(n);
            if(n%ten[(l+1)/2]==1) ans--;
            ans+=n%ten[(l+1)/2];
            n-=n%ten[(l+1)/2];
            ans++;n--;
        }
        ans+=n;
        printf("Case #%d: %lld\n",kase,ans);
    }
    return 0;
}
