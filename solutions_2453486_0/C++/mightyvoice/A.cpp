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
int n, t, test = 0;
string a[4];

bool row_num( char y, int x)
{
    int n1 = 0;
    F0(i,4)
    {
        if( a[x][i] == y || a[x][i] == 'T')
            n1++;
    }
    if( n1 == 4) return 1;
    else return 0;
}

bool col_num( char y, int x)
{
    int n1 = 0;
    F0(i,4)
    {
        if( a[i][x] == y || a[i][x] == 'T')
            n1++;
    }
    if( n1 == 4) return 1;
    else return 0;
}

bool dig_num(char y)
{
    int n1 = 0, n2 = 0;
    F0(i,4)
    {
        if( a[i][i] == y || a[i][i] == 'T') n1++;
        if( a[i][3-i] == y || a[i][3-i] == 'T') n2++;
    }
    if( n1 == 4 || n2 == 4) return 1;
    else return 0;
}

void solve()
{
    int flag = -1;
    F0(i,4)
    {
        if( row_num('X', i) || col_num('X', i) || dig_num('X'))
        {
            flag = 1;
            break;
        }
        if( row_num('O', i) || col_num('O', i) || dig_num('O'))
        {
            flag = 2;
            break;
        }
    }
    if( flag < 0)
    {
        F0(i,4)
            F0(j,4)
                if( a[i][j] == '.') flag = 3;
    }
    if( flag == 1) cout<<"X won"<<endl;
    else if( flag == 2) cout<<"O won"<<endl;
    else if( flag == 3) cout<<"Game has not completed"<<endl;
    else cout<<"Draw"<<endl;
}
int main()
{
//   freopen("out.txt","w",stdout);
//    freopen("A-small-attempt0.in","r",stdin);
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        F0(i,4) cin>>a[i];
        solve();
    }
    return(0);
}

