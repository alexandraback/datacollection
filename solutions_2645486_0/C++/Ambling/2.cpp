#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long lint;

int maxgain;
lint E ,R, N;
vector<int> value;

void get(int n, int energy, int gain)
{
	if (n == N)
	{
		return;
	}
	if (energy > E)
	{
		energy = E;
	}
	for (int i = 0; i <= energy; ++i)
	{
		int now = gain + i*value[n];
		if (now > maxgain)
		{
			maxgain = now;
		}
		get(n + 1, energy - i + R, now);
	}
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;

	for (int tt = 0; tt < T; ++tt)
	{
		cin>>E>>R>>N;
		value.clear();
		maxgain = 0;

		for (int i = 0; i < N; ++i)
		{
			int t;
			cin>>t;
			value.push_back(t);
		}

		get(0, E, 0);


		cout<<"Case #"<<tt+1<<": "<<maxgain<<endl;
	}
	return 0;
}