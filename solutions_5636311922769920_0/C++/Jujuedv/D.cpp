#include <iostream>

using namespace std;

int main()
{
	int T; 
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		long long K, C, S;
		cin >> K >> C >> S;
		if(S * C < K)
			cout << "Case #" << t << ": IMPOSSIBLE\n";
		else
		{
			cout << "Case #" << t << ":";
			int i = 0;
			for(int x = 0; x < S; ++x)
			{
				long long y = 0;
				for(int c = 0; c < C; ++c)
				{
					y *= K;
					y += i;
					i = (i + 1) % K;
					if(i == 0)
						x = S;
				}
				cout << " " << y + 1;
			}
			cout << endl;
		}
	}
}
