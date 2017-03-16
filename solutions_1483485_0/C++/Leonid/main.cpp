#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)

void openfiles()
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("test.out","wt",stdout);
#endif
}

char code[255] = {0};

void init() {
code['a'] = 'y';
code['b'] = 'h';
code['c'] = 'e';
code['d'] = 's';
code['e'] = 'o';
code['f'] = 'c';
code['g'] = 'v';
code['h'] = 'x';
code['i'] = 'd';
code['j'] = 'u';
code['k'] = 'i';
code['l'] = 'g'; 
code['m'] = 'l';
code['n'] = 'b';
code['o'] = 'k';
code['p'] = 'r';
code['q'] = 'z';
code['r'] = 't';
code['s'] = 'n';
code['t'] = 'w';
code['u'] = 'j';
code['v'] = 'p';
code['w'] = 'f';
code['x'] = 'm';
code['y'] = 'a';
code['z'] = 'q';
code[' '] = ' ';
}

void solve(int test)
{
	char a[10000];
	gets(a);
	int len = strlen(a);
	static int ntest = 0;
	cout << "Case #" << ++ntest << ": ";
	for (int i = 0; i < len; i++) {
		cout << code[a[i]];
	}
	cout << endl;	
}

int main()
{
	openfiles();
	init();
	int n; scanf("%d ",&n); REP(i,n) solve(i + 1);
	
	return 0;
}