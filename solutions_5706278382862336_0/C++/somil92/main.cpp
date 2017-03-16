#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef map<int, int> MI;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
const double pi=acos(-1.0);
const double eps=1e-11;
const int mod = 1e9 + 7;

#define two(X) (1<<(X))
#define twoL(X) ((1LL)<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

#define rep(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = ((int)(b)); i c ((int)(n)); i++)

#define p(x) cout << x;
#define ps(x) cout << x << " "
#define pl cout << endl
#define pn(x) cout << x << endl

#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define getcx getchar
//_unlocked

// freopen ("A-large.in","r",stdin);
// freopen ("output.txt","w",stdout);

template<class T>
inline void readInt( T &n )//fast input function
{
   n=0;
   T ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
ULL gcd(ULL u, ULL v) {
return (v != 0)?gcd(v, u%v):u;
}
int main()
{
freopen ("aba.in","r",stdin);
 freopen ("output.txt","w",stdout);

    int t;
    cin>>t;
    for(int oo=1;oo<=t;oo++)
    {
    LL p,q;
    scanf("%lld/%lld",&p,&q);

ULL w=gcd(p,q);
 while(w!=1)
 {
  p=p/w;
  q=q/w;
  w=gcd(p,q);

 }
    ULL ans=0,flag=0;
    if(ceil(log10(q)/log10(2))!=floor(log10(q)/log10(2)))
        flag=1;


    while(p<q)
    {
            ans++;
            q=q/2;
    }
        cout<<"Case #"<<oo<<": ";
        if(flag)
            cout<<"impossible"<<endl;
            else
                cout<<ans<<endl;
}
}
