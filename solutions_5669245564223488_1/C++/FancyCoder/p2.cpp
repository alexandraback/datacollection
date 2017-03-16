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

const int mod=int(1e9)+7;
int T,n,i,z,j,k,l,p,ca;
char s[111111];
bool can[30],ok[30];
int cnt[30],next[30];
bool vis[30];
ll fac[111];

int main()
{
    freopen("1.in","r",stdin);
    freopen("x.out","w",stdout);
    fac[0]=1;rep(i,1,100)fac[i]=fac[i-1]*i%mod;
    read(T);
    rep(ca,1,T)
    {
        printf("Case #%d: ",ca);
        read(n);
        
        CL(can,1);CL(cnt,0);CL(next,-1);CL(ok,0);
        bool yes=1;
        rep(z,1,n)
        {
            scanf("%s",s+1);l=strlen(s+1);
            rep(i,1,l)if(!can[s[i]-'a']){yes=0;continue;}
            for(i=1;i<=l&&s[i]==s[1];i++);
            if(i>l){ok[s[1]-'a']=1;cnt[s[1]-'a']++;continue;}
            for(j=l;j>=1&&s[j]==s[l];j--);
            rep(k,i,j)can[s[i]-'a']=0;
            
            if(next[s[1]-'a']!=-1){yes=0;continue;}
            next[s[1]-'a']=s[l]-'a';
            
            rep(i,1,l){int cnt=1,same=0;rep(j,i+1,l)if(s[i]==s[j]){++same;if(cnt>1&&same>1){yes=0;break;}}else if(s[i]!=s[j])cnt++;}
            
        }
        CL(vis,0);int g=0;
		rep(z,0,25)if(next[z]>=0||ok[z])
		if(!can[z]){yes=0;break;}
        rep(z,0,25)if((next[z]>=0)&&(!vis[z]))
        {
            vis[z]=1;
            for(p=next[z];p>=0&&p!=z;p=next[p])
            vis[p]=1;
            if(p>=0&&p==z){yes=0;break;}
        }
        rep(z,0,25)if(vis[z]&&(next[z]==-1))g++;
        rep(z,0,25)if(ok[z]&&(!vis[z]))g++;
        if(!yes){printf("0\n");continue;}
        
        ll res=fac[g];rep(i,0,25)res=res*fac[cnt[i]]%mod;
        cout<<res%mod<<endl;
        
    }	
    return 0;
}
