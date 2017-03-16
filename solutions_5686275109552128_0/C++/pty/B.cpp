/*.....................
Author : PTY
Time : 14/04/02
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
struct Tprogram
{
    void open()
    {
        freopen("B.in", "r", stdin);
        freopen("B.out", "w", stdout);
    }
    void close()
    {
        fclose(stdin);
        fclose(stdout);
    }
    int T, n, c[1008];
    void init()
    {
		scanf("%d", &T);
		rep(i,1,T)
		{
			scanf("%d", &n);
			memset(c, 0, sizeof(c));
			int p;
			rep(j,1,n)
				scanf("%d", &c[j]);
			int tmp = 0, ans = 1e9;
			rep(i,1,1000)
			{
				int tmp = 0;
				rep(j,1,n) 
					tmp += (c[j] -  1)/ i;
				ans = min(ans, tmp + i);
			}
			printf("Case #%d: %d\n", i, ans);
		}
					
    }
    void work()
    {
    	
    }
}Program;
int main()
{
    Program.open();
    Program.init();
    Program.work();
    //Program.close();
    return 0;
}
