#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define LL long long
using namespace std;

vector<LL> v;
LL n;
string s;

void gen() 
{
	LL x = 1;
	while(x < 1000000000000000LL)
	{
		v.push_back(x);
		x *= 2;
	}
}

void solve()
{
	cin >> s;
	LL i = 0, p = 0, q = 0;
	while(s[i] != '/')p = p*10 + (LL)s[i]-'0', i++;
	i++;
	while(i < (int)s.size())q = q*10 + s[i]-'0', i++;
	i = __gcd(p, q);
	p /= i;
	q /= i;
	for(int i = 0; i < (int)v.size(); i++)
	{
		if(v[i]/q*q == v[i])
		{
			int x = 1;
			while(p*2 < q)q/=2, x++;
			cout << x << endl;
			return;
		}
	}
	cout << "impossible\n";
}

int main() 
{
	gen();
	cin >> n;
	for(int i = 1; i <= n; i++)cout << "Case #" << i << ": ", solve();
}
