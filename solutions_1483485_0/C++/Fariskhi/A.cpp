#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <bitset>
#include <fstream>
using namespace std;
 
#define LL long long
#define INF 2000000000
#define INF64 9200000000000000000LL
#define eps 1e-9
 
#define DEBUG printf("===DEBUG===\n")
#define DEBUGX(a) cout << "DEBUG : " << a << endl
#define TC(a) while (a--)
 
#define PB push_back
#define MP make_pair
#define fi first
#define se second
 
#define REP(a,b) for (int a = 0; a < b; a++)
#define FORN(a,b,c) for (int a = b; a <= c; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string b = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string c = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	string ax = "our language is impossible to understand";
	string bx = "there are twenty six factorial possibilities";
	string cx = "so it is okay if you want to just give up";
	
	map <char,char> decrypt;
	
	REP(i,a.length()) decrypt[a[i]] = ax[i];
	REP(i,b.length()) decrypt[b[i]] = bx[i];
	REP(i,c.length()) decrypt[c[i]] = cx[i];
	decrypt['q'] = 'z'; decrypt['z'] = 'q';
	
	int t;
	scanf("%d",&t);
	getchar();
	FORN(tc,1,t)
	{
		char s[111]; gets(s);
		string g = s;
		printf("Case #%d: ",tc);
		REP(i,g.length()) cout << decrypt[g[i]];
		cout << endl;
	}
	
	fclose(stdin); fclose(stdout);
	return(0);
}
