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
        freopen("D.in", "r", stdin);
        freopen("D.out", "w", stdout);
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
    		
    }
}Program;
int ask(int x, int R, int C)
{
	if (R >= C) swap(R, C);
	if (R*C % x) return 1;
	if (x <= 2) return 0;
	if (x == 3)
		if (R == 1) return 1;
		else return 0;
	if (x == 4)
		if (R == 1 || R == 2 && C == 2 || R == 2 && C == 4) return 1;
		else return 0;
	if (x >= 7) return 1;
	if (x == 5)
		if (R == 1 || R == 2 || R == 3 && C == 5) return 1;
	if (x == 6)
		if (R == 1 || R == 2 || R == 3)  return 1;
	return 0;
}
int main()
{
    Program.open();
    int T, x, R, C;
    scanf("%d", &T);
    Program.init();
    rep(i,1,T)
    {
    	printf("Case #%d: ", i);
    	scanf("%d%d%d", &x, &R, &C);
    	if (ask(x, R, C)) printf("RICHARD\n");
    	else printf("GABRIEL\n");
    }
    //Program.close();
    return 0;
}
