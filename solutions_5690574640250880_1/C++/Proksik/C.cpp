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

#define MAX 60

int Y, X, M;

char T[MAX][MAX];

bool visits[MAX][MAX];

int diry[] = {0,1,0,-1,1,-1,1,-1};
int dirx[] = {1,0,-1,0,1,-1,-1,1};

bool ok(int y, int x)
{
	return y >= 0 && y < Y && x >=0 && x < X;
}

bool can_go(int y, int x)
{
	FOR(dir,0,7)
	{
		int ny = diry[dir] + y;
		int nx = dirx[dir] + x;
		if (ok(ny, nx) && T[ny][nx] == '*') return false;
	}
	return true;
}

void dfs(int y, int x)
{
	visits[y][x] = true;
	if (!can_go(y,x)) return;
	FOR(dir,0,7)
	{
		int ny = diry[dir] + y;
		int nx = dirx[dir] + x;
		if (ok(ny, nx) && T[ny][nx] == '.' && !visits[ny][nx]) dfs(ny, nx);
	}
}

bool valid()
{
	FOR(i,0,Y-1) FOR(j,0,X-1) visits[i][j] = false;
	dfs(Y-1,X-1);
	
	int c = 0;
	FOR(i,0,Y-1) FOR(j,0,X-1) if (T[i][j] == '*') c++;
	
	FOR(i,0,Y-1) FOR(j,0,X-1)
		if (T[i][j] != '*' && !visits[i][j]) return false;
		
	return c == M;
}

#define DEBUG 0
#define DEBUG_PRINT 0

void print(int q)
{
	if (DEBUG) return ;
	
	printf("Case #%d:\n",q);
	FOR(i,0,Y-1)
	{
		FOR(j,0,X-1)
		{
			if (T[i][j] == '-') T[i][j] = '.';
			putchar(T[i][j]);
		}
		printf("\n");
	}
	
	if (!valid())
		printf("NOT VALID\n");
}

void clear()
{
	FOR(i,0,Y-1) FOR(j,0,X-1) T[i][j] = '*';
	T[Y-1][X-1] = 'c';
}

void insert(int sy, int ey, int sx, int ex)
{
	if (sy < 0 || sx < 0 || ey >= Y || ex >= X) return ;
	FOR(i,sy,ey) FOR(j,sx,ex) if (T[i][j] != 'c') T[i][j] = '.';
}

bool generate()
{
	//ideme vygenerovat bodky do hviezdiciek
	int K = X*Y-M;
	
	if (DEBUG_PRINT) printf("Generate - x: %d %d - %d\n", Y, X, M);
	FOR(x,1,X)
	{
		int y = K / x;
		int zvy = K % x;
		
		if (DEBUG_PRINT) printf("Navrh: %d x %d + %d\n", y, x, zvy);
		
		clear();
		insert(Y-y,Y-1,X-x,X-1);
		insert(Y-y-1,Y-y-1,X-zvy,X-1);
		
		if (valid()) return true;
	}
	
	if (DEBUG_PRINT) printf("Generate - y: %d %d - %d\n", Y, X, M);
	FOR(y,1,Y)
	{
		int x = K / y;
		int zvy = K % y;
		
		if (DEBUG_PRINT) printf("Navrh: %d x %d + %d\n", y, x, zvy);
			
		clear();
		insert(Y-y,Y-1,X-x,X-1);
		insert(Y-zvy,Y-1,X-x-1,X-x-1);
		
		if (valid()) return true;
	}
	
	
	//sepcial case
	FOR(x,1,X)
	{
		FOR(y,1,Y)
		{
			int zvy = K - (x*y);
			FOR(a,1,zvy) if (zvy % a == 0)
			{
				int b = zvy / a;
		
				if (DEBUG_PRINT) printf("Navrh: %d x %d a %d x %d\n", y, x, a, b);
			
				clear();
				insert(Y-y,Y-1,X-x,X-1);
				insert(Y-y-a,Y-y-1,X-b,X-1);
				
				if (valid()) return true;
				
				clear();
				insert(Y-y,Y-1,X-x,X-1);
				insert(Y-a,Y-1,X-x-b,X-x-1);
				
				if (valid()) return true;
			}
		}
	}

	//sepcial - special case
	FOR(x,1,X)
	{
		FOR(y,1,Y)
		{
			int zvy = K - (x*y);
			FOR(a,1,zvy)
				FOR(b,1,zvy) if ( (a*b) <= zvy)
				{
					if (DEBUG_PRINT) printf("Speci. Navrh: %d x %d a %d x %d\n", y, x, a, b);
					
					int zvy2 = zvy - a*b;
					FOR(c,1,zvy2) if (zvy2 % c == 0)
					{
						int d = zvy2 / c;
						
						if (DEBUG_PRINT) printf("Speci. Navrh: %d x %d a %d x %d a %d x %d\n", y, x, a, b, c, d);
						
						clear();
						insert(Y-y,Y-1,X-x,X-1);
						insert(Y-y-a,Y-y-1,X-b,X-1);
						insert(Y-y-a-c,Y-y-a-1,X-d,X-1);
						
						if (valid()) return true;
						
						clear();
						insert(Y-y,Y-1,X-x,X-1);
						insert(Y-a,Y-1,X-x-b,X-x-1);
						insert(Y-c,Y-1,X-x-b-d,X-x-b-1);
						
						if (valid()) return true;
					}
				}
		}
	}	
	
	return false;
}

void impossible(int q)
{
	printf("Case #%d:\n",q);
	printf("Impossible\n");
	if (DEBUG) printf("%d %d %d - %d\n", Y, X, M, X*Y - M);
}

void solve(int q)
{	
	if (generate())
		print(q);
	else
		impossible(q);
}

int main()
{
	int Q;
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		scanf("%d %d %d", &Y, &X, &M);
		solve(q);
	}
	return 0;
}
