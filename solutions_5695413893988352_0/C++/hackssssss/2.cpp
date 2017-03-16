
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
int cnt1[1234],cnt2[1234];

void dfs(int pos,int n,int sum,int *cnt,string &a)
{
    if(pos==n)
    {
        cnt[sum]=1;
        //cout<<"sum=="<<sum<<endl;
        return;
    }
    if(a[pos]!='?')
    {
        sum = sum*10+a[pos]-'0';
        dfs(pos+1,n,sum,cnt,a);
    }
    else{
        for(int i=0;i<10;i++)
        {
            dfs(pos+1,n,sum*10+i,cnt,a);
        }
    }
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("in.txt","w",stdout);
    int T=in(),ca=1;

    while(T--)
    {
        string a,b;
        cin>>a>>b;
        int n=a.size();
        mem(cnt1,0);
        mem(cnt2,0);
        dfs(0,n,0,cnt1,a);
        dfs(0,n,0,cnt2,b);
        int ans1=inf*2,ans2=inf;
        for(int i=0;i<1000;i++)
        {
            for(int j=0;j<1000;j++)
            {
                if(cnt1[i] && cnt2[j])
                {
                    if(abs(j-i) < abs(ans1-ans2))
                    {
                        ans1=i,ans2=j;
                    }
                    else if(abs(j-i) == abs(ans1-ans2) && j<ans2)
                    {
                        ans1=i,ans2=j;
                    }
                }
            }
        }
        if(n==1)printf("Case #%d: %01d %01d\n",ca++,ans1,ans2);
        if(n==2)printf("Case #%d: %02d %02d\n",ca++,ans1,ans2);
        if(n==3)printf("Case #%d: %03d %03d\n",ca++,ans1,ans2);

    }
    return 0;
}
