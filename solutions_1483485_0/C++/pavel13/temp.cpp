#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
using namespace std;
#define REP(i,n) for(int i=0,n_=(n);i<n_;i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOR(i,a,b) for (int i=a,b_=b;i<=(b);i++)
#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)(a).size()
#define SORT(a) sort(ALL(a))
#define INF 1073741823
#define DEB(x) cerr<<#x<<":"<<x<<"\n"
#define PB(b) push_back(b)
#define i64 long long
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

vector<int> SplitInt(string &s)
{
	vector<int>Res;int tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

vector<string> SplitStr(string &s)
{
	vector<string>Res;string tmp;stringstream a(s);
	while (a>>tmp){Res.push_back(tmp);}return Res;
}

//////////////////////////////////////////////////////////////

string R[]={"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up"};
string h="yhesocvxduiglbkrztnwjpfmaq";
int main ()
{
	int c,n,k;
	char Pal[122222];
	scanf ("%d",&c);
	gets(Pal);
	char M[1111];
	memset(M,-1,sizeof M);
	FOR(cas,1,c)
	{
		int res=0;

		
		gets(Pal);
		string s;
		REP(i,strlen (Pal))
		{
			if (Pal[i]!=' ')
			{
				s+=h[Pal[i]-'a'];
			}
			else
				s+=Pal[i];
		}
//		REP(i,strlen (Pal))
//		{
//			if (Pal[i]!=' ')
//			if (M[Pal[i]]==-1||M[Pal[i]]==R[cas-1][i])
//			{
//				M[Pal[i]]=R[cas-1][i];
//			}
//			else
//			{
//				DEB("err");
//			}
//		}
		printf ("Case #%d: %s",cas,s.c_str());

		printf ("\n");
	}
//	REP(i,26)
//	{
//		if (M[i+'a']!=-1)
//		printf ("%c",M[i+'a']);
//		else
//		printf (" %c ",i+'a');
//		
//	}
//	printf ("\n");
	return 0;
}

