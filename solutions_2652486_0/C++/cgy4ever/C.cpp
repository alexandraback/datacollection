#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

map <int, bool> have;
int v[11];

void solve()
{
	int R, N, M, K;
	cin >> R >> N >> M >> K;
	cout << endl;

	for(int c = 1; c <= R ; c++)
	{
		have.clear();
		for(int i = 1; i <= K; i++)
		{
			int x;
			cin >> x;
			have[x] += 1;
			v[i] = x;
		}
		int ans1 = 0, ans2 = 0, ans3 = 0;
		int maxOK = 0;
		for(int i = 2; i <= 5; i++)
			for(int j = 2; j <= 5; j++)
				for(int k = 2; k <= 5; k++)
				{
					int ok = 0;
					ok += have[i];
					ok += have[j];
					ok += have[k];
					ok += have[i*j];
					ok += have[i*k];
					ok += have[j*k];
					ok += have[i*j*k];
					for(int u = 1; u <= K; u++)
						if(v[u] % i == 0)
							ok += 10;

					if(ok > maxOK)
					{
						ans1 = i, ans2 = j, ans3 = k;
						maxOK = ok;
					}
				}
		cout << ans1 << ans2 << ans3 << endl;

	}
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cout << "Case #" << CaseID << ": ";
		solve();
	}
	return 0;
}


int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}

