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
#include<deque>
#define Pi 3.1415926535897932384626433832795
#define INF 1000000000
#define P 1000000007
#define MA(a,b) (a>b?a:b)
#define MI(a,b) (a<b?a:b)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
using namespace std;

FILE *fi=freopen("C-small-attempt1.in","r",stdin);
FILE *fo=freopen("text.txt","w",stdout);

int T,J,m,n,i,I,j,k,s,A,d,dd,ds,dp,l,r,K,K0,x,y,X,Y,xx,yy;
map <int,int> M;
struct EL{int l,r,s;} R;
vector <EL> v[1001000];
int main()
{
    cin>>T;
    for (I=1;I<=T;I++)
    {
        for (i=0;i<=1000000;i++) v[i].clear();
        cin>>n;
        for (i=1;i<=n;i++)
        {
            cin>>d>>m>>l>>r>>s>>dd>>dp>>ds;
            for (j=0;j<m;j++)
            {
               //   cout<<d<<endl;
                   R.l=l;
                R.r=r;
                R.s=s;
                v[d].pb(R);
                l+=dp;
                r+=dp;
                d+=dd;
                s+=ds;


            }
        }
    M.clear();
    A=0;
    for (i=0;i<1000000;i++)
     if (v[i].size())
     {
     for (j=0;j<v[i].size();j++)
     {
         J=0;
     //    cout<<" * "<<v[i][j].s<<" "<<v[i][j].l<<" "<<v[i][j].r<<endl;
         for (k=v[i][j].l*2;k<=v[i][j].r*2;k++)
         if (v[i][j].s>M[k]) J=1;
     //    cout<<J<<endl;
         A+=J;
       //  cout<<v[i][j].s<<" "<<v[i][j].l<<" "<<v[i][j].r<<" "<<J<<endl;
     }
     for (j=0;j<v[i].size();j++)
     {
         for (k=v[i][j].l*2;k<=v[i][j].r*2;k++)
         M[k]=MA(M[k],v[i][j].s);
     }
 //    cout<<i<<endl;
   //  for (j=-5;j<=15;j++) cout<<M[j]<<" ";system("pause");
     }
    cout<<"Case #"<<I<<": "<<A<<endl;
    }

    return 0;
}
