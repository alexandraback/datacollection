#include <bits/stdc++.h>
using namespace   std;



#define mod 1000000009
#define si 1000001
#define f first
#define s second
#define rep(i,n) for(i=1;i<=n;i++)
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rep2(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define v2(x) vector< vector <int> > x
#define print(x) printf("%d\n",x)

#ifdef ONLINE_JUDGE
#define gc getchar_unlocked
#else
#define gc getchar
#endif

inline int scan(){
    char c = gc();
    int x = 0;
    bool b=0;
    while(c<'0'||c>'9'){
        {
            if(c=='-')
            b=1;
            c=gc();

        }
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=gc();
    }
    if(b==1)
        x*=-1;
    return x;
}
int dist[si],vi[si]={0};
int rev(int uu)
{
int p=0;

  while(uu>0)
  {
   p*=10;
   p+=uu%10;
   uu/=10;

  }
  return p;
}
int main() {

int t,n,i,j,u,v,p,uu;
freopen("A-small-attempt0 (1).in","r",stdin);
freopen("AAAs.out","w",stdout);
cin>>t;

rep(j,t)
{
 cin>>n;
 rep(i,n)
 dist[i]=n;

 memset(vi,0,sizeof(vi));

 vi[1]=1;

 queue<int> q;
dist[1]=1;
 q.push(1);

 while(!q.empty())
 {
  u=q.front();

  q.pop();

  if(vi[u+1]==0&&u<=n)
  {
   vi[u+1]=1;
   dist[u+1]=dist[u]+1;
   q.push(u+1);
  }

 p=rev(u);



  if(vi[p]==0&&p<=n)
  {
   vi[p]=1;
   dist[p]=dist[u]+1;
   q.push(p);
  }


 }
 printf("Case #%d: %d\n",j,dist[n]);
}

}
