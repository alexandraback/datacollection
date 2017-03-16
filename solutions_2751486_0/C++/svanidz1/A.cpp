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

FILE *fi=freopen("A-small-attempt0.in","r",stdin);
FILE *fo=freopen("text.txt","w",stdout);

int T,J,m,n,i,I,j,k,l,r,K,K0,x,y,X,Y,xx,yy;
string s;
long long A;
int main()
{
    cin>>T;
    for (I=1;I<=T;I++)
    {
    cin>>s>>k; A=0; l=0;
    n=0;
    for (i=0;i<s.size();i++)
    {
        n++;
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') n=0;
        if (n>=k) l=i-k+2;
        A+=l;
   //     cout<<i<<" "<<l<<" "<<n<<endl;
    }
    cout<<"Case #"<<I<<": "<<A<<endl;
    }

    return 0;
}
