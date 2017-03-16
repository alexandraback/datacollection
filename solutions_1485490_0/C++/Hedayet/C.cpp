//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647

using namespace std;

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;

ll kas,A[109],B[109],a[109],b[109],memo[109][109],N,M;

void ini()
{
    rep(i,100)
    rep(j,109)
    memo[i][j]=-1;
}
struct str{
    int x,y;
    ll xh,yh,val;
};
bool operator<(const str &a, const str &b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    if(a.xh!=b.xh)
    return a.xh<b.xh;
    return a.yh<b.yh;
}
set<str>S;
map<str,ll>Mp;
ll dp(int curx,int cury){
    if(memo[curx][cury]!=-1)return memo[curx][cury];

    if(curx==N||cury==M)return 0;

    ll ret=0;
    if(a[curx]==b[cury]){
        ll got = min(A[curx],B[cury]);

        ret=dp(curx+1,cury+1)+got;
    }
    ret=max(ret,max(dp(curx,cury+1),dp(curx+1,cury)));

    memo[curx][cury]=ret;
    return ret;
}


int main()
{
	freopen("inputx.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>kas;
	rep(cas,kas){
        cin>>N>>M;
        rep(i,N)cin>>A[i]>>a[i];
        rep(i,M)cin>>B[i]>>b[i];
        //rep(i,N)cout<<A[i]<<" A "<<a[i]<<endl;
        ini();
        S.clear();
        Mp.clear();
        ll res = dp(0,0);
        printf("Case #%d: %I64d\n",cas+1,res);
	}
return 0;
}
