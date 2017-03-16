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

ll T,ca,a,b,n,i,j,k,l,p;


ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    read(T);
    REP(ca,1,T)
    {
        scanf("%I64d/%I64d",&a,&b);
        ll t=gcd(a,b);a/=t;b/=t;
        
        
        
        printf("Case #%d: ",ca);
        if((b&(b-1))!=0){printf("impossible\n");continue;}
        
        int cnt=0;
        while(1)
        {
            cnt++;if(cnt>40){printf("impossible\n");break;}
            if(a>=b/2){printf("%d\n",cnt);break;}
            b/=2;
        }
                
    }
    return 0;
}
