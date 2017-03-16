#include <bits/stdc++.h>

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long 
#define elif else if
#define pii pair<ll int,ll int>
#define mp make_pair
#define pb push_back
using namespace std;


int n,r,c,ans;
void foo(vector< vector<int> >mat,int num)
{
  int i,j,tem=0;
   if(num==n)
  {
    for(i=1;i<=r;i++)
    {
      for(j=1;j<=c;j++)
      {
        if(!mat[i][j])continue;
        if(mat[i-1][j])
          tem++;
        if(mat[i][j-1])
          tem++;
      }
    }
    ans=min(tem,ans);
    return;
  }
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=c;j++)
    {
      if(mat[i][j])continue;
      mat[i][j]=1;
      foo(mat,num+1);
      mat[i][j]=0;
    }
  }
  return;
}
void boo(vector< vector<int> >mat,int num)
{
  int i,j,tem=0;
   if(num==n)
  {
    for(i=1;i<=r;i++)
    {
      for(j=1;j<=c;j++)
      {
        if(mat[i][j])continue;
        if(!mat[i-1][j] && i>1)
          tem++;
        if(!mat[i][j-1] && j>1)
          tem++;
        /*if(!mat[i+1][j])
          tem++;
        if(!mat[i][j+1])
          tem++;*/
      }
    }
    ans=min(tem,ans);
   // cout<<tem<<" "<<n<<"\n";
    return;
  }
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=c;j++)
    {
      if(mat[i][j])continue;
      mat[i][j]=1;
      boo(mat,num+1);
      mat[i][j]=0;
    }
  }
  return;
  } 
int main()
{
  freopen("int","r",stdin);
  freopen("out","w",stdout);
  std::ios::sync_with_stdio(false);
  int T,t;
  cin>>T;
  for (t=1;t<=T;t++)
  {
    ll int i,j,n,sa,sb,da,db,ta,tb;
    int ans;
   ll int ta1,ta2,tb1,tb2;
     cin>>n;
     if(n==1)
     {
      ll int a,b,c;
      cin>>a>>b>>c;
      sa=c;
      sb=c+1;
      if(   (360-a) < 360*sb  )
        ans=0;
      else
        ans=1;
     }
     else
     {
         ll int a,b,c,d,e,f;
          cin>>a>>b>>c>>d>>e>>f;
          da=360-a;
          db=360-d;
          sa=c;
          sb=f;
          if(da<db)
          {
            swap(da,db);
            swap(sa,sb);
          }
          if(da==db)
          {
            if(sa>sb)swap(sa,sb);
          }
          if(  da*(sb-sa) < sa*(360-(da-db)))
            ans=0;
          else
            ans=1;
       
     }
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}