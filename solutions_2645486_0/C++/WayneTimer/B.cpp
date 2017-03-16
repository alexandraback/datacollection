#include <cstdio>
#include <queue>

using namespace std;

struct eugin
{
  long long v,g;
  int u;
};

priority_queue <eugin> q;
long long E,R,ans;
int n;

bool operator < (eugin e,eugin r)
{
  if (e.v<r.v) return true;
  if (e.v==r.v)
    if (e.u>r.u) return true;
  return false;
}

inline void work()
{
  long long x;
  eugin t;
  int i,y;
  while (!q.empty()) q.pop();
  scanf("%lld",&t.v);
  t.g=R;
  t.u=1;
  q.push(t);
  ans+=t.v*R;
  y=0;
  for (i=2;i<=n;i++)
  {
    x=R;
    scanf("%lld",&t.v);
    t.g=0;
    t.u=i;
    q.push(t);
    while (x)
    {
      do
      {
        t=q.top();
        q.pop();
      } while (t.u<=y);
      if (t.g+x<E)
      {
        ans+=x*t.v;
        t.g+=x;
        x=0;
        q.push(t);
      }
      else
      {
        ans+=t.v*(E-t.g);
        x-=E-t.g;
        y=t.u;
      }
    }
  }
  x=E-R;
  while (x)
  {
    do
    {
      t=q.top();
      q.pop();
    } while (t.u<=y);
    if (t.g+x<=E)
    {
      ans+=x*t.v;
      x=0;
    }
    else
    {
      ans+=t.v*(E-t.g);
      x-=E-t.g;
      y=t.u;
    }
  }
}

int main()
{
  int T,o;
  long long x;
  freopen("B-small-attempt2.in","r",stdin);
  freopen("B_ans_small.txt","w+",stdout);
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    scanf("%lld%lld%d",&E,&R,&n);
    ans=0;
    if (R>=E)
    {
      while (n--)
      {
        scanf("%lld",&x);
        ans+=x*E;
      }
    }
    else
      work();
    printf("Case #%d: %lld\n",o,ans);
  }
  return 0;
}
