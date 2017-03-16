#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <fstream>
#include <set>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b)	for(int i=(a);i<(b);++i)
#define REP(iter,v) for(typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define mp make_pair
#define pb push_back
#define SZ size()

typedef long long ll, int64;

string s = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string t = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";


int main(void)	{
	map<char, char> m;
	FOR (i, 0, s.SZ)	{
		if (m.find(s[i]) == m.end())	{
			m[s[i]] = t[i];
		}
		else	{
			assert(m[s[i]] == t[i]);
		}
	}
	m['z'] = 'q';
	m['q'] = 'z';
	int n;
	cin >> n;
	cin.ignore();
	FOR (cs, 0, n)	{
		getline(cin, s);

		cout << "Case #" << (cs+1) << ": ";
		FOR (i, 0, s.SZ)	{
			cout << m[s[i]];
		}
		cout << endl;
	}
}