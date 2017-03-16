#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
//typedef vector<bool> vb;
typedef vector<string> vstr;
#define IOS std::ios_base::sync_with_stdio(false)
#define EPS 1e-07
#define PI (2*acos(0.0))
//struct point { double x, y; };
//struct line { double a, b, c; }; // ax + by + c = 0 
//funciones
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

double dabs(double a)
{
	return (a < 0) ? (a * -1) : a;
}

int dcomp (double a, double b) {
	if (a - b > EPS) return 1;// a > b
	else if (b - a > EPS) return -1; // a < b
	return 0; // a == b
}

int main()
{
	int casos;
	scanf("%d", &casos);
	char pal[110];
	for(int cas = 0; cas < casos; cas++)
	{
		printf("Case #%d: ", cas+1);
		scanf("%s", pal);
		
		int n = strlen(pal);
		//printf("--- n: %d----",n);
		pal[n] = '+';
		n++;
		int ans = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(pal[i] != pal[i+1])
				ans++;
		}
		
		printf("%d\n", ans);
		
		
		
		
	}
	
	return 0;
}

