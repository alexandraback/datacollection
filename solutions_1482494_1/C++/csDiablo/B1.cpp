/*
ID:   cs_diab1
TASK: 
LANG: C++
*/

#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

#define stop exit(0)
#define nc -1
#define eps 1e-10
#define inf 1000000000
#define mp make_pair

#define fill(array,value) memset(array,value,sizeof(array))
#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)
#define Max(a,b) ( (a>b)?a:b )
#define Min(a,b) ( (a<b)?a:b )
#define pi 3.1415926535897932384626433832
#define iread(var) scanf("%d",&var)
#define dread(var) scanf("%f",&var)
#define lread(var) scanf("%lld",&var)
#define input(name) freopen(name,"r",stdin)
#define output(name) freopen(name,"w",stdout)
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef long long ll;

using namespace std;

int n, a[1010], b[1010], used[2][1010];

inline int ok()
{
    //f(i,1,n)
      //  cout<<i<<" : "<<used[1][i]<<endl<<endl;
    
    f(i,1,n)
        if (!used[1][i]) return 0;
    return 1;
}

int solve(int curr_points, int cnt)
{
    //cout<<curr_points<<" "<<cnt,<endl;
    if (ok()) return cnt;
    
    f(i,1,n)
    {
        if (!used[1][i] && b[i]<=curr_points)
        {
            used[1][i]=1;
            int gap;
            if (used[0][i]) gap=1;
            else gap=2;
            return solve(curr_points+gap,cnt+1);
        }
    }
    
    int ind=-1;
    f(i,1,n)
    {
        if (!used[0][i] && (!used[1][i]) && a[i]<=curr_points)
        {
            if (ind==-1) ind=i;
            else if (b[i]>b[ind]) ind=i;
        }
    }
    if (ind==-1) return -1;
    else
    {
        used[0][ind]=1;
        return solve(curr_points+1,cnt+1);
    }
}

void init()
{
    fill(used,0); fill(a,0); fill(b,0);
    cin>>n;
    f(i,1,n)
        cin>>a[i]>>b[i];
}

void solve()
{
    int tt; cin>>tt;
    
    f(i,1,tt) 
    {
        init();
        cout<<"Case #"<<i<<": ";  int h=solve(0,0);
        if (h==-1) cout<<"Too Bad\n";
        else cout<<h<<endl;
    }
}

int main()
{
    //redirect();
    //input("test.txt");
     input("a2.in");
    output("sol.txt");
    solve();

    return 0;
}