/*.....................
Author : PTY
Time : 15/05/01
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
#include <map>
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

int h[1000008], d[100000008];
struct Tprogram
{
    void open()
    {
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    void close()
    {
        fclose(stdin);
        fclose(stdout);
    }
    int reverse(int u)
    {
    	int cnt = 0;
    	while (u)
    	{
    		cnt = cnt * 10 + u % 10;
    		u /= 10;
    	}
    	return cnt;
    }
    void init()
    {
    	int l = 1, r = 1; h[1] = 1; d[1] = 1;
    	rep(i,1,1000000)
    	{
    		int u = h[l++];
    		int u1 = u + 1;
    		if (!d[u+1])
    		{
    			d[u+1] = d[u] + 1;
    			h[++r] = u + 1;
    		}
    		u1 = reverse(u);
    		if (!d[u1])
    		{
    			d[u1] = d[u] + 1;
    			h[++r] = u1;
    		}
    	}
    }
    void work()
    {
    	int n;
    	scanf("%d", &n);
		printf("%d\n", d[n]);	
    }
}Program;
int main()
{
    Program.open();
    Program.init();
    int T;
    scanf("%d", &T);
    rep(i,1,T)
    {	
    	printf("Case #%d: ", i);
    	Program.work();
    }
    Program.close();
    return 0;
}
