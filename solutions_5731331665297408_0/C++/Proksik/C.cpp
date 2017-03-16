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

#define MAX 10

int N, M;
string Zips[MAX];
int G[MAX][MAX];

int perm[MAX];

bool valid()
{
	//testujeme ci je validna permutacia
	int active = perm[0];
	stack<int> S;
	FOR(i,1,N-1)
	{
		int current = perm[i];
		while(true)
		{
			if (!G[active][current])
			{
				if (S.empty()) return false;
				active = S.top();
				S.pop();
			}
			else
				break;
		}
		//active je spojeny s current
		S.push(active);
		active = current;
	}
	return true;
}

string solve()
{
	string best = "";
	FOR(i,0,N-1) perm[i] = i;
	do
	{
		if (valid())
		{
			string s = "";
			FOR(i,0,N-1) s+= Zips[perm[i]];
			if (s < best || best == "") best = s;
		}
	} while( next_permutation(perm, perm+N));
	return best;
}

int main()
{
	int a, b;
	int Q;
	cin >> Q;
	FOR(q,1,Q)
	{
		cin >> N >> M;
		FOR(i,0,N-1) cin >> Zips[i];
		FOR(i,0,N-1) FOR(j,0,N-1) G[i][j] = 0;
		while(M--)
		{
			cin >> a >> b;
			a--; b--;
			G[a][b] = 1;
			G[b][a] = 1;
		}
		cout << "Case #" << q << ": " << solve() << endl;
	}
	return 0;
}
