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
int t, test = 0;
int n, m;
int a[101][101];
typedef struct node{
    int x, y;
}node;

bool solve()
{
    vector< vector<node> > b;
    b.resize(101);
    cin>>n>>m;
    F1(i,n) F1(j,m) 
    {
        cin>>a[i][j];
        node tmp;
        tmp.x = i; tmp.y = j;
        b[a[i][j]].PB(tmp);
    }
    int c[101][101];
    F1(i,100) F1(j,100) c[i][j] = -1;
    for( int i = 100; i >= 1; i--)
    {
        int n1 = b[i].size();
        if( n1 > 0)
        {
            for( int j = 0; j < n1; j++)
            {
                int x1=b[i][j].x, y1=b[i][j].y;
                if( c[x1][y1] == i) continue;
                else
                {
                    bool flag1=1, flag2=1;
                    F1(k,m)
                    {
                        if( c[x1][k] != -1 && c[x1][k] != i)
                        {
                            flag1 = 0;
                            break;
                        }
                    }
                    F1(k,n)
                    {
                        if( c[k][y1] != -1 && c[k][y1] != i)
                        {
                            flag2 = 0;
                            break;
                        }
                    }
                    if( flag1 || flag2) c[x1][y1] = i;
                    else return 0;
                }
            }
        }
    }
    F1(i,n)
    {
        F1(j,m) 
        {
            if( c[i][j] != a[i][j]) return 0;
        }
    }
    return 1;
}

int main()
{
//    freopen("out.txt","w",stdout);
//    freopen("B-large.in","r",stdin);
    cin>>t;
    while( t--)
    {
        cout<<"Case #"<<++test<<": ";
        if( solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return(0);
}

