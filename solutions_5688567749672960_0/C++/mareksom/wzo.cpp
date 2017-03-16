#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int odl[1000005];

int rev(int x)
{
	int wyn = 0;
	while(x)
	{
		wyn *= 10;
		wyn += x % 10;
		x /= 10;
	}
	return wyn;
}

int main()
{
	set< pair<int, int> > nic;
	for(int i = 1; i <= N; i++)
	{
		odl[i] = i;
		nic.emplace(i, i);
	}
	auto dorzuc = [&nic] (int w, int o) {
		if(odl[w] > o)
		{
			nic.erase(make_pair(odl[w], w));
			odl[w] = o;
			nic.emplace(odl[w], w);
		}
	};
	while(!nic.empty())
	{
		auto p = *nic.begin();
		nic.erase(nic.begin());
		int w = p.second;
		int o = p.first;

		if(w >= N)
			break;

		dorzuc(w + 1, o + 1);
		dorzuc(rev(w), o + 1);
	}

	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		int x;
		scanf("%d", &x);
		printf("Case #%d: %d\n", i, odl[x]);
	}
	return 0;
}
