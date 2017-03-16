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

int T, R, n, m, k;
LL s[1008];
int c[1008], p[1008], ans, g[1008];
set<LL> F;

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
    	scanf("%d", &T);
    	scanf("%d%d%d%d", &R, &n, &m, &k);
    }
    void fenjie(int n)
    {
    	rep(i,2,7)
    	{
    		int t = 0;
    		while (n % i == 0) n /= i, t++;
    		c[i] = max(t, c[i]);
    	}
    }
    void dfs1(int tot)
    {
    	if (tot > 12)
    	{
    		int cnt = 0;
    		rep(i,0,1023)
    		{
    			LL tmp = 1;
    			rep(j,0,11) if ((i>>j)&1)
    				tmp *= p[j+1];
    			rep(j,1,12) if (tmp == s[j]) cnt++;
    		}
    		if (cnt > ans)
    		{
    			ans = cnt;
    			rep(i,1,12) g[i] = p[i];
    		}
    		return;
    	}
    	rep(i,2,8)
    		p[tot] = i, dfs1(tot+1); 
    }
    void dfs(int t, int tot)
    {
    	LL s = 0; 
    	sort(p+1, p+tot);
    	rep(i,1,tot-1)
    		s = s * 9 + p[i];
    	if (F.find(s) != F.end()) return;
    	if (!t)
    	{
    		tot--;
    		F.insert(s);
			rep(i,3,7)
				rep(j,1,c[i])
					p[++tot] = i;
			if (tot > 12) return;
			if (tot < 10) return;
			dfs1(tot+1);
			return; 
    	}
    	if (t>=1) p[tot] = 2, dfs(t-1, tot+1);
    	if (t>=2) p[tot] = 4, dfs(t-2, tot+1);
    	if (t>=3) p[tot] = 8, dfs(t-3, tot+1);
    	if (t>=1 && c[3]) p[tot] = 6, c[3]--, dfs(t-1, tot+1), c[3]++;
    }
    void work()
    {
    	printf("Case #1:\n"); 
    	rep(i,1,R)
    	{
    		F.clear();
    		memset(c, 0, sizeof(c));
    		rep(j,1,k)
    			scanf("%lld", &s[j]);
    		rep(j,1,k)
    			fenjie(s[j]);
    		ans = 0;
    		rep(i,1,12) g[i] = 2;
    		dfs(c[2], 1);
    		rep(i,1,12) printf("%d", g[i]);
    		printf("\n");
    		
    	}
    }
}Program;
int main()
{
    Program.open();
    Program.init();
    Program.work();
    Program.close();
    return 0;
}
