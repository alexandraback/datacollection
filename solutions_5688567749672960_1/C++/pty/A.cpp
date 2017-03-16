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

int tmp[100008];
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
    bool check(LL x)
    {
    	while (x % 10 == 0) x /= 10;
    	return x == 1;
    }
    LL ask(LL n)
    {
    	LL x = n, ans = 0;
    	while (n != 0)
    	{
	    	LL x = n, tot = 0;
			if (x % 10 == 0) 
			{
				x--, ans++;
				if (check(x+1))
				{
					n = x;
					continue;
				}
			}
			while (x)
			{
				tmp[++tot] = x % 10;
				x /= 10;
			}
			LL dt = 1;
			rep(j,1,tot/2)
				ans += tmp[j] * dt, dt *= 10;
			dt = 1;
			drep(j,tot,tot/2+1)
				ans += tmp[j] * dt, dt *= 10;
			dt = 1;
			rep(j,1,tot-1) dt *= 10;
			if (tot == 1) break;
			ans++;
			rep(j,(tot+1)/2+1,tot-1)
				if (tmp[j]) goto die;
			if (tmp[tot] != 1) goto die;
			ans--;
			die:;
			n = dt - 1;
		}
		return ans;
    }
    void work()
    {
    	LL n;
    	scanf("%lld", &n);
		printf("%lld\n", ask(n));
    }
}Program;
int main()
{
    Program.open();
    //Program.init();
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
