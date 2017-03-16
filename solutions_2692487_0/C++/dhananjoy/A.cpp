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

int N, T;
ll A;
VL v;

int main (int argc, char const* argv[])
{
	cin >> T;

	for (int cs = 1; cs <= T; cs += 1)
	{
		cin >> A >> N;
		v = VL(N);
		for (int i = 0; i < N; i += 1)
			cin >> v[i];
		sort(all(v));
		int cnt = 0, ans = N;
		while (!v.empty() && A > 1)
		{
			ans = min(ans, cnt+sz(v));
			if (A > v.front())
			{
				A += v.front();
				v.pop_front();
			}
			else
			{
				A += (A-1LL);
				cnt++;
			}
		}
		ans = min(ans, cnt+sz(v));
		cout << "Case #" << cs << ": " << ans << '\n';
	}
	
	return 0;
}














