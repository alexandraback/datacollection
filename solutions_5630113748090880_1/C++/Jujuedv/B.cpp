#include <iostream>
#include <vector>

using namespace std;

bool operator < (const vector<int> &a, const vector<int> &b)
{
	for(int i = 0; i < a.size(); ++i)
		if(a[i] != b[i])
			return a[i] < b[i];
	return false;
}

int main()
{
	int T; 
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int N;
		cin >> N;
		int cnt[2501] = {};
		for(int i = 0; i < N * (2 * N - 1); ++i)
		{
			int x;
			cin >> x;
			cnt[x] ++;
		}
		int count = 0;
		cout << "Case #" << t << ":";
		for(int i = 0; i <= 2500; ++i)
		{
			if(cnt[i] % 2 == 1)
			{
				count++;
				cout << " " << i;
			}
		}
		cout << endl;
		if(count != N)
			cerr << "exp " << N << " count " << count << endl;
	}
}
