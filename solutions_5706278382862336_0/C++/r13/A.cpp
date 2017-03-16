#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int solve(ll p, ll q)
{
	forr(i,1,60)
	{
		if ( (p << i) >= q )
			return i;
	}
	cout << "\nUPS\n";
	return -1;
}

int main()
{
    ofstream fout("out.txt");
	freopen("debug.txt","w",stdout);
    freopen("inA.txt","r",stdin);

    int t;
    cin >> t;
	ll p, q;
	char c;
	rep(tc,t)
	{
		cin >> p >> c >> q;
		ll d = gcd(p,q);
		p /= d; 
		q /= d;
		if (q & (q-1))
			fout << "Case #" << tc + 1 << ": " << "impossible" << "\n";
		else
			fout << "Case #" << tc + 1 << ": " << solve(p,q) << "\n";
	}

	cout << "Done " << clock() << endl;

    return 0;
}