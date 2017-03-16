#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef long double LD;
const int N = 1000+5;
int n;
LD a[ N ], b[ N ];

set< int > se;
int main()
{
   //freopen("D-small-attempt0.in", "r", stdin);
   //freopen("D-small-attempt0.out", "w", stdout);
   //freopen("input.txt", "r", stdin);
   int T = 0, te = 0;
   cin>>T;
   while(T--)
   {
      ++ te;
      cout<<"Case #"<<te<<": ";
      cin>>n;
      for(int i = 1; i <= n; ++ i)
      cin>>a[i];
      for(int i = 1; i <= n; ++ i)
      cin>>b[i];

      se.clear();
      for(int i = 1; i <= n; ++ i)
      se.insert( i );

      sort(a+1, a+n+1);
      sort(b+1, b+n+1);
      int s1 = 1, f1 = n, s2 = 1, f2 = n;
      int q2 = 0;
      while(s1 <= f1)
      {
         if(a[f1] > b[f2])
         {
            --f1;
            --f2;
            continue;
         }

         if(a[s1] < b[f2])
         {
            ++ s1;
            -- f2;
            ++ q2;
         }
         else
            break;
      }

      int s = 1;
      int q1 = 0;
      for(int i = 1; i <= n; ++ i)
      {
         while(s <= n)
         {
            if(a[i] < b[s])
               break;
            ++ s;
         }
         if(s <= n)
         {
            ++ q1;
            ++ s;
         }
      }
      cout<<n-q2<<" "<<n-q1<<endl;
   }
   return 0;
}
