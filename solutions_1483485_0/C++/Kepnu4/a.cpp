#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cassert>
#include <climits>
#include <fstream>

using namespace std;

#define Filename ""
#define sqr(a) (a)*(a)

typedef long long lng;
typedef long double ldb;

const double EPS = 1e-8;

string s;

char a[505];

void Load()
{
	s = "";
	for (int c = getchar();c != EOF && c != '\n';c = getchar())
		s += c;
}

void Solve()
{
	string ans = s;
	for (int i = 0;i < ans.size();i++)
		ans[i] = (ans[i] == ' ' ? ' ' : a[ans[i]]);
	puts(ans.c_str());
}

int main()
{
	//freopen(Filename".in", "r", stdin);
	//freopen(Filename".out", "w", stdout);
	string s, t;
	s = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	t = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	for (int i = 0;i < s.size();i++) {
     	if (s[i] == ' ') continue;
     	if (a[s[i]] == 0) a[s[i]] = t[i];
     	else if (a[s[i]] != t[i]) cerr << "FTW?\n";
    }
    a['q'] = 'z';
    a['z'] = 'q';

	int T;
	scanf ("%d\n", &T);

	for (int i = 0;i < T;i++) {
		printf ("Case #%d: ", i+1);
		Load();

		Solve();
	}

	return 0;
}
