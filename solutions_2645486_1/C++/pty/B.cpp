/*.....................
Author : PTY
Time : 13/04/27
Desprition :
Analyse : 
Attention : 
.....................*/
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define Travel(E, u) for(int i=E.start[u],v;v=E.e[i].a,i;i=E.e[i].next)
#define sqr(x) ((x)*(x))
#define pb push_back
#define read() (strtol(ipos, &ipos, 10))
#define pb push_back
#define pi 3.1415926535897

int cnt;
LL ans;
int E, R, n;
int v[100008];

struct Tprogram
{
    void open()
    {
        freopen("1.in", "r", stdin);
        freopen("1.out", "w", stdout);
    }
    void close()
    {
        fclose(stdin);
        fclose(stdout);
    }
    void init()
    {
    	scanf("%d%d%d", &E, &R, &n);
    	rep(i,1,n)
    		scanf("%d", &v[i]);
    }
    void dfs(int S, int T, int l, int r)
    {
    	if (l > r) return;
    	if (S + (r - l + 1) * (LL)R == T) return;
    	int p = l;
    	rep(i,l,r)
    		if (v[i] > v[p]) p = i;
    	int v1 = E;
		v1 = min(v1, S + (LL)R * (p - l));
		int v2 = v1 - max(T - (LL)R * (r - p + 1), 0);
		ans += (LL)v2 * v[p]; 
		dfs(S, v1, l, p-1);
		int t = min(v1 - v2 + R, E);
		dfs(t, T, p+1, r);
    }
    void work()
    {
    	ans = 0;
    	dfs(E, 0, 1, n);
    	printf("Case #%d: %lld\n", ++cnt, ans);
    }
}Program;
int main()
{
    Program.open();
    int t;
    scanf("%d", &t);
    while (t--)
    {
    	Program.init();
   		Program.work();
   	}
    Program.close();
    return 0;
}
