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

LL r, t;
int cnt;
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
    	
    }
    void work()
    {
    	scanf("%lld%lld", &r, &t);
    	long long L = 1, R = 3*1e18;
    	while (L <= R)
    	{
    		LL m = L + R >> 1;
    		if (t / m >= (2 * m + 2 * r - 1)) L = m + 1;
    		else R = m - 1;
    	}
    	printf("Case #%d: %lld\n", ++cnt, R);
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
