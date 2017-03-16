#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll             long long
#define ull            unsigned long long
string tostr(long long x) { stringstream ss; ss << x; return ss.str(); }
long long toint(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }

int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int test;

cin>>test;
for(int i=1;i<=test;i++)
{
    ull r,t;
    cin>>r>>t;
    ull ft;
    ft= (2*r +1);
    ull a,b,c;
    a=2;
    b=(ft*2 -4)/2;
    c=-t;
    ull d,sq;
    d= b*b +(-4*a*c);
    sq=sqrt(d);
    ull n;
    n= (sq- b)/4 ;

    cout<<"Case #"<<i<<": "<<n<<endl;

}
return 0;
}
