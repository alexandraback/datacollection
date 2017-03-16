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
long long toint(string s)
{
	long long res = 0;
	int len = s.size();
	for(int i = 0; i < len; i++)
		res = res * 10 + s[i] - '0';
	return res;
}
void update(long long i, long long j, long long &resx, long long &resy)
{
	if(abs(i - j) < abs(resx - resy))
		resx = i, resy = j;
	else if(abs(i - j) == abs(resx - resy) && i < resx)
		resx = i, resy = j;
	else if(abs(i - j) == abs(resx - resy) && j < resy)
		resx = i, resy = j;
}
int main()
{
	int T, cas = 0;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		string s1, s2;
		cin>>s1>>s2;
		string ss1 = s1, ss2 = s2, sss1 = s1, sss2 = s2;
		int len = s1.size();
		long long resx = 0, resy = 1000000000000000000ll;
		int flag = 1;
		for(int i = 0; i < len; i++)
		{
			if(s1[i] == '?' && s2[i] == '?')
				s1[i] = '0', s2[i] = '0';
			else if(s1[i] == '?')
				s1[i] = s2[i];
			else if(s2[i] == '?')
				s2[i] = s1[i];
			else if(s2[i] != s1[i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("Case #%d: ", ++cas);
			cout<<s1<<' '<<s2<<endl;
			continue;
		}
		s1 = ss1, s2 = ss2;
		for(int i = 0; i < len; i++)
		{
			if(s1[i] != '?' && s2[i] != '?' && s1[i] < s2[i])
				break;
			else if(s1[i] != '?' && s2[i] != '?' && s1[i] == s2[i])
			{}
			else if(s1[i] != '?' && s2[i] != '?')
			{
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '0', s2[j] = '9';
					else if(s1[j] == '?')
						s1[j] = '0';
					else if(s2[j] == '?')
						s2[j] = '9';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
				break;
			}
			else if(s1[i] == '?' && s2[i] == '?')
			{
				s1[i] = '1', s2[i] = '0';
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '0', s2[j] = '9';
					else if(s1[j] == '?')
						s1[j] = '0';
					else if(s2[j] == '?')
						s2[j] = '9';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
			}
			else if(s1[i] == '?' && s2[i] == '9')
			{}
			else if(s1[i] == '?')
			{
				s1[i] = s2[i] + 1;
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '0', s2[j] = '9';
					else if(s1[j] == '?')
						s1[j] = '0';
					else if(s2[j] == '?')
						s2[j] = '9';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
			}
			else if(s1[i] == '0' && s2[i] == '?')
			{}
			else if(s2[i] == '?')
			{
				s2[i] = s1[i] - 1;
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '0', s2[j] = '9';
					else if(s1[j] == '?')
						s1[j] = '0';
					else if(s2[j] == '?')
						s2[j] = '9';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
			}
			if(s1[i] == '?' && s2[i] == '?')
				s1[i] = s2[i] = '0';
			else if(s1[i] == '?')
				s1[i] = s2[i];
			else if(s2[i] == '?')
				s2[i] = s1[i];
			ss1 = s1, ss2 = s2;
		}
		s1 = sss1, s2 = sss2, ss1 = s1, ss2 = s2;
		for(int i = 0; i < len; i++)
		{
			if(s1[i] != '?' && s2[i] != '?' && s1[i] > s2[i])
				break;
			else if(s1[i] != '?' && s2[i] != '?' && s1[i] == s2[i])
			{}
			else if(s1[i] != '?' && s2[i] != '?')
			{
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '9', s2[j] = '0';
					else if(s1[j] == '?')
						s1[j] = '9';
					else if(s2[j] == '?')
						s2[j] = '0';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
				break;
			}
			else if(s1[i] == '?' && s2[i] == '?')
			{
				s1[i] = '0', s2[i] = '1';
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '9', s2[j] = '0';
					else if(s1[j] == '?')
						s1[j] = '9';
					else if(s2[j] == '?')
						s2[j] = '0';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
			}
			else if(s1[i] == '?' && s2[i] == '0')
			{}
			else if(s1[i] == '?')
			{
				s1[i] = s2[i] - 1;
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '9', s2[j] = '0';
					else if(s1[j] == '?')
						s1[j] = '9';
					else if(s2[j] == '?')
						s2[j] = '0';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
			}
			else if(s1[i] == '9' && s2[i] == '?')
			{}
			else if(s2[i] == '?')
			{
				s2[i] = s1[i] + 1;
				for(int j = i + 1; j < len; j++)
				{
					if(s1[j] == '?' && s2[j] == '?')
						s1[j] = '9', s2[j] = '0';
					else if(s1[j] == '?')
						s1[j] = '9';
					else if(s2[j] == '?')
						s2[j] = '0';
				}
				long long x = toint(s1), y = toint(s2);
				update(x, y, resx, resy);
				s1 = ss1, s2 = ss2;
			}
			if(s1[i] == '?' && s2[i] == '?')
				s1[i] = s2[i] = '0';
			else if(s1[i] == '?')
				s1[i] = s2[i];
			else if(s2[i] == '?')
				s2[i] = s1[i];
			ss1 = s1, ss2 = s2;
		}
		char output[111] = {0};
		sprintf(output, "Case #%%d: %%0%dlld %%0%dlld\n", len, len);
		printf(output, ++cas, resx, resy);
	}
}