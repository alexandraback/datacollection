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

int Q;

#define MAX 1050

double A[MAX],  B[MAX];
int N;

bool use[MAX];

int find(double a)
{
	int best = -1;
	FOR(i,0,N-1)
		if (!use[i] && B[i] > a && (best == -1 || B[best] > B[i]))
			best = i;
	if (best >= 0) return best;
	FOR(i,0,N-1)
		if (!use[i] && (best == -1 || B[best] > B[i]))
			best = i;
	return best;
}

int optimal_strategy()
{
	int c = 0;
	FOR(i,0,N-1) use[i] = false;
	FOR(i,0,N-1)
	{
		int id = find(A[i]);
		use[id] = true;
		if (A[i] > B[id]) c++;
	}
	return c;
}

int p[MAX];

int find2(double a)
{
	int best = -1;
	FOR(i,0,N-1)
		if (!use[i] && B[i] < a && (best == -1 || B[best] < B[i]))
			best = i;
	if (best >= 0) return best;
	FOR(i,0,N-1)
		if (!use[i] && (best == -1 || B[best] > B[i]))
			best = i;
	return best;
}

int best_strategy()
{
	sort(A,A+N);
	//FOR(i,0,N-1) printf("%.3lf ", A[i]); puts("");
//	FOR(i,0,N-1) printf("%.3lf ", B[i]); puts("");
	
	int c = 0;
	FOR(i,0,N-1) use[i] = false;
	FORD(i,N-1,0)
	{
		int id = find2(A[i]);
		use[id] = true;
		if (A[i] > B[id]) c++;
	}
	return c;
}


int main()
{
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		scanf("%d",&N);
		FOR(i,0,N-1) scanf("%lf",A+i);
		FOR(i,0,N-1) scanf("%lf",B+i);
		printf("Case #%d: %d %d\n", q, best_strategy(), optimal_strategy());
	}
	return 0;
}
