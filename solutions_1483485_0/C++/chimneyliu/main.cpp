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
#include <cstring>

using namespace std;
typedef long long int64;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= a; --i)
#define SIZE(a) ((a).size())

template<typename T> T gcd(T a, T b) { if (!b) return a; else return gcd(b, a%b);}
template<typename T> void ext_euclid(T a, T b, T& x, T& y) { if (!b) {x=1; y=0;} else {int xx, yy; ext_euclid(b, a%b, xx, yy); x=yy; y=-yy*(a/b)+xx;}}

int main()
{
	const char* inFile = "A-small-attempt0.in";
	const char* outFile = "out.txt";
	freopen(inFile, "r", stdin);
	freopen(outFile, "w", stdout);

	string gSample[4] = {"y qee", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string eSample[4] = {"a zoo", "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

	map<char, char> mapping;
	int exist[26];
	memset(exist, 0, sizeof(exist));
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<gSample[i].length(); j++)
		{
			mapping[gSample[i][j]] = eSample[i][j];
			exist[eSample[i][j]-'a'] = 1;
		}
	}
	for (int i=0; i<26; i++)
	{
		if (!exist[i])
			mapping['z'] = (char)(i+'a');
	}

	int T;
	cin >> T;
	cin.get();
	for (int t=0; t<T; t++)
	{
		string line;
		getline(cin, line);
		string res;
		for (int i=0; i<line.length(); i++)
			res += mapping[line[i]];
		printf("Case #%d: %s\n", t+1, res.c_str());
	}
	
	return 0;
}