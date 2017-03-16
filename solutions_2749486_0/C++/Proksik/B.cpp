//--BY--©--WA-
#include<iostream> //cout, cin, getline

#include<algorithm> //find, reaplce, swap, sort, lower_bound, uper_bound, binnary_search...
#include<vector> //push_back, size, resize, 
#include<string>
#include<queue> //empty, front, back, push
#include<stack> //push, top, empty
#include<map>
#include<set>
#include<list> //spajazny zoznam .. vsetko v O(1)

#include<stdio.h> //printf, scanf, getchar, putchar
#include<math.h> //cos, sin, exp, pow, sqrt,  flnoor, cell
#include<stdlib.h> //atio, atl, strtod, strtol, atof, abs, 
#include<ctype.h> //isalnum, isalpha, isdigit, islower, isupper, toupper, tolower, 
#include<string.h> //strcm, strstr, strlen,

using namespace std;

#define FOREACH(obj,it) for(__typeof(obj.begin()) it = (obj).begin(); it != (obj).end(); (it)++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)
#define DEBUG(V,S) FOR(i,0,S-1){cout << i << ". " << V[i] << endl;}

#define PB push_back
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define fi first
#define se second

#define SIZE(s) (int) (s).size()

#define INF 987654321
#define EPS 1e-9
#define ld long double // %Lf, double %lf
#define ll long long   // %llf

//--------------------------------------------------------------------------------------

int Y, X;
set< PII > S;

int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};
char dirs[] = {'N','E','S','W'};

queue< pair< PII, string> > Q;

bool in(int x, int y)
{
	return (abs(x) < 5000 && abs(y) < 5000);
}
	
string bfs()
{
	while(!Q.empty()) Q.pop();
	S.clear();
	S.insert(MP(0,0));
	Q.push( MP(MP(0,0),"") );
	while(!Q.empty())
	{
		PII poz = Q.front().fi;
		string steps = Q.front().se;
		Q.pop();
		int step = SIZE(steps) + 1; 
		if (poz.fi == X && poz.se == Y)
			return steps;
		FOR(dir,0,3)
		{
			int ny = step*diry[dir] + poz.se;
			int nx = step*dirx[dir] + poz.fi;
			if (S.find(MP(nx,ny)) == S.end() && in(nx,ny))
			{
				//este tam nebol
				string nsteps = steps+dirs[dir];
				Q.push( MP( MP(nx,ny), nsteps) );
				S.insert(MP(nx,ny));
			}
		}
	}
	return "";
}

int main()
{
	int Q;
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		scanf("%d %d",&X,&Y);
		printf("Case #%d: %s\n",q,bfs().c_str());
	}
	return 0;
}
