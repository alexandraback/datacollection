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

int ee,rr,nn;
int v[10004];
int dp[15][10];
int ans = 0;
int sum = 0;
void dfs( int id, int total)
{
    if( id > nn)
    {
        ans = max( ans, sum);
        return;
    }
    for( int i = 0; i <= total; i++)
    {
        sum += v[id] * i;
        int tmp = total - i + rr;
        if( tmp > total) tmp = total;
        dfs( id+1, tmp);
        sum -= v[id] * i;
    }
    return;
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("B-small-attempt2.in","r",stdin);
//    freopen("in.txt","r",stdin);
    int t, test = 0;
    cin>>t; 
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        cin>>ee>>rr>>nn;
        F1(i,nn) cin>>v[i];
        ans = sum = 0;
        memset(dp, 0, sizeof(dp));
        for( int i = 0; i <= ee; i++)
        {
            int tmp = ee-i+rr;
            if( tmp > ee) tmp = ee;
            dp[1][tmp] = max( dp[1][tmp], v[1] * i);
        }
        for( int i = 2; i <= nn; i++)
        {
            for( int j = rr; j <= ee; j++)
            {
                for( int jj = rr; jj <= ee; jj++)
                {
                    for( int kk = 0; kk <= ee; kk++)
                    {
                        int tmp = jj - kk + rr;
                        if( tmp >= ee) tmp = ee;
                        if( tmp == j)
                        {
                            dp[i][j] = max( dp[i][j], dp[i-1][jj]+ kk * v[i]);
                        }
                    }
                }
            }
        }
        for( int i = 0; i <= ee; i++) ans = max( ans, dp[nn][i]);
        cout<<ans<<endl;
    }
    return(0);
}

