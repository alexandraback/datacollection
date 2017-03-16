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
int t[1008], s[1008];

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
    void work()
    {
    	printf("Case #1:\n"); 
    	rep(i,1,R)
    	{
    		rep(j,1,k)
    			scanf("%d", &s[j]);
    		rep(x,2,5)
    			rep(y,x,5)
    				rep(z,y,5)
    				{
						rep(i,0,x*y*z) t[i] = 0;
						t[1] = 1; t[x] = 1; t[y] = 1; t[z] = 1;
						t[x*y] = 1; t[x*z] = 1; t[y*z] = 1; t[x*y*z] = 1; 
    					rep(j,1,k)
    						if (s[j] > x * y * z || ! t[s[j]]) goto die;
    					printf("%d%d%d\n", x,y,z); goto die2;
						die:; 
    				}
    		die2:; 
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
