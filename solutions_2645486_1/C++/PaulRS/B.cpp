#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int E, R;
vector <int> v;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> E >> R >> N;
		v = vector<int>(N);
		for (int j = 0; j < N; j++)
			cin >> v[j];
		long long acc = E;
		long long ans = 0, ans1 = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
				if ( v[k] > v[j] )
				{
					long long diff = (k - j) * (long long)R;
					long long rem = max(0ll,(long long)E - diff); // can consume up to that remainder
					ans += v[j] * max(0ll,acc - rem);
					if (ans > (1ll << 50))
						ans1 += ans / (1ll << 50), ans %= (1ll << 50);
					acc -= max(0ll,acc - rem);
					goto nxt;
				}
			ans += v[j] * (long long)acc;
			if (ans > (1ll << 50))
				ans1 += ans / (1ll << 50), ans %= (1ll << 50);
			acc = 0;
			nxt:;
			acc = min(acc + R, (long long)E);
		}
		cout << "Case #" << (i+1) << ": ";
		vector <int> d;
		while (ans1 > 0)
			d.push_back(ans1 % 10), ans1 /= 10;
		reverse(d.begin(),d.end());
		for (int i = 0; i < d.size(); i++)
			cout << d[i];
		cout << ans << endl;
	}
	return 0;
}
