/*
* Author: Ikshu Bhalla
* Language: C++
*/
#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define fori(s,e) for(i=s;i<=e;i++)
#define forj(s,e) for(j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int)x.size()
#define ln(s) s.length()
#define ppb pop_back
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define psi pair<string,int>
#define in(c,x) scanf("%"#c,&x)
#define out(c,x) printf("%"#c" ",x)
#define aa first
#define bb second
#define Endl endl
using namespace std;
int readint()
{
    int t=0;
    char c,ch;
    ch=getchar();
    if (ch=='-') c=getchar();
    else c=ch;
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        t=(t<<3)+(t<<1)+c-'0';
        c=getchar();
    }
    if (ch=='-' ) return -t;
    else return t;
}

bool is2(int x)
{
    return (x>0&&!(x&(x-1)));
}
int fun(int n,int d)
{
    if (2*n>=d) return 1;
    else return 1+fun(2*n,d);
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m,t;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("OutA.txt","w",stdout);
    scanf("%d",&t);
    int T=t;
    while(t--)
    {
        int p,q,flag=1,ans=0;
        scanf("%d/%d",&p,&q);
        if (!is2(q)) flag=0;
        else
        {
            if (p==1&&q==1) ans=0;
            else ans=fun(p,q);
        }
        cout<< "Case #"<<T-t<< ": ";
        if (flag) cout<<ans<<Endl;
        else cout<< "impossible"<<Endl;
    }
    return 0;
}
