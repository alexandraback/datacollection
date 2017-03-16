#include<cstdio>
#include<algorithm>

using namespace std;

int T;
int n;
int a[1010];
int vec[1010];

inline int pre(int i,int nn)
{
    i--;if(i==0)i=nn;
    return i;
}
inline int nxt(int i,int nn)
{
    i++;if(i>nn)i=1;
    return i;
}
inline bool check(int nn)
{
    for(int i=1;i<=nn;i++)
        if(a[vec[i]]!=vec[pre(i,nn)]&&a[vec[i]]!=vec[nxt(i,nn)])
            return false;
    return true;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        int N=1<<n,ans=1;
        for(int i=1;i<N;i++)
        {
            int temp=i;
            int nn=0,j=0;
            while(temp)
            {
                j++;
                if(temp&1)vec[++nn]=j;
                temp>>=1;
            }
            if(nn>ans)
            {
                sort(vec+1,vec+nn+1);
                bool flag=false;
                if(check(nn))flag=true;
                while(next_permutation(vec+1,vec+nn+1))
                {
                    if(check(nn))
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag)ans=nn;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
}
