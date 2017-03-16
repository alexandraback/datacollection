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

#define MAX 150

char s[MAX];
int n;

bool spol(char z)
{
	return (z != 'a' && z != 'e' && z != 'i' && z != 'o' && z != 'u'); //a, e, i, o, and u 
}

bool ok(int zac, int kon)
{
	int kolko = 0;
	FOR(i,zac,kon)
	{
		//cout << s[i] << endl;
		if (!spol(s[i]))
		{
			if (kolko >=n) return true;
			kolko=0;
		}
		else
			kolko++;
	}
	//cout << zac << " " << kon << " " << kolko << " " << n << endl;
	return kolko >= n;
}

int main()
{
	int Q;
	scanf("%d",&Q);
	FOR(q,1,Q)
	{
		scanf("%s %d",s,&n);
		//puts(s);
		int kolko = 0;
		int L = (int)strlen(s);
		FOR(i,0,L-1)
			FOR(j,i,L-1)
				kolko+= ok(i,j);
		printf("Case #%d: %d\n",q,kolko);
	}
	return 0;
}
