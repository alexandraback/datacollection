#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2500 + 2;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;

#define X first
#define Y second

int cnt[N];;

int main()
{
	ios::sync_with_stdio(false);

	int __;
	cin >> __;
	for (int _ = 0; _ < __; _++)
	{
		cout << "Case #" << _+1 << ": ";
		memset(cnt, 0, sizeof cnt);
		int n;
		cin >> n;
		for (int i=0; i<2*n-1; i++)
			for (int j=0; j<n; j++)
			{
				int x;
				cin >> x;
				cnt[x]++;
			}
		for (int i=0; i<N; i++)
			if (cnt[i] % 2 == 1)
				cout << i << " ";
		cout << "\n";
	}

	return 0;
}
