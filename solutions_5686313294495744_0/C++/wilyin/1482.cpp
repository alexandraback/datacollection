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
#define fop   freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define getfile char fin[11], fout[11]; sprintf(fin, "%d.in", i); sprintf(fout, "%d.out", i); freopen(fin, "r", stdin); freopen(fout, "w", stdout);
#define makefile char fout[11]; sprintf(fout, "%d.in", i); freopen(fout, "w", stdout);
#define myprogram By_135678942570
#define clrcpy(x,siz,y)  for(int xx=0;xx<siz;xx++)  x[xx]=y[xx];
#define pb push_back
using namespace std;
map<string, int> mp1, mp2;
string s1[55], s2[55];
int main()
{
	fop;
	int T, cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		mp1.clear(), mp2.clear();
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			cin>>s1[i]>>s2[i];
			mp1[s1[i]] += 1, mp2[s2[i]] += 1;
		}
		int res = 0;
		for(int i = 0; i < 1 << n; i++)
		{
			for(int k = 0; k < n; k++)
			if(i & (1 << k))
			{
				mp1[s1[k]]--, mp2[s2[k]]--;
			}
			int flag = 1;
			for(int k = 0; k < n; k++)
			if(i & (1 << k))
			{
				if(mp1[s1[k]] && mp2[s2[k]])
				{}
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag)
				res = max(res, __builtin_popcount(i));
			for(int k = 0; k < n; k++)
			if(i & (1 << k))
			{
				mp1[s1[k]]++, mp2[s2[k]]++;
			}
		}
		printf("Case #%d: %d\n", ++cas, res);
	}
}