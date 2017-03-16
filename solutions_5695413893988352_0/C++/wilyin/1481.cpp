#include <set>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <ctime>
#include <queue>
#include <list>
#include <map>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define clr(x)  memset(x,0,sizeof(x));
#define clrto(x,siz,y)  for(int xx=0;xx<=siz;xx++)  x[xx]=y;
#define clrset(x,siz)  for(int xx=0;xx<=siz;xx++)  x[xx]=xx;
#define clr_1(x) memset(x,-1,sizeof(x));
#define clrmax(x) memset(x,0x3f,sizeof(x));
#define clrvec(x,siz) for(int xx=0;xx<=siz;xx++)  x[xx].clear();
#define fop2   freopen(".in","r",stdin); //freopen(".out","w",stdout);
#define fop   freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
#define getfile char fin[11], fout[11]; sprintf(fin, "%d.in", i); sprintf(fout, "%d.out", i); freopen(fin, "r", stdin); freopen(fout, "w", stdout);
#define makefile char fout[11]; sprintf(fout, "%d.in", i); freopen(fout, "w", stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
int check(int p, string s)
{
	int pp = p;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == '?')
		{}
		else if(s[i] - '0' != p % 10)
			return 0;
		p /= 10;
	}
	return 1;
}
int main()
{
	int T, cas = 0;
	freopen("in.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		string s1, s2;
		cin>>s1>>s2;
		int len = s1.size();
		int limit = int(pow(10, len) + 1e-8) - 1;
		int resx = 0, resy = 999999999;
		for(int i = 0; i <= limit; i++)
			for(int j = 0; j <= limit; j++)
			{
				if(check(i, s1) && check(j, s2))
				{
					if(abs(i - j) < abs(resx - resy))
						resx = i, resy = j;
					else if(abs(i - j) == abs(resx - resy) && i < resx)
						resx = i, resy = j;
					else if(abs(i - j) == abs(resx - resy) && j < resy)
						resx = i, resy = j;
				}
			}
		char output[111] = {0};
		sprintf(output, "Case #%%d: %%0%dd %%0%dd\n", len, len);
		printf(output, ++cas, resx, resy);
	}
}