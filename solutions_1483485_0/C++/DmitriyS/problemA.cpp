#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

#define pb push_back
#define sz(x) ((int) (x).size())
#define fo(i, n) for (int i = 0; i < (n); i++)
#define rfo(i, n) for (int i = (n) - 1; i >= 0; i--)
#define clr(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll,ll> pll;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<char,char> dict;
	dict['a'] = 'y';
	dict['b'] = 'h';
	dict['c'] = 'e';
	dict['d'] = 's';
	dict['e'] = 'o';
	dict['f'] = 'c';
	dict['g'] = 'v';
	dict['h'] = 'x';
	dict['i'] = 'd';
	dict['j'] = 'u';
	dict['k'] = 'i';
	dict['l'] = 'g';
	dict['m'] = 'l';
	dict['n'] = 'b';
	dict['o'] = 'k';
	dict['p'] = 'r';
	dict['q'] = 'z';
	dict['r'] = 't';
	dict['s'] = 'n';
	dict['t'] = 'w';
	dict['u'] = 'j';
	dict['v'] = 'p';
	dict['w'] = 'f';
	dict['x'] = 'm';
	dict['y'] = 'a';
	dict['z'] = 'q';
	
	int N;
	string cases;
	getline(cin,cases);
	N = atoi(cases.c_str());
	fo(casenum,N)
	{
		string str;
		getline(cin,str);
		cout << "Case #" << casenum+1 << ": ";
		fo(j,sz(str))
			if (str[j] != ' ')
				str[j] = dict[str[j]];
		cout << str << endl;		
	}
	
	
	return 0;
}