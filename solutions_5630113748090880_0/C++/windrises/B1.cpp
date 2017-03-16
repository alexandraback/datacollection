#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<complex>
#define ft first
#define sd second
#define pb push_back
#define mkp make_pair
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)<(b)?(b):(a))
using namespace std;
typedef long long LL;
typedef pair<int,int> Pair;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
const int maxn=3000;
int n;
int cnt[maxn];
int ans[100];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        int m=n*2-1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int a;
                scanf("%d",&a);
                cnt[a]++;
            }
        }
        int p=0;
        for(int i=1;i<=2500;i++)
        {
            if(cnt[i]%2==1)
            {
                ans[++p]=i;
            }
        }
        printf("Case #%d: ",kase);
        for(int i=1;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n]);
    }
}
