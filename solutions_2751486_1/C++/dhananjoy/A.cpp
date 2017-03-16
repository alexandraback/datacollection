#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAXN 1024*1024
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%M)

typedef long long ll;
typedef deque<int> VI;
typedef deque<VI> VVI;
typedef pair<int,int> PI;
typedef deque<PI> VPI;
typedef deque<VPI> VVPI;
typedef pair<ll,ll> PL;
typedef deque<ll> VL;
typedef deque<VL> VVL;

int T, N, n;
ll A;
string S;
VI x, s;
int prev;

int main (int argc, char const* argv[])
{
	cin >> T;
	
	for (int cs = 1; cs <= T; cs += 1)
	{
		A = 0;
		cin >> S >> n;
		N = sz(S);
		x = VI(N, 1);
		s = VI(N+1,0);
		for (int i = 0; i < N; i += 1)
		{
			if( S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' )
				x[i] = 0;
			s[i+1] = s[i] + x[i];
		}
		prev = 0;
		for (int i = 1; i+n-1 <= N; i += 1)
		{
			if (s[i+n-1]-s[i-1] == n)
			{
				A += ((ll)(i-prev))*((ll)(N-i-n+2));
				prev = i;
			}
		}
		cout << "Case #" << cs << ": " << A << '\n';
	}
	
	return 0;
}














