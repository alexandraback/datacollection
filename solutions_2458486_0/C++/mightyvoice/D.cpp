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
const int M = 22;
int n, k;
vector< vector<int> > invo;
int cur[M];
int ans[M], ansn = 0;
bool vis[M];
int needing[M];

bool dfs( int x)
{
//    cout<<x<<' ';
    ans[++ansn] = x;
    vis[x] = 1;
    cur[needing[x]]--;
    if( ansn == n) return 1;
    int n1 = invo[x].size();
    F0(i,n1) cur[invo[x][i]]++;
    F1(i,n)
    {
        if( !vis[i])
        {
            if( cur[needing[i]] > 0)
            {
                if( dfs(i)) return 1;
                ansn--;
                vis[i] = 0;
//                cur[needing[i]]++;
                int n1 = invo[i].size();
                F0(j,n1) cur[invo[i][j]]--;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("D-small-attempt3.in","r",stdin);
    int t, test = 0;
    cin>>t; 
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
        invo.clear();
        invo.resize(M);
        memset( needing, 0, sizeof(needing));
        cin>>k>>n;
        vector<int> init;
        F1(i,k)
        {
            int tmp; cin>>tmp;
            init.PB(tmp);
        } 
        F1(i,n)
        {
            int t1, k1;cin>>t1>>k1;
            needing[i] = t1;
            F1(j,k1)
            {
                int k2; cin>>k2; 
                invo[i].PB(k2);
            }
        }
        bool flag = 0;
        F1(i,n)
        {
            ansn = 0;
            memset(vis, 0, sizeof(vis));
            memset(cur, 0, sizeof(cur));
            for( int j = 0; j < (int)init.size(); j++) cur[init[j]]++;
            if( cur[needing[i]] > 0 && dfs(i)) 
            {
                flag = 1;
                break;
            }
        }
        if( !flag) cout<<"IMPOSSIBLE"<<endl;
        else
        {
            F1(i,ansn) 
            {
                cout<<ans[i];
                if( i < ansn) cout<<' ';
            }
            cout<<endl;
        }
    }
    return(0);
}

