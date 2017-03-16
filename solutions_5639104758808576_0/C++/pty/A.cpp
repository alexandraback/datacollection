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
    	int T, n;
    	char s[10008];
		scanf("%d", &T);
		rep(i,1,T)
		{
			scanf("%d %s", &n, &s);
			int tmp = 0, ans = 0;
			rep(i,0,n)
			{
				if (tmp < i && s[i] > '0') ans += i - tmp, tmp = i;
				tmp += s[i] - '0';
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
