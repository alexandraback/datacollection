#include <stdio.h>
#include <iostream>

using namespace std;

#define FOR(i,a,b)      for(int i(a);i<b;++i)
#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
#define REP(i,n)        FOR(i,0,n)
#define scanI(i)                scanf("%d",&i)
#define printI(i)               printf("%d ",i)
#define printIln(i)             printf("%d\n",i)
#define scanS(i)                scanf("%s",&i)
#define printS(i)               printf("%s ",i)
#define printSln(i)             printf("%s\n",i)


string fairsquare[] = {"1","4","9","121","484","10201","12321","14641","40804","44944","1002001","1234321","4008004","100020001","102030201","104060401","121242121","123454321","125686521","400080004","404090404","10000200001","10221412201","12102420121","12345654321","40000800004","1000002000001","1002003002001","1004006004001","1020304030201","1022325232201","1024348434201","1210024200121","1212225222121","1214428244121","1232346432321","1234567654321","4000008000004","4004009004004"};
int f = 39;

bool more(string x, string y)
{
	if (x.size() != y.size()) return x.size() > y.size();
	REP(i, x.size())
		if (x[i]!=y[i]) return x[i] > y[i];
	return false;
}
bool equal(string x, string y)
{
	if (x.size() != y.size()) return false;
	REP(i, x.size()) if (x[i]!=y[i]) return false;
	return true;
}

int loc(string x)
{
	REP(i, 39) if (more(fairsquare[i],x)) return i-1;
	return 38;
}


int main()
{
	int T, ai, bi, r; scanI(T);
	string a, b;
	REP(t, T)
	{
		cin >> a >> b;
		ai = loc(a);
		bi = loc(b);
		printf("Case #%d: ", t+1);
		r = bi-ai;
		if (fairsquare[ai]==a) r++;
		printIln(r);
	}
    return 0;
}
