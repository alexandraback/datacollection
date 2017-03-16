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
string res = "";
map<char, int> mp;
void get(char s, char bit, string init)
{
	int get = mp[s];
	for(int i = 0; i < get; i++)
	{
		res += bit;
		for(int j = 0; j < init.size(); j++)
			mp[init[j]]--;
	}
}
int main()
{
	fop;
	int T, cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		mp.clear();
		res = "";
		string s;
		cin>>s;
		int len = s.size();
		for(int i = 0; i < len; i++)
			mp[s[i]] += 1;
		get('Z', '0', "ZERO");
		get('X', '6', "SIX");
		get('S', '7', "SEVEN");
		get('V', '5', "FIVE");
		get('F', '4', "FOUR");
		get('R', '3', "THREE");
		get('G', '8', "EIGHT");
		get('T', '2', "TWO");
		get('I', '9', "NINE");
		get('O', '1', "ONE");
		sort(res.begin(), res.end());
		printf("Case #%d: ", ++cas);
		cout<<res<<endl;
	}
}