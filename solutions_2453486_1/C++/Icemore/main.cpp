#pragma comment(linker,"/STACK:256000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <utility>
#include <ctime>
#include <memory.h>
#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define forv(i, a) for(int i=0; i<(int)a.size(); i++)
#define mset(a, val) memset(a, val, sizeof(a))
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define VI vector< int >
#define VS vector< string >
#define PII pair< int,int >
#define PDD pair< double,double >
#define PIS pair< int, string >
#define PLL pair<long long, long long>
#define sqr(a) ((a)*(a))
#define cube(a) ((a)*(a)*(a))
#define pi 3.1415926535897932384626433832795
#define PI pi
#define iinf 1000000000
#define linf 1000000000000000000LL
#define sinf 10000
#define eps 1e-9
#define lng long long
#define ulng unsigned long long
#define X first
#define Y second
using namespace std;
#define prev asdprev
#define exit(a) { if (a) cerr<<"oops "<<a<<endl; exit(a); }

string field[4];

bool check(char ch)
{
	
	forn(i, 4)
	{
		//rows
		bool won=true;
		forn(j, 4)
			if(field[i][j]!=ch && field[i][j]!='T') won=false;

		if(won) return true;

		//cols
		won=true;
		forn(j, 4)
			if(field[j][i]!=ch && field[j][i]!='T') won=false;
		if(won) return true;
	}

	//diags
	bool won1=true, won2=true;
	forn(i, 4)
	{
		if(field[i][i]!=ch && field[i][i]!='T') won1=false;
		if(field[i][3-i]!=ch && field[i][3-i]!='T') won2=false;

	}

	if(won1 || won2) return true;

	return false;
}

string solve()
{
	
	forn(i, 4) cin>>field[i];

	if(check('X'))
		return "X won";

	if(check('O'))
		return "O won";

	bool draw=true;
	forn(i, 4)forn(j, 4)
		if(field[i][j]=='.') 
			draw=false;

	if(draw)
		return "Draw";
	else
		return "Game has not completed";

}

#define taska "casting"
int main() {
#ifdef __ASD__
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
	//freopen(taska".in", "r", stdin);freopen(taska".out", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int T;
	cin>>T;

	forn(tc, T)
	{
		cout<<"Case #"<<tc+1<<": "<<solve()<<endl;
	}
	
	return 0;
}

