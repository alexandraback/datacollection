#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<list>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>

using namespace std;

struct node
{
       int x,y;
};

#define INF 10000000000000000LL
#define M 1000000007LL
typedef long long ll;
typedef list<int> li;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef pair<string,int> psi;

ll power(ll a,ll b)
{
        ll res=1,curr=a;
        if(a==0) return 0;
        if(b<0) return 0;
        while(b)
        {
                if(b&1) res=(res*curr)%M;
                curr=(curr*curr)%M;
                b>>=1;
        }
        return res;
}  

#define MXN 200010
#define pb push_back
#define mp make_pair
                       

int main()
{
    int t=1,s,i,cnt,rs;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    char a[1010];
    scanf("%d",&t);
    for(int ts=1;ts<=t;++ts)
    {
              scanf("%d",&s);
              scanf("%s",a);
              cnt=0,rs=0;
              for(i=0;i<=s;++i)
              {
                    if(a[i]>'0') 
                    {    
                         rs+=max(0,i-cnt);
                         cnt+=max(0,i-cnt);
                    }
                    cnt+=a[i]-'0';
              }
              printf("Case #%d: %d\n",ts,rs);
    }
}
                                              
                                            
                                               
              
                                          
