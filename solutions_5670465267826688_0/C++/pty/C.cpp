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


char be[208][208];
int n;
LL m;
char s[10008];
char suml[10008], sumr[10008];
char count(char x, char y)
{
	if (x >= 'a' && y >= 'a')
	{
		if (x == 'l') return y;
		if (y == 'l') return x;
		if (x == y) return 'L';
		if (x == 'i')
			if (y == 'j') return 'k';
			else return 'J';
		if (x == 'j')
			if (y == 'k') return 'i';
			else return 'K';
		if (x == 'k')
			if (y == 'i') return 'j';
			else return 'I';
	}
	int cnt = 0;
	if (x < 'a') x -= 'A' - 'a', cnt ^= 1;
	if (y < 'a') y -= 'A' - 'a', cnt ^= 1;
	if (!cnt) return be[x][y];
	if (be[x][y] <= 'Z') return be[x][y] + 'a' - 'A';
	return be[x][y] + 'A' - 'a';
}
struct Tprogram
{
    void open()
    {
        freopen("", "r", stdin);
        freopen("", "w", stdout);
    }
    void close()
    {
        fclose(stdin);
        fclose(stdout);
    }
    void init()
    {
    	char t[10] = "lijkLIJK";
    	rep(i,0,3)
    		rep(j,0,3)
    		{
    			be[t[i]][t[j]] = count(t[i], t[j]);
    		}
    	rep(i,0,7)
    		rep(j,0,7) if (i > 3 || j > 3)
    			be[t[i]][t[j]] = count(t[i], t[j]);
    	int T;
		scanf("%d",&T);
		rep(t,1,T)
		{
			scanf("%d%lld", &n, &m);
			scanf("%s", &s[1]);
			suml[0] = 'l';
			rep(i,1,n)
			{
				suml[i] = be[suml[i-1]][s[i]];
			}
			sumr[n+1] = 'l';
			drep(i,n,1)
				sumr[i] = be[s[i]][sumr[i+1]];
			//first situation
			char S = suml[n];
			if (m > 1)
			{
				rep(i,1,n) rep(j,1,n)
				{
					char S1 = 'l';
					char L = '0', R = '0', M = '0';
					rep(l,0,3)
					{
						if (be[S1][suml[i-1]] == 'i' && L=='0')
							L = l;
						if (be[sumr[j+1]][S1] == 'k' && R=='0')
							R = l;
						if (be[be[sumr[i]][S1]][suml[j]] == 'j' && M == '0')
							M = l;
						S1 = be[S1][S];
					}
					if (L == '0' || R == '0' || M == '0') continue;
					if (m < L + R + M+2) continue;
					if ((L + R + M + 2) % 4 == m % 4 || S == 'l' || S == 'L'&&(L^R^M^m&1) == 0)
					{
						printf("Case #%d: YES\n", t);
						goto end;
					}
				}
			}
			//second situation
			rep(i,1,n)
				rep(j,i,n)
				{
					char S1 = 'l';
					char L = '0', R = '0', M = '0';
					char mid = be[suml[i-1]][suml[j]];
					if (suml[i-1] != 'l' && suml[i-1] != 'L') mid = be[mid]['L'];
					if (mid != 'j') continue;  
					rep(l,0,3)
					{
						if (be[S1][suml[i-1]] == 'i' && L == '0')
							L = l;
						if (be[sumr[j+1]][S1] == 'k' && R == '0')
							R = l;
						S1 = be[S1][S];
					}
					if (L == '0' || R == '0') continue;
					if ((L+R+1)%4 == m % 4 && m >= L+R+1 || S == 'l' || (S == 'L' && (L^R^m&1)==1 && m >= L+R+1))
					{
						printf("Case #%d: YES\n", t);
						goto end;
					}
				}
			printf("Case #%d: NO\n", t);
			end:;
		}
    }
    void work()
    {
    	
    }
}Program;
int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
    //Program.open();
    Program.init();
    Program.work();
    //Program.close();
    return 0;
}
