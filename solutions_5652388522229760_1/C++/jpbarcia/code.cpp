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


bool dig[10];
vi ans;



int main()
{
	int casos;
	scanf("%d", &casos);
	
	for(int cas = 0; cas < casos; cas++)
	{
		printf("Case #%d: ", cas+1);
		memset(dig, 0, sizeof dig);
		ans.clear();
		ll ini, a;
		scanf("%lld", &ini);
		if(ini == 0)
		{
			printf("INSOMNIA\n");
			continue;
		}
		ll temp = ini;
		while(ans.size() < 10)
		{
			a = temp;
			while(true)
			{
				if(a <= 0)
					break;
				if(!dig[a%10])
				{
					dig[a%10] = true;
					ans.push_back(a%10);
				}
				a /= 10;
			}
			if(ans.size() < 10)
				temp += ini;
		}
		
		printf("%lld\n", temp);
		
	}
	
	return 0;
}

