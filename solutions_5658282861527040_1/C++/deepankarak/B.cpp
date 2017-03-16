#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cassert>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define vi vector < int >
#define pb push_back
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()

long long dp[31][2][2][2];

vi A,B,K;

ll solve(int bit,int fa,int fb,int fk)
{
   if(bit == 0)
   return 1;
   
   if(dp[bit][fa][fb][fk]!=-1)
   return dp[bit][fa][fb][fk];
   
   ll ret = 0;
   int i,j;
   for(i=0;i<2;i++)
   {
      for(j=0;j<2;j++)
      {
         int k = i&j;
         
         if( (!fa || (i <= A[bit-1]))
             && (!fb || (j <= B[bit-1]))
             && (!fk || (k <= K[bit-1])) )
         {
             ret += solve(bit-1,fa && (i == A[bit-1]),fb && (j == B[bit-1]),fk && (k == K[bit-1]));
         }
      }
   }
   
   return dp[bit][fa][fb][fk] = ret;
}

void print(vi v)
{
     int i;
     for(i=0;i<v.size();i++)
     cout<<v[i]<<" ";
     cout<<endl;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int a,b,k,i,j;
    int t,tc=1;
    scanf("%d",&t);
    while(t--)
    {
              memset(dp,-1,sizeof(dp));
              scanf("%d%d%d",&a,&b,&k);
              a--,b--,k--;
              ll ans = 0;
              A.resize(30);
              B.resize(30);
              K.resize(30);
              for(i=0;i<30;i++)
              {
                 A[i] = ((a&(1<<i))!=0);
              }
              for(i=0;i<30;i++)
              {
                 B[i] = ((b&(1<<i))!=0);
              }
              for(i=0;i<30;i++)
              {
                 K[i] = ((k&(1<<i))!=0);
              }
              ans = solve(30,1,1,1); 
              printf("Case #%d: %lld\n",tc++,ans);
    }
    //system("pause");
    return 0;
}
