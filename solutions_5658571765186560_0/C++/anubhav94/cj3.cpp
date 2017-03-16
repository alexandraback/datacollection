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
           freopen("D-small-attempt0.in","r",stdin);
           freopen("D-small-attempt0.out","w",stdout);
           int t,x,r,c,i,j;
           scanf("%d",&t);
           for(int ts=1;ts<=t;++ts)
           {
                  scanf("%d%d%d",&x,&r,&c);
                  if(r<c) swap(r,c);
                  printf("Case #%d: ",ts);
                  if(x==1) printf("GABRIEL\n");
                  else if(x==2)
                  {
                       if((r*c)&1) printf("RICHARD\n");
                       else printf("GABRIEL\n");
                  }
                  else if(x==3)
                  { 
                       if(((r*c)%3)!=0) printf("RICHARD\n");
                       else if(c==1) printf("RICHARD\n");
                       else printf("GABRIEL\n");
                  }
                  else 
                  {
                       if(((r*c)%4)!=0) printf("RICHARD\n");
                       else if(r==2) printf("RICHARD\n");
                       else if(c<=2) printf("RICHARD\n");
                       else  printf("GABRIEL\n");
                  }
           }
 }
