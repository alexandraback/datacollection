
#include<bitset>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;int f=1;
    while((c=getchar())<'0' || c>'9')if(c=='-')f=-1;
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res*f;
}
const int N=100010,MOD=1e9+7;
int cnt[2503];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T=in(),ca=1;
    while(T--)
    {
        int n=in();
        mem(cnt,0);
        int m=n*2-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) cnt[in()]++;
        }
        printf("Case #%d:",ca++);
        for(int i=1;i<=2500;i++)
        {
            if(cnt[i] & 1)
            {
                printf(" %d",i);
            }
        }
        puts("");
    }
    return 0;
}
