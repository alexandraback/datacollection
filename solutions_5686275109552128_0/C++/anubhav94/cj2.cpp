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
     freopen("B-small-attempt0.in","r",stdin);
     freopen("B-small-attempt0.out","w",stdout);
     int t,d,i,rs,curr,x;
     scanf("%d",&t);
     int a[1010],mx[1010];
     for(int ts=1;ts<=t;++ts)
     {
             scanf("%d",&d);
             memset(a,0,sizeof(a));
             rs=0;
             for(i=0;i<d;++i) 
             {
                  scanf("%d",&x);
                  a[x]++;
             }
             mx[0]=0;
             for(i=1;i<1010;++i)
             {
                if(a[i]>0) mx[i]=i;
                else mx[i]=mx[i-1];
             }
             rs=mx[1001];
             curr=0;
             for(i=1001;i>=0&&curr<rs;--i)
             {
                      if(a[i]>0)
                      {                    
                             curr+=a[i]; 
                             if(i&1) 
                             {
                                     a[i>>1]+=a[i];
                                     a[(i>>1)+1]+=a[i];
                             }
                             else
                                    a[i>>1]+=(a[i]<<1);
                             for(int j=i>>1;j<i;++j)
                                 if(a[j]>0) mx[j]=j;
                                 else mx[j]=mx[j-1];
                             rs=min(rs,curr+mx[i-1]);
                      }
             }
             printf("Case #%d: %d\n",ts,rs);
     }
}                               
             
