/// ///////////////////// ///
///                       ///
///      Silver Rain      ///
///                       ///
///         JU            ///
///                       ///
/// ///////////////////// ///

#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<cctype>

typedef long long ll;
typedef unsigned long long ull;

template <class T> T _diff(T a,T b) {return (a<b?b-a:a-b);}
template <class T> T _abs(T a) {return(a<0?-a:a);}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T max3(T a, T b, T c) {return (_max(a,b)>c ? _max(a,b) : c);}
template <class T> T min3(T a, T b, T c) {return (_min(a,b)<c ? _min(a,b) : c);}
template< class T >T GCD(T a,T b) {
    a=_abs(a);b=_abs(b);T tmp;while(a%b){ tmp=a%b; a=b; b=tmp; } return b;
}
template< class T >T LCM(T a,T b) {
    a=_abs(a);b=_abs(b);return (a/GCD(a,b))*b;
}

#define read(a) freopen("a.txt","r",stdin)
#define write(a) freopen("a.txt","w",stdout)

#define sz(a) a.size()
#define VC(a) a.clear()
#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))

#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PS() printf(" ")
#define PCASE() printf("Case #%d: ",kk++)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)
#define FOR(i,n) for(i=0;i<n;i++)

#define eps 1e-9
#define pi 2.0*acos(0.0)
#define inf 1000000000
#define mod 1000000007

using namespace std;

int main()
{
    int T,i,j,x,d,o,kk=1;
    string a[5];
    bool fx,fo,fd;

    freopen("ain.txt","r",stdin);
    freopen("aout.txt","w",stdout);

    S(T);
    while(T--)
    {
        fx=fo=fd=0;
        for(i=0;i<4;i++)cin>>a[i];

        for(i=0;i<4;i++)
        {
            x=o=d=0;
            for(j=0;j<4;j++)
            {
                if(a[i][j]=='T'){x++;o++;}
                else if(a[i][j]=='X') x++;
                else if(a[i][j]=='O') o++;
                else if(a[i][j]=='.') d++;
            }
            if(d)fd=1;
            if(x==4)fx=1;
            else if(o==4)fo=1;
        }
        for(j=0;j<4;j++)
        {
            x=o=d=0;
            for(i=0;i<4;i++)
            {
                if(a[i][j]=='T'){x++;o++;}
                else if(a[i][j]=='X') x++;
                else if(a[i][j]=='O') o++;
                else if(a[i][j]=='.') d++;
            }
            if(d)fd=1;
            if(x==4)fx=1;
            else if(o==4)fo=1;
        }

        x=d=o=0;
        for(i=0;i<4;i++)
        {
            if(a[i][i]=='T'){x++;o++;}
            else if(a[i][i]=='X') x++;
            else if(a[i][i]=='O') o++;
            else if(a[i][i]=='.') d++;
        }
        if(d)fd=1;
        if(x==4)fx=1;
        else if(o==4)fo=1;

        x=d=o=0;
        for(i=0;i<4;i++)
        {
            if(a[i][3-i]=='T'){x++;o++;}
            else if(a[i][3-i]=='X') x++;
            else if(a[i][3-i]=='O') o++;
            else if(a[i][3-i]=='.') d++;
        }
        if(d)fd=1;
        if(x==4)fx=1;
        else if(o==4)fo=1;
        PCASE();
        if(fx)puts("X won");
        else if(fo) puts("O won");
        else if(fd) puts("Game has not completed");
        else puts("Draw");
    }
    return 0;
}
