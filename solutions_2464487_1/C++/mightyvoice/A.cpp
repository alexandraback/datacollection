#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vI;
typedef vector<string> vS;
typedef pair<int, int> pI;
typedef map<int, int> mI;
typedef map<string, int> mSI;
typedef set<int> sI;
typedef set<pI> spI;
typedef priority_queue<int> qmax;
typedef priority_queue<int, vector<int>, greater<int> >qmin;
typedef map<int, int>::iterator mI_it;
typedef set<int>::iterator sI_it;

#define TWO(k)  (1<<(k))
#define LTWO(k) (((LL)(1)<<(k)))
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define B begin()
#define E end()
#define F0(i, n) for( int (i) = 0; (i) < (n); (i)++)
#define F1(i, n) for( int (i) = 1; (i) <= (n); (i)++)
#define zero(i) memset((i),0,sizeof((i)))

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int ioo = (~0)-(1<<31);
const LL loo = (~(LL)0)-((LL)1<<63);

LL func( double a, double b, LL x)
{
    return a*x*x+b*x;
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("A-large.in","r",stdin);
    int t, test = 0;
    cin>>t; 
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        LL r, t1; cin>>r>>t1;
        double a = 2.0, b=2.0*r-1, c = -1.0*t1;
        double x = (-1.0*b+sqrt(1.0*b*b-4.0*a*c))/(2.0*a);
//        if( x - 1.0*((LL)x) <= EPS) x = (LL)x-1;
//        else x = (LL)x;
        x = (LL)x;
        if( func(a,b,x) > t1) x--;
        cout<<(long long)x<<endl;
    }
    return(0);
}

