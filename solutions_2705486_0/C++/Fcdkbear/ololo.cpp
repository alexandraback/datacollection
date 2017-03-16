#pragma comment(linker, "/STACK:500777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <unordered_map>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned


struct ver
{
	int go[27];
	int isterm;
	ver()
	{
		MEMS(go,-1);
		isterm=0;
	}
};
char s[1000010];
int n;
vector<ver> a;
void add()
{
	int now=0;
	FOR(i,0,n)
	{
		if (a[now].go[s[i]-'a']==-1)
		{
			a[now].go[s[i]-'a']=a.size();
			a.push_back(* new ver());
		}
		now=a[now].go[s[i]-'a'];
	}
	a[now].isterm=1;
}
bool was[51][1125079][6];
char dp[51][1125079][6];
int now;
string st;
char r(int p1, int p2, int last)
{
	//cout<<p1<<" "<<p2<<" "<<last<<endl;
	if (p1==n)
		return 0;
	if (dp[p1][p2][last]!=-1)
		return dp[p1][p2][last];
	//was[p1][p2][last]=now;
	int c=s[p1]-'a';
	char res=100;
	if ((a[p2].isterm) && (p2!=0))
		res=min(res,r(p1,0,last));
	FOR(i,0,26)
	{
		int ne=a[p2].go[i];
		if (ne==-1)
			continue;
		if (p1==n-1)
		{		
			if (a[ne].isterm==0)

				continue;
		}
		if (i==c)
		{
			//st+='a'+i;
			char v=r(p1+1,ne,min(5,last+1));
			if (v!=100)
				res=min(res,v);
			//st.pop_back();
		}
		else
		{
			if (last!=5)
				continue;
			//st+='a'+i;
			char v=r(p1+1,ne,1);
			if (v!=100)
			{
				v++;
				res=min(res,v);
			}
			//st.pop_back();
		}
	}
	return dp[p1][p2][last]=res;
}
int main()
{
#ifdef Fcdkbear
    double beg=clock();
	//freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
	//freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

	FILE *f1=fopen("garbled_email_dictionary.txt","r");
	a.push_back(*new ver);
	while (fscanf(f1,"%s",&s)!=EOF)
	{
		n=strlen(s);
		add();
	}
	//cout<<a.size()<<endl;
	//return 0;
	fclose(f1);
	FILE *f2=fopen("in.txt","r");
	int t;
	fscanf(f2,"%d",&t);
	for (now=1; now<=t; ++now)
	{
		fscanf(f2,"%s",&s);
		n=strlen(s);
		MEMS(dp,-1);
		int res=r(0,0,5);
		printf("Case #%d: %d\n",now,res);
		fprintf(stderr,"Case #%d done\n",now);
	}
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}