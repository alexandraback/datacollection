#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;

const ll M = 1000000007;

int innerC[255], lC[255], rC[255], wC[255], endC[255],addedC[255];

bool prepare(const vector<string>& cs)
{
	forr(c,'a','z')
	{
		innerC[c] = 0;
		wC[c] = rC[c] = lC[c] = 0;
		endC[c] = 0;
		addedC[c] = 0;
	}

	rep(i,cs.size())
	{
		const string& s = cs[i];
		int a = 0, b = s.size()-1;
		while (a < s.size() && s[a] == s.front())
			++a;
		while (b && s[b] == s.back())
			--b;

		forr(ci,a,b)
			if (s[ci] != s[ci-1])
				innerC[s[ci]]++;

		if (a <= b && s.front() == s.back()) // "aba"
			return false;

		if (s.front() != s.back())
		{
			lC[s.front()]++;
			rC[s.back()]++;
			endC[s.front()] = s.back();
		} else
			wC[s[0]]++;
	}

	forr(c,'a','z')
	{
		if (innerC[c] > 1)
			return false;

		if (innerC[c] && (lC[c] || rC[c] || wC[c]))
			return false;

		if (lC[c] > 1 || rC[c] > 1)
			return false;

		// loops detect
		if (lC[c] == 1 && rC[c] == 0)
		{
			char cc = c;
			while (endC[cc] && !addedC[cc])
			{
				addedC[cc] = 1;
				cc = endC[cc];
			}

			if (endC[cc] && addedC[cc])
				return false;
		}
	}

	// loops
	forr(c,'a','z')
		if (lC[c] == 1 && !addedC[c])
			return false;

	return true;
}

ll factorial(int n)
{
	ll ans = 1;
	forr(i,2,n)
		ans = (ans * i) % M;

	return ans;
}

ll solve()
{
	ll ans = 1;
	int ws = 0;
	
	forr(c,'a','z')
		if (wC[c])
		{
			ans *= factorial(wC[c]);
			ans %= M;
			if (lC[c] == 0 && rC[c] == 0)
				++ws;
		}

	forr(c,'a','z')
		if (lC[c] == 1 && rC[c] == 0)
		{
			++ws;
		}

	ans *= factorial(ws);
	ans %= M;

	return ans;
}

int main()
{
    ofstream fout("out.txt");
    freopen("in.txt","r",stdin);
	freopen("debug.txt","w",stdout);

    int t;
    cin >> t;
	int n;
	vector<string> cs;
	cs.reserve(100);

	rep(tc,t)
	{
		cin >> n;
		cs.clear();
		cs.resize(n);
		rep(i,n)
			cin >> cs[i];

		if (prepare(cs))
			fout << "Case #" << tc + 1 << ": " << solve() << "\n";
		else
			fout << "Case #" << tc + 1 << ": " << 0 << "\n";
	}

    return 0;
}