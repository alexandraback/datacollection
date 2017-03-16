/// ///////////////////// ///
///                       ///
///      Tamanna_24       ///
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

#define pi 2.0*acos(0.0)

template <class T> T _diff(T a,T b) {return (a<b?b-a:a-b);}
template <class T> T _abs(T a) {return(a<0?-a:a);}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T max3(T a, T b, T c) {return (_max(a,b)>c ? _max(a,b) : c);}
template <class T> T min3(T a, T b, T c) {return (_min(a,b)<c ? _min(a,b) : c);}
template< class T>T GCD(T a,T b) {
    a=_abs(a);b=_abs(b);T tmp;while(a%b){ tmp=a%b; a=b; b=tmp; } return b;
}
template< class T>T LCM(T a,T b) {
    a=_abs(a);b=_abs(b);return (a/GCD(a,b))*b;
}
template<class T> T toRad(T deg) { return (deg*pi)/(180.0) ;}
template<class T> T toDeg(T rad) { return (rad*180.0)/(pi) ;}

#define pb(a) push_back(a)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PN() puts("")
#define PCASE() printf("Case #%d:",kk++)
#define eps 1e-9
#define inf 2000000000
#define mod 1000000007
#define MX  1000000
using namespace std;

int t,kk=1,n,i,j;
bool vis[1000006];
struct s{
    int nw,c;
}x,y;
queue<s>Q;

int rev(int p){
    int r=1;
    vector<int>v;
    r=p;
    while(r){
        v.pb(r%10);
        r/=10;
    }
    r=0;
    for(int m=0;m<v.size();m++){
        r=(r*10)+v[m];
    }
    return r;
}


int main()
{
    freopen("a.txt","r",stdin);
    freopen("a1.txt","w",stdout);

    cin>>t;
    while(t--){

        while(!Q.empty())Q.pop();
        CLR(vis);
        cin>>n;

        vis[1]=1;
        x.c=1;
        x.nw=1;
        Q.push(x);
        while(!Q.empty()){
            y=Q.front();
            if(y.nw==n) break;
            Q.pop();
            x.c=y.c+1;
            x.nw=rev(y.nw);
            if(vis[x.nw]==0) {
                vis[x.nw]=1;
                Q.push(x);
            }
            x.nw=y.nw+1;
            if(vis[x.nw]==0) {
                Q.push(x);
                vis[x.nw]=1;
            }
        }
        PCASE();cout<<" "<<y.c<<endl;

    }

	return 0;
}










