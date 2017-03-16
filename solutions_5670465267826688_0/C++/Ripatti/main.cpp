#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

LL L, X;
string S;

int T[5][5] = {
	{ 0, 0,  0,  0,  0 },
	{ 0, 1,  2,  3,  4 },
	{ 0, 2, -1,  4, -3 },
	{ 0, 3, -4, -1,  2 },
	{ 0, 4,  3, -2, -1 } };

void sol()
{
	if (X > 16)
	{
		X = 12 + X%4;
		if (X==12) X += 4;
	}

	string s;
	FOR(a,1,X) s = s + S;

	bool minus = false;
	int state = 1;
	bool flag1 = false, flag2 = false;
	FA(a,s)
	{
		if (s[a]=='i') state = T[state][2];
		else if (s[a]=='j') state = T[state][3];
		else state = T[state][4];
		if (state < 0)
		{
			state *= -1;
			minus = !minus;
		}
		if (state==2 && !minus) flag1 = true;
		if (flag1 && state==4 && !minus) flag2 = true;
	}

	if (flag2 && state==1 && minus) cout << "YES";
	else cout << "NO";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t=0;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";
		cin >> L >> X >> S;
		cout << "Case #" << a << ": ";
		sol();
		cout << "\n";
	}
	return 0;
}
