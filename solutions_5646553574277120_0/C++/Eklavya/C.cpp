//Abinash Ghosh
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cassert>
using  namespace  std;

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;


//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 10000007
#define EPS 1e-9

int pos[10000],D,a[10];
void solve(int idx,int sum)
{
    if(idx>D+1)return;
    //pr(sum);
    pos[sum]=1;
    solve(idx+1,sum+a[idx]);
    solve(idx+1,sum);
}
int main()
{
    READ("C-small-attempt0.in");
    WRITE("outC.out");
    int T,c,d,v;
    scanf("%d",&T);
    FOR(t,1,T)
    {
        scanf("%d%d%d",&c,&d,&v);
        D=d;
        FOR(i,1,d)scanf("%d",&a[i]);
        mem(pos,0);
        solve(1,0);
        int ans=0;
        FOR(i,1,v)if(!pos[i])ans++;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}



