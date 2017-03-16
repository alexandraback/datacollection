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

FILE *fi=freopen("B-small-attempt0.in","r",stdin);
FILE *fo=freopen("text.txt","w",stdout);

int T,J,m,n,i,I,j,k,l,r,K,K0,x,y,X,Y,xx,yy;
map <pair <int, int> ,string > S,SN;
map <int,map <int, bool> > F;
map <pair <int,int> ,string  > ::iterator IT;
long long A;
string s;
int main()
{
    cin>>T;
    for (I=1;I<=T;I++)
    {
    cin>>x>>y;
    F.clear();
    S.clear();
    s.clear();
    S[mp(0,0)]=s;
    k=0;
    while (F[x][y]==0){k++;
    SN.clear();
    for (IT=S.begin();IT!=S.end();IT++)
    {
        X=(*IT).X.X;
        Y=(*IT).X.Y;
        F[X][Y]=1;
        if (F[X+k][Y]==0) {SN[mp(X+k,Y)]=(*IT).Y+"E"; F[X+k][Y]=1;}
        if (F[X-k][Y]==0) {SN[mp(X-k,Y)]=(*IT).Y+"W"; F[X-k][Y]=1;}
        if (F[X][Y+k]==0) {SN[mp(X,Y+k)]=(*IT).Y+"N"; F[X][Y+k]=1;}
        if (F[X][Y-1]==0) {SN[mp(X,Y-k)]=(*IT).Y+"S"; F[X][Y-k]=1;}
    }
    S=SN;
    }
    cout<<"Case #"<<I<<": "<<S[mp(x,y)]<<endl;
    }

    return 0;
}
