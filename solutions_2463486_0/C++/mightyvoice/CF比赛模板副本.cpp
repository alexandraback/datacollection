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

bool flag[1005] = {0};
int sum[1005] = {0};

void build()
{
    flag[1]=flag[4]=flag[9]=flag[121]=flag[484]=1;
    F1(i,1000)
    {
        if( !flag[i]) sum[i] = sum[i-1];
        else sum[i] = sum[i-1] + 1;
    }
}
int main()
{
//    freopen("out.txt","w",stdout);
//    freopen("C-small-attempt0.in","r",stdin);
    int t, test = 0;
    cin>>t;
    build();
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        int a,b; cin>>a>>b;
        cout<<sum[b] - sum[a-1]<<endl;
    }
    return(0);
}

