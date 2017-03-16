
#define _CRT_SECURE_NO_DEPRECATE 

#include <string> 
#include <vector> 
#include <map> 
#include <list> 
#include <set> 
#include <queue> 
#include <iostream> 
#include <sstream> 
#include <stack> 
#include <deque> 
#include <cmath> 
#include <memory.h> 
#include <cstdlib> 
#include <cstdio> 
#include <cctype> 
#include <algorithm> 
#include <utility> 

using namespace std; 

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define ALL(V) V.begin(), V.end()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PI;

char buf[1 << 10];

string s1[] = {"y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string s2[] = {"a zoo", "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

map<char, char> Map;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	REP(i, 4)
	{
		string a = s1[i], b = s2[i];
		if(a.length() != b.length())
			throw -1;
		REP(j, a.length())
		{
			if(isspace(a[j]))
				continue;
			if(Map.count(a[j]) && Map[a[j]] != b[j])
				throw -1;
			Map[a[j]] = b[j];
		}
	}

	set<char> Set;
	
	REP(i, 25)
		Set.insert(Map['a' + i]);

	REP(i, 26)
		if(!Set.count('a' + i))
			Map['z'] = 'a' + i;

	int tests;

	scanf("%d", &tests);
	gets(buf);

	REP(I, tests)
	{
		gets(buf);
		int len = (int)strlen(buf);
		printf("Case #%d: ", I + 1);
		REP(i, len)
			if(isspace(buf[i]))
				putchar(buf[i]);
			else
				putchar(Map[buf[i]]);
		puts("");
	}

	return 0;
}