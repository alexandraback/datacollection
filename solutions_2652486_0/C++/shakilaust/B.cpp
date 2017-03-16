//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::   TC  1 Round (small C)
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int a[20],res[5],maxi,R,M,N,K,cc=0;
bool flag;
void cal()
{     int i,j,k,r;
      //printf("cc:: %d\n",cc++);
       for(i=2;i<=M;i++)
         for(j=2;j<=M;j++)
           for(k=2;k<=M;k++)
              if(i*j*k==maxi)
              {
                     res[0]=i,res[1]=j,res[2]=k;
                    // printf("eikhane\n");
                     flag=true;
                     return ;
              }
              //else if(i*j*k>(a[r])) break;

}


int main()
{

   //  freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i,t;
    cin>>t;
    puts("Case #1:");
    cin>>R>>N>>M>>K;
    while(R--)
    {
           int b[10]={0},c[10]={0};
           vector <int> v;
           maxi=-1;
           rep(i,K)
           {
                  cin>>a[i];
                  maxi=max(maxi,a[i]);
                  if(a[i]<=M)
                  { b[a[i]]++;
                    if(a[i]>=2 && a[i]<=M)
                    c[a[i]]++;
                  }
           }
           int ct=0;
           flag=false;
           cal();
            if(flag)
           printf("%d%d%d\n",res[0],res[1],res[2]);
           else if(b[i]==K) puts("222");
             else if(c[2]==1 && c[3]==1 && c[4]==1) printf("234\n");
            else if(c[2]==1 && c[3]==1 && c[5]==1) printf("235\n");
           else if(c[3]==1 && c[5]==1 && c[4]==1) printf("345\n");

           else { // printf("here\n");
                  int mxx=-1,val;
                  for(i=2;i<=M;i++)
                  {
                         if(mxx<c[i])
                         {
                                val=i;
                                mxx=c[i];
                         }
                  }
                  if(mxx==3) printf("%d%d%d\n",val,val,val);

                  //else if(c[4]==2 && (c[3]==1 || c[3]==2)) printf("223\n");
                  else if(mxx==2) printf("%d%d%d\n",val,val,val==M?val-1:val+1);
                  else puts("234");
                }

           }



}
