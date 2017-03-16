#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<time.h>
#include<queue>
#include<deque>
#define Pi 3.1415926535897932384626433832795
#define INF 1000000000
#define Ppi 67
#define MA(a,b) (a>b?a:b)
#define MI(a,b) (a<b?a:b)
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
using namespace std;
bool BO=1;
int A,AN,M,k,n,m,I,in,i,j,e,f;
int a[10000000];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("text.txt","w",stdout);

   cin>>m;
   for (int T=1;T<=m;T++)
   {
       cin>>A>>n;
       AN=n;
       for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
       sort(a+1,a+n+1);
       k=0;
       if (A>1)
       for (i=1;i<=n;i++)
       {
           if (a[i]>=A)
                while (A<=a[i]){k++;A+=(A-1);}
           A+=a[i];
           AN=MI(AN,n-i+k);
       }
       cout<<"Case #"<<T<<": "<<AN<<endl;
   }
    return 0;
}
