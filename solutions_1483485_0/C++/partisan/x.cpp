#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <list>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define FOR(i,a,b) for(int i(a),_b(b); i < _b; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i(a),_b(b); i >= _b; --i)
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)(a).size()

#define L 110

//"yhesocvxduiglbkr#tnwjpfma#" absent q,z

char f[] = "yhesocvxduiglbkrztnwjpfmaq";
char s[L];
int n;

void find_match()
{
	char a[3][L],b[3][L]; // for 1st test
	REP(i,26)
		f[i] = '#';
	scanf("%d",&n);
	gets(a[0]);
	REP(i, n)
		gets(a[i]);
	REP(i, n)
		gets(b[i]);
	REP(i, n)
	{
		int len = strlen(a[i]);
		REP(j, len)
			if(a[i][j] != ' ' && f[a[i][j] - 'a'] == '#')
				f[a[i][j] - 'a'] = b[i][j];
	}
}

int main()
{
	freopen("input.txt","r", stdin);
	freopen("output.txt","w", stdout);
	//find_match();	
	scanf("%d",&n);
	gets(s);
	REP(i, n)
	{
		gets(s);
		int len = strlen(s);
		REP(j, len)
			if(s[j] != ' ')
				s[j] = f[s[j] - 'a'];
		printf("Case #%d: %s\n",i+1, s);
	}
	return 0;
}

