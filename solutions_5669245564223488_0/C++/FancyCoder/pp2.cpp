#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<bitset>
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,x,y) for(i=x;i<=y;i++)
#define _rep(i,x,y) for(i=x;i>=y;i--)
#define REP(i,x,y) for(int i=(x);i<=(y);i++)
#define _REP(i,x,y) for(int i=(x);i>=(y);i--)
#define CL(S,x) memset(S,x,sizeof(S))
#define CP(S1,S2) memcpy(S1,S2,sizeof(S2))
#define ALL(x,S) for(x=S.begin();x!=S.end();x++)
#define pb push_back
#define IN insert
#define ER erase
#define BE begin()
#define ED end() 
#define LB lower_bound
#define UB upper_bound
#define mp make_pair
#define fi first
#define se second
#define upmin(x,y) x=min(x,y)
#define upmax(x,y) x=max(x,y)
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
inline char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int T,ca,n,i,j,k,p,ans;int st[111],l[111];
char s[111][1111];bool vis[111];
int la[30];
bool check()
{
    int i,j,p,c,tot=0;
    CL(la,0);
    rep(i,1,n)
    {
        p=st[i];
        rep(j,1,l[p])
        {
            c=s[p][j]-'a';
            if(la[c]==0||la[c]==tot);
            else return 0;
            la[c]=++tot;
        }
    }
    return 1;
}
void dfs(int i)
{
    if(i>n)
    {
        if(check())ans++;
        return;
    }
    for(int j=1;j<=n;j++)if(!vis[j])
    {
        vis[j]=1;st[i]=j;
        dfs(i+1);
        vis[j]=0;
    }
    
}
int main()
{
    freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	read(T);
	rep(ca,1,T)
	{
        read(n);
        ans=0;
        rep(i,1,n)scanf("%s",s[i]+1),l[i]=strlen(s[i]+1);
        CL(vis,0);
        dfs(1);
        printf("Case #%d: %d\n",ca,ans);
    }
	
    return 0;
}
