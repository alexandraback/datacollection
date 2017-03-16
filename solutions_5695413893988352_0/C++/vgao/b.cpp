#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct score
{
	ll c, j;

	bool operator < (const score & r) const
	{
		ll x = c < j ? j - c : c - j;
		ll y = r.c < r.j ? r.j - r.c : r.c - r.j;
		if (x != y)
			return x < y;
		if (c != r.c)
			return c < r.c;
		return j < r.j;
	}

	score(ll a = 0, ll b = 0):
		c(a), j(b)
	{
	}
};

char A[100], B[100];

char * P[32]; size_t M = 0;

score X;

void dfs(size_t i, char c)
{
	*P[i] = c;
	if (i + 1 < M)
		for (char c = '0'; c <= '9'; ++c)
			dfs(i + 1, c);
	else {
		score x = score(atoll(A), atoll(B));
		if (x < X)
			X = x;
	}
}
   
int main()
{
	size_t __; cin >> __;
	for (size_t _ = 0; _ < __; ++_) {
	    cin >> A >> B; M = 0;
		X = score(0, 1000000000000000ll);
		size_t n = strlen(A);
		for (size_t i = 0; i < n; ++i) {
			if (A[i] == '?')
				P[M++] = A + i;
			if (B[i] == '?')
				P[M++] = B + i;
		}
		if (M == 0)
			X = score(atoll(A), atoll(B));
		else {
			for (char c = '0'; c <= '9'; ++c)
				dfs(0, c);
		}
		cout << "Case #" << (_ + 1) << ": " <<setw(n) << setfill('0') <<X.c << " " <<setw(n) << setfill('0') << X.j << endl;
	}
	return 0;
}
