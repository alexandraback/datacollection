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
                       
char a[MXN];

int mod(int a)
{
    if(a>0) return a;
    return -a;
}

int num(char c)
{
    if(c=='i') return 2;
    if(c=='j') return 3;
    return 4;
}

int main()
{
        freopen("C-large.in","r",stdin);
        freopen("C-large.out","w",stdout);
        int t,i,l,fnd,curr,sgn,nm,prd[5][5];
        ll x;
        scanf("%d",&t);
        prd[1][1]=1;
        prd[1][2]=2;
        prd[1][3]=3;
        prd[1][4]=4;
        
        prd[2][1]=2;
        prd[2][2]=-1;
        prd[2][3]=4;
        prd[2][4]=-3;
        
        prd[3][1]=3;
        prd[3][2]=-4;
        prd[3][3]=-1;
        prd[3][4]=2;
        
        prd[4][1]=4;
        prd[4][2]=3;
        prd[4][3]=-2;
        prd[4][4]=-1;
        for(int ts=1;ts<=t;++ts)
        {
                scanf("%d%lld",&l,&x);
                if(x>12)
                {
                        x-=12;
                        x%=4;
                        x+=12;
                }
                scanf("%s",a);
                i=-1;
                for(fnd=2;fnd<=3;++fnd)
                {
                   //cout<<"fnd: "<<fnd<<endl;
                   curr=1;
                   sgn=1;
                   for(++i;i<(l*x);++i)
                   {
                      nm=num(a[i%l]);              
                      sgn=sgn*prd[curr][nm]/mod(prd[curr][nm]);
                      curr=mod(prd[curr][nm]);
                    //  cout<<"i: "<<i<<" curr: "<<curr<<endl;
                      if(curr==fnd && sgn==1) break;
                   }
                }
                ++i;
                bool poss=0;
                if(i<l*x)
                {
                         curr=1;
                         sgn=1;
                         for(;i<(l*x);++i)
                         {
                             nm=num(a[i%l]);
                             sgn=sgn*prd[curr][nm]/mod(prd[curr][nm]);
                             curr=mod(prd[curr][nm]);
                         }
                         if(curr==4 && sgn==1) poss=1;
                }    
                if(poss) printf("Case #%d: YES\n",ts);
                else     printf("Case #%d: NO\n",ts);
        }
}   
                                 
