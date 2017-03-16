#include <bits/stdc++.h>
using namespace std;

#define endl ('\n')

const int
	MAXN = 1 << 10;

int N;
vector< char > T[MAXN];
string S[MAXN];
int cnt[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; ++test)
	{
		cout << "Case #" << test << ": ";
		
		int A, B, K;
		cin >> A >> B >> K;
		
		int ans = 0;
		for (int a = 0; a < A; ++a)
			for (int b = 0; b < B; ++b)
				if ((a & b) < K)
					ans++;
				
		cout << ans << endl;
	}
	
	return 0;
}