#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<queue>
#include <iterator>
#include <deque>
#define Pi 3.141592
#define E 0.000001
#define P 1000000009ll
#define MA(a,b) (a>b?a:b)
#define MI(a,b) (a<b?a:b)
#define minn min_element
#define maxx max_element
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pf push_front
#define S size
using namespace std;
int n,m,p,i,j,k,SZ,T;
int v[10000009];
long long I;

   FILE *fi=freopen("C-large-1.in","r",stdin);
   FILE *fo=freopen("text.txt","w",stdout);
 bool pa(long long X)
 {
      if (X%10==0) return 0;
      long long Y=X,Z=0;
      while (Y)
      {
            Z=Z*10+Y%10;
            Y/=10;
            }
            return X==Z;
      }
int d(long long X)
{
    long long L=0;
    long long R=10000000;
    while (L<R)
    {
          long long Z=(L+R)/2;
          if (Z*Z>X) R=Z-1; else L=Z;
          if (L+1==R)
          {
                     if (R*R<=X) L=R;
                     R=L;
                     }   
          }
           
          return v[L];
     }
int main()
{
     for (I=1;I<=10000000;I++)
    {v[I]=v[I-1];
         if (pa(I))
    if (pa(I*I))
    v[I]=v[I-1]+1;
}
    int t;
     cin>>t;
    while (t--)
    {
          k++;
          long long A,B;
          cin>>A>>B;
          cout<<"Case #"<<k<<": "<<d(B)-d(A-1)<<endl; 
          }
    return 0;
}
