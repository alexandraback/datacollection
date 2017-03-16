#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
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
	int k,c,s;
	ll pot[110];
	for(int cas = 0; cas < casos; cas++)
	{
		printf("Case #%d:", cas+1);
		scanf("%d %d %d", &k, &c, &s);
		memset(pot, 0, sizeof pot);
		pot[0] = 1;
		for(int i = 1; i <= c; i++)
		{
			pot[i] = pot[i-1]*k;
		}
		if(c >= k)
		{
			c=k;
			ll tempp = 1;
			ll ans = 0;
			for(int i = k-1; i > 0; i--)
			{
				
				ans += (i*tempp);
				tempp *= k;
			}
			printf(" %lld\n", ans+1);
			continue;
		}
		
		int ps = k/c;
		
		if(k%c != 0)
			ps++;
			
		if(ps > s)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}
		
		int punt = 0;
		ll tans = 0;
		for(int i = 0; i < k; i += c)
		{
			punt = i;
			tans = 0;
			for(int m = i; m < i+c; m++)
			{
				tans += punt*pot[i+c-m-1];
				punt++;
				if(punt >= k)
					break;
			}
			if(tans+1 >= pot[c])
				printf(" %lld", pot[c]);
			else
				printf(" %lld", tans+1);
		}
		printf("\n");
		
		
		
		
		
	}
	
	return 0;
}

