#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int s[35];
int n,p[13]={0,2,3,5,7,11,13,17,19,23,29,31},mo[13],ans[13];

void get_s(int x)
{
    s[0]=s[n-1]=1;
    for(int i=1;i<n-1;i++)
        s[i]=(x&(1<<(i-1)))>>(i-1);
}

void Print()
{
    for(int i=0;i<n;i++)
        printf("%d",s[i]);
    printf(" ");
}

int main()
{
    int T,m,x,k,i,j,flag;
    freopen("Clarge.out","w",stdout);
    cin>>T;
    printf("Case #1:\n");
    cin>>n>>m;

    for(x=0;x<(1ll<<(n-1))&&m;x++)
    {
        get_s(x);
        flag=1;
        memset(ans,0,sizeof(ans));
        for(k=2;k<=10;k++)
        {
            memset(mo,0,sizeof(mo));
            for(i=0;i<n;i++)
                for(j=1;j<=11;j++)
                {
                    mo[j]=(mo[j]*k+s[i])%p[j];
                    //if(j==2)
                        //debug(mo[2]);
                }
            //debug(x);
            //debug(mo[2]);
            for(j=1;j<=11;j++)
                if(mo[j]==0)
                {
                    ans[k]=p[j];
                    break;
                }
            if(ans[k]==0)
                flag=0;
        }
        if(flag!=0)
        {
            Print();
            for(k=2;k<=10;k++)
                printf("%d ",ans[k]);
            cout<<endl;
            m--;
        }
        //else debug(233);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
