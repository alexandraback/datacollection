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
int AN,M,k,n,m,I,x,y,in,i,j,e,f;
int a[10000000];
double S,D,A,FA[100000],O[5200][5200];
int SK,K[100000],OK[5200][5200];
void mi(double &a,int &aa,double b,int bb)
{
    while (bb<aa) {bb++;b/=10;}
    a+=b;
}
int main()
{
    freopen("B-small-attempt5.in","r",stdin);
    freopen("text2.txt","w",stdout);
   cin>>m;
   for (int T=1;T<=m;T++)
   {
       A=0;
       cin>>n>>x>>y;
 //  cout<<n<<" "<<x<<" "<<y<<endl;
         x=abs(x);
       M=0;
       for (i=0;i<(x+y)/2 && M<n;i++)
        M+=i*4+1;
       if (M+(x+y)*2+1<=n)  cout<<"Case #"<<T<<": 1.000000"<<endl; else
       if (x==0)  cout<<"Case #"<<T<<": 0.000000"<<endl; else
       if (M>=n)  cout<<"Case #"<<T<<": 0.000000"<<endl; else
       {

        I=y+1;
        n-=M;

        A=0;
        f=x+y;
      //  cout<<n<<" "<<f<<endl;
        for (i=0;i<=f;i++)
            for (j=0;j<=f;j++)
            O[i][j]=OK[i][k]=0;
        O[0][0]=1;
        for (i=0;i<=f;i++)
            for (j=0;j<=f;j++)
        if (i+j>0)
        {
            if (i>0) OK[i][j]=MA(OK[i][j],OK[i-1][j]);
            if (j>0) OK[i][j]=MA(OK[i][j],OK[i][j-1]);
            if (i>0) mi(O[i][j],OK[i][j],O[i-1][j],OK[i-1][j]);
            if (j>0) mi(O[i][j],OK[i][j],O[i][j-1],OK[i][j-1]);
            while (O[i][j]>10)  {OK[i][j]++;O[i][j]/=10.0;}
        }
        SK=0;S=0;

        for (i=0;i<=f && i<=n;i++)
            if (n-i<=f)
            {
        for (j=SK;j<OK[i][n-i];j++)
        {
            SK++;
            S/=10;
        }
        mi(S,SK,O[i][n-i],OK[i][n-i]);
        while (S>10)
        {
            SK++;
            S/=10;
        }
        }
      //  cout<<S<<" "<<SK<<" "<<f<<" "<<n<<endl;
A=0;
        for (I=y+1;I<=n && I<=f;I++)
            if (n-I<=f)
        {
     //       cout<<I<<" "<<n<<endl;
            D=O[I][n-I];
            k=OK[I][n-I];

             D/=S;
             k-=SK;

            for (i=1;i<=k;i++) D*=10;
            for (i=1;i<=-k;i++) D/=10;
            A+=D;
      //     cout<<I<<" "<<D<<endl;
        }
           printf("Case #%d: %.8lf\n",T,A);
       }

      }
    return 0;
}
